// dp6.h
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-10-30
// Updated: 2020-10-30

// For CS 311 Fall 2020
// Header for Project 6 functions


// CREDIT:
//
//
//

#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"	
#include <memory>		// for std::unique_ptr
#include <functional>	// for std::function
#include <cstddef>		// for std::size_t

// reverseList
// Efficient reversing function for a Linked List of LLNode2
// Pre:
//	Valid LLNode2 unique pointer
// ??? Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head)
{
	std::unique_ptr<LLNode2<ValType>> newHead(nullptr);
	std::unique_ptr<LLNode2<ValType>> currentHead(nullptr);

	while (head != nullptr)
	{
		currentHead = std::move(head->_next);
		head->_next = std::move(newHead);
		newHead = std::move(head);
		head = std::move(currentHead);
	}

	head = std::move(newHead);
}

// **********************************************************************
// class LLMap - Class definition
// **********************************************************************
// class LLMap
// Templated linked list map
// Invariants:
//		???
// Type requirements:
//		???
template <typename Key, typename Data>
class LLMap {

	// ***** LLMap: Types *****
public:
	// key_type: type of key items
	using key_type = Key;
	// data_type: type of data items
	using data_type = Data;

	// ***** LLMap: Constructors, Destructors *****
public:
	// Default constructor
	// Creates an empty data set
	// Strong Guarantee
	LLMap() : _head(nullptr)
	{}

	// Default destructor
	// No Throw Guarantee
	~LLMap()
	{}

	// Big 5: 
	// LLMap must not have any other public member functions
	// Copy ctor, move ctor, copy assignment op, and move assignment op deleted
	LLMap(const LLMap& other) = delete;
	LLMap(LLMap&& other) = delete;
	LLMap& operator=(const LLMap& other) = delete;
	LLMap& operator=(const LLMap&& other) = delete;

	// ***** LLMap: Public Member Functions *****
public:
	// size
	// Returns an integer of appropriate type 
	// giving the number of key-value pairs in LLMap
	// Strong Guarantee
	size_t size() const
	{
		auto it = _head.get();
		std::size_t i = 0;
		while (it)
		{
			it = it->_next.get();
			++i;
		}
		return i;
	}

	// empty
	// Returns a bool indicating if there are no key-balue pairs in LLMap
	// No-Throw Guarantee
	bool empty() const
	{
		if (_head == nullptr)
		{
			return true;
		}
		return false;
	}

	// find
	// Returns a const pointer to value of the key given if the 
	// key is in LLMap, otherwise returns nullptr
	// Pre:
	//		
	// No-Throw Guarantee
	data_type* find(const key_type& key)
	{
		auto it = _head.get();
		while (it)
		{
			if (it->_data.first == key)
			{
				return &(it->_data.second);
			}
			it = it->_next.get();
		}
		return nullptr;
	}

	const data_type* find(const key_type& key) const
	{
		auto it = _head.get();
		while (it)
		{
			if (it->_data.first == key)
			{
				return &(it->_data.second);
			}
			it = it->_next.get();
		}
		return nullptr;
	}
	// insert
	// If the key does not lie in LLMap then the key-value pair is inserted
	// If key already lies in LLMap, overwrite with given key-value pair
	// Pre:
	//		
	// Basic Guarantee
	void insert(key_type key, data_type data)
	{
		auto it = find(key);
		if (it)
		{
			*it = data;
			return;
		}
		push_front(_head, std::make_pair(key, data));
	}

	// erase
	// If key is found then erase the key-value pair
	// If key isn't found do nothing
	// Pre:
	//		
	// Basic Guarantee
	void erase(key_type key)
	{
		auto it = _head.get();
		auto it2 = _head.get();
		while (it) {
			if (it->_data.first == key) {
				std::swap(it2->_next, it->_next);
				it->_next = nullptr;
				it = nullptr;
			}
			else {
				it2 = it;
				it = it->_next.get();
			}
		}
	}

	// traverse
	// Applies a function to every object in LLMap
	// Pre:
	//		
	// Basic Guarantee
	void traverse(std::function<void(key_type, data_type)> func) const
	{
		auto it = _head.get();
		while (it)
		{
			func(it->_data.first, it->_data.second);
			it = it->_next.get();
		}
	}

	// ***** LLMap: Data Members *****
private:
	std::unique_ptr<LLNode2<std::pair<key_type, data_type>>> _head;

}; // End class LLMap

#endif // FILE_DP6_H_INCLUDED
