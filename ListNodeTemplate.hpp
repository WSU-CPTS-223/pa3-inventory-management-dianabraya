/***********************
Diana Raya Sanchez
September 8th, 2025
Programming Assignment 1
CPTS 223
************************/

#pragma once

template <typename T> class ListNode
{
private:
	T data;
	ListNode* pNext;

public:
	//constructor -- initializes attributes of the class
	ListNode() { pNext = nullptr; }

	ListNode(T& values) { data = values; pNext = nullptr; }

	//getters
	T& getData() { return data; }
	ListNode* getNext() { return pNext; }

	//setters
	void setData(T& value) { data = value; }
	void setNext(ListNode* next) { pNext = next; }

	//destructor
	~ListNode() {}
};
