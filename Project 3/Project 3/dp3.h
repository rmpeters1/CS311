// dp3.h
// Rose Peters
// Created: 2020-09-19
// Updated: 2020-09-26
//
// For CS 311 Fall 2020
// Header for dp3.cpp

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept> // for std::out_of_range
#include <iostream> // for std::cerr
#include <exception> // for std::exception

// lookup
// Uses a given index to check if it is in range
// otherwise throws an exception
// Requirements on types: 
//						ValueType must be a valid type.
//						index > 0 && index <= _data size
template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head,
	std::size_t index)
{
	auto amnt = 0;
	const LLNode<ValueType>* p = head;
	while (p != NULL)
	{
		++amnt;
		p = p->_next;
	}
	if (head == nullptr || index > amnt || index < 0) {
		throw std::out_of_range("The index is out of range.");
	}
	else {
		const LLNode<ValueType>* temp = head;
		int count = 0;
		while (temp != NULL) {
			if (count == index)
			{
				return(temp->_data);
			}
			count++;
			temp = temp->_next;

		}
	}

}


// didItThrow
// Throws exception if ff is called without needed parameters/type
// and sets threw to true
// Implementation in source file
void didItThrow(const std::function<void()>& ff,
	bool& threw);




// FDIter
// Checks whether everything between the iterators is sorted or not
// Throws an exception if first = last
// Requirements on type:
//						first => 0 && last > first					
template <typename FDIter>
bool checkSorted(FDIter first,
	FDIter last)
{
	bool sorted;

	try {
		first = last;
		sorted = true;

	}
	catch (std::exception & e) {
		std::cerr << "Index out of range" << e.what();
	}

	while (first != last) {

		if (*first < *++first) {
			sorted = true;
		}

		else if (*++first < *first) {
			sorted = false;
		}
		++first;

	}
	
	return sorted;
}

// gcd
// Calculates gcd by calling itself recursively
// Implementation in source file
int gcd(int a,
	int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

