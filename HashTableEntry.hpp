/***********************
Diana Raya Sanchez
October 22nd, 2025
Programming Assignment 3
CPTS 223
************************/

#pragma once

#define HASH_ENTRY_EMPTY    0
#define HASH_ENTRY_DELETED  1
#define HASH_ENTRY_OCCUPIED 2

template <typename Tkey, typename Tvalue> class hash_table_entry
{
private:
	Tkey key;
	Tvalue value;
	char status;
	
public:
	//constructor -- initializes attributes of the class
	hash_table_entry() { status = HASH_ENTRY_EMPTY;  }

	//constructor 
	hash_table_entry(const Tkey& nKey, const Tvalue& nValue)
	{
		key = nKey;
		value = nValue;
		status = HASH_ENTRY_OCCUPIED;
	}

	//constructor 
	hash_table_entry(const hash_table_entry& other)
	{
		key = other.key; 
		value = other.value; 
		status = other.status;
	}
	
	//operator=
	hash_table_entry& operator=(const hash_table_entry& other)
	{
		if (this == &other) return *this;
		key = other.key;
		value = other.value;
		status = other.status;
		return *this;
	}

	//getters
	Tkey& getKey() { return key; }
	Tvalue& getValue() { return value; }
	char& getStatus() { return status; }
	
	//setters
	void setKey(const Tkey& nKey) { key = nKey; }
	void setValue(const Tvalue& nValue) { value = nValue; }
	void setStatus(const int& nStatus) { status = nStatus; }
	
	//destructor
	~hash_table_entry() {}
};
