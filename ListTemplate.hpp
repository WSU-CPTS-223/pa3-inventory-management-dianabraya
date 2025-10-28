/***********************
Diana Raya Sanchez
September 8th, 2025
Programming Assignment 1
CPTS 223
************************/

#pragma once

#include "ListNodeTemplate.hpp"

template <typename T> class List
{
private:
	ListNode<T>* pHead;    
	ListNode<T>* pTail;
	int lengthOfList;

public:
	class iterator {
	private:
		ListNode<T>* currentNode; 

	public:
		//constructor
		iterator() { currentNode = nullptr; }

		//constructor 
		iterator(ListNode<T>* newNode) { currentNode = newNode; }

		//operator*
		T& operator*() { return currentNode->getData(); } 

		//operator++
		iterator& operator++() 
		{
			currentNode = currentNode->getNext();
			return *this;
		}

		//operator!=
		bool operator!=(const iterator& other)  
		{
			return currentNode != other.currentNode;
		}

		//destructor
		~iterator() {}
	};

	//constructor
	List() 
	{ 
		pHead = nullptr;
		pTail = nullptr;
		lengthOfList = 0;
	}

	//constructor 
	List(const List<T>& other)
	{
		pHead = nullptr;
		pTail = nullptr;
		lengthOfList = 0;
		for (auto it = other.begin(); it != other.end(); ++it) addNodeBack(*it);
	}

	//operator=
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other) return *this;
		emptyList();
		pHead = nullptr;
		pTail = nullptr;
		lengthOfList = 0;
		ListNode<T>* ptr = nullptr;
		for (ptr = other.pHead; ptr != nullptr; ptr = ptr->getNext()) addNodeBack(ptr->getData());
		return *this;
	}

	//returns iterator to the first item
	iterator begin() { return iterator(pHead); }

	//returns iterator to the last item (null)
	iterator end() { return iterator(nullptr); }

	//deletes all nodes from list
	void emptyList() 
	{
		ListNode<T>* ptr = nullptr;
		ListNode<T>* ptrNext = nullptr;
		for (ptr = pHead; ptr != nullptr; ptr = ptrNext)
		{
			ptrNext = ptr->getNext();
			delete ptr;
		}
		pHead = nullptr;
		pTail = nullptr;
		lengthOfList = 0; 
	}

	//deletes one node from list
	void removeNode(T& data)
	{
		ListNode<T>* ptr = pHead; 
		ListNode<T>* ptrPrev = nullptr;

		for (ptr = pHead; ptr != nullptr; ptr = ptr->getNext())
		{
			if (ptr->getData() == data)
			{
				if (ptrPrev == nullptr) pHead = ptr->getNext();
				else ptrPrev->setNext(ptr->getNext());
				if (ptrPrev->getNext() == nullptr) pTail = ptrPrev;
				delete ptr;
				lengthOfList--; 
				return;
			} 
			ptrPrev = ptr;
		}
	}

	//checks if list is empty
	//returns true if empty and false otherwise
	bool isEmpty()
	{
		if (pHead == nullptr) return true;
		else return false; 
	}

	//adds node at the back of the list
	void addNodeBack(T& value) 
	{
		ListNode<T>* newNode = new ListNode<T>(value);   
		if (pHead == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else {
			//ListNode<T>* ptr = nullptr;
			//for (ptr = pHead; ptr->getNext() != nullptr; ptr = ptr->getNext());
			pTail->setNext(newNode);
			pTail = newNode;
		}
		lengthOfList++;
	}

	//adds node to the front of the list
	void addNodeFront(T& value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);
		if(pHead == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else {
			newNode->setNext(pHead); 
			pHead = newNode; 
		}
		lengthOfList++;
	}

	//returns value(s) in the node of the position given
	// assumes position exists on the list
	//returns the data in reference
	T& findValues(int position)
	{
		ListNode<T>* ptr = pHead;
		for (int i = 0; i < position && ptr != nullptr; i++)
		{
			ptr = ptr->getNext();
		}
		//if (ptr == nullptr) return nullptr;
		return ptr->getData();
	}

	//searches list for a certain data value 
	//returns a pointer to data if found, otherwise null
	T* findValues(T& data)
	{
		ListNode<T>* ptr = pHead;    
		for (ptr = pHead; ptr != nullptr; ptr = ptr->getNext())
		{
			if (ptr->getData() == data) return &(ptr->getData());
		}
		return nullptr;
	}

	//keeps track of list length
	int listLength()
	{	
		return lengthOfList; 
	}
 

	//destructor 
	~List()
	{
		emptyList(); 
	}

};
