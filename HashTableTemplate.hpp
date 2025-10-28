/***********************
Diana Raya Sanchez
October 22nd, 2025
Programming Assignment 3
CPTS 223
************************/

#pragma once

#include "HashTableEntry.hpp"

template <typename Tkey, typename Tvalue> class HashTable
{
private:
	hash_table_entry<Tkey, Tvalue>* table;
	int tableSize;
	int tableLoad;

public:
	//definition of class iterator
	class iterator {
	private:
		HashTable* hTable;
		int currentEntry;

	public:

		//constructor 
		iterator() { currentEntry = -1; hTable = nullptr;  }

		//constructor 
		iterator(HashTable* pTable) { currentEntry = -1; hTable = pTable;  }

		//constructor 
		iterator(HashTable* pTable, int entry) { hTable = pTable; currentEntry = entry; }

		//operator=
		iterator& operator=(const iterator& other)
		{
			if (this == &other) return *this;
			hTable = other.hTable; 
			currentEntry = other.currentEntry;
			return *this;  
		}

		//operator*
		pair<Tkey&, Tvalue&> operator*()
		{
			return { hTable->table[currentEntry].getKey(), hTable->table[currentEntry].getValue() };
		}

		//operator++
		iterator& operator++()
		{
			if (currentEntry >= hTable->tableSize) currentEntry = 0;
			else currentEntry++;
			return *this;
		}


		//operator!=
		bool operator!=(const iterator & other)
		{
			return currentEntry != other.currentEntry;
		}

		//operator==
		bool operator==(const iterator& other)
		{
			return currentEntry == other.currentEntry;
		}

		//destructor
		~iterator() {}

	}; 	//end of definition of class iterator

	//constructor
	HashTable() { table = nullptr; tableSize = 0;  tableLoad = 0;  }

	//constructor
	HashTable(int size)
	{
		table = nullptr;
		tableSize = findNextPrimeNumber(size);
		table = new hash_table_entry<Tkey, Tvalue>[tableSize];
		tableLoad = 0;
	}

	//returns iterator to the first item
	iterator begin() { return iterator(this, 0); }

	//returns iterator to the last item (null)
	iterator end() { return iterator(this); }

	int getSize()
	{
		return tableSize;
	}

	double loadFactor() 
	{ 
		if (tableSize <= 0) return 1.0;
		return (double)tableLoad / (double)tableSize;
	}

	size_t quadraticHashFunction(Tkey key, int attempt)
	{
		hash<Tkey> h;						// Create hash function for type Tkey
		size_t hashValue = h(key);			// Generate hash value
		return ((hashValue + (attempt*attempt)) % tableSize);		
	}

	//deletes all items from table
	void emptyTable()
	{
		hash_table_entry<Tkey, Tvalue> empty_entry;
		for (int i = 0; i < tableSize; i++) table[i] = empty_entry;
	}

	//checks if table is empty
	//returns true if empty and false otherwise
	bool isEmpty()
	{
		if (tableLoad == 0) return true;
		return false;
	}

	//inserts key-value pair
	iterator insert(const Tkey& key, const Tvalue& value)
	{
		// automatic rehash if load factor greater than 0.5
		if (loadFactor() > 0.5) reHash();

		for  (int attempt = 0; attempt<tableSize; attempt++)
		{
			size_t pos = quadraticHashFunction(key, attempt);
			if (table[pos].getStatus() == HASH_ENTRY_EMPTY)
			{
				table[pos].setKey(key);
				table[pos].setValue(value);
				table[pos].setStatus(HASH_ENTRY_OCCUPIED);
				tableLoad++; 
				return iterator(this, pos);
				break;
			}
		} 
		return end();
	}

	//returns an iterator
	iterator find(const Tkey& key)
	{
		for (int attempt = 0; attempt < tableSize; attempt++)
		{
			size_t pos = quadraticHashFunction(key, attempt);
			if (table[pos].getStatus() == HASH_ENTRY_EMPTY) return end();
			if (table[pos].getStatus() == HASH_ENTRY_OCCUPIED)
			{
				if (table[pos].getKey() == key) return iterator(this, pos);
			}
		}
		return end();
	}

	//lazy deletation of key entry
	void remove(const Tkey& key)
	{
		hash_table_entry <Tkey, Tvalue>empty_entry;
		empty_entry.setStatus(HASH_ENTRY_DELETED);

		for (int attempt = 0; attempt < tableSize; attempt++)
		{
			size_t pos = quadraticHashFunction(key, attempt);
			if (table[pos].getStatus() == HASH_ENTRY_EMPTY) return;
			if (table[pos].getStatus() == HASH_ENTRY_OCCUPIED)
			{
				if (table[pos].getKey() == key) table[pos] = empty_entry;
			}
		}
	}

	//destructor 
	~HashTable()
	{
		if (table != nullptr) delete[]table;
		tableSize = 0;
		tableLoad = 0;
		table = nullptr;
	}

private:

	bool isPrime(size_t num)
	{
		if (num % 2 == 0 || num % 3 == 0) return false;
		for (size_t i = 5; i * i <= num; i += 6)
		{
			if (num % i == 0 || num % (i + 2) == 0) return false;
		}
		return true;
	}

	size_t findNextPrimeNumber(size_t num)
	{
		size_t prime = num;
		while (!isPrime(prime)) prime++;
		return prime;
	}

	// resizes the table to next prime of double the current size
	void reHash()
	{
		size_t beforeTableSize = tableSize;
		hash_table_entry<Tkey, Tvalue>* beforeTable = table;

		//duplicates size
		table = nullptr;
		tableSize = findNextPrimeNumber(tableSize * 2);
		table = new hash_table_entry<Tkey, Tvalue>[tableSize];
		tableLoad = 0;

		//for each entry on the table
		for (size_t i = 0; i < beforeTableSize; i++)
		{
			//inserts value on the new table only if pos was occupied
			if (beforeTable[i].getStatus() == HASH_ENTRY_OCCUPIED)
			{
				insert(beforeTable[i].getKey(), beforeTable[i].getValue());
			}

		}

		if (beforeTable!=nullptr) delete[] beforeTable;
	}

};
