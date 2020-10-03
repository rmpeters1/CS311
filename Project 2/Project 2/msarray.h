// msarray.h
// Rose Peters
// Created: 2020-09-09
// Updated: 2020-09-18
// 
// For CS 311 Fall 2020
// Header for class MSArray
// A RAII class holding dynamic array of a given type.
// There is no associated source file.

#ifndef MSARRAY_H_
#define MSARRAY_H_

#include <cstddef>  // For std::size_t
#include <algorithm>


// class MSArray
// RAII class holding dynamic array of value_type.
// A const MSArray does not allow modification of its array items.
// Invariants:
// Requirements on Types: Valtype must have a valid type
// i.e. string,double, int, etc
template <typename ValType>
class MSArray {

	// ***** MSArray: Types *****
public:
	using size_type = std::size_t;

	using value_type = ValType;


	// ***** MSArray: Ctors, dctor, op= *****
public:

	// Default ctor
	// Set array size to 8.
	MSArray()
		:_arrayPtr(new value_type[8])
	{
		_arraySize = 8;
	}

	// Ctor from size
	// Not an implicit type conversion.
	// Pre:
	//		size >= 0
	explicit MSArray(size_type size)
	: _arrayPtr(new value_type[size]),
		_arraySize(size)

	{}

	// Ctor from size and type
	// Not an implicit type conversion.
	// Pre:
	//		size >= 0, value_type must be valid type
	explicit MSArray(size_type size, value_type val)
		: _arrayPtr(new value_type[size]),
		_arraySize(size)
	{
		for (int i = 0; i < _arraySize; i++) {
			_arrayPtr[i] = val;
		}
	
}

	// Dctor
	~MSArray() {
		delete[] _arrayPtr;
	}

	// Copy ctor
	MSArray(const MSArray& other)
		:_arrayPtr(new value_type[other.size()]),
		_arraySize(other._arraySize)
	{
		std::copy(other.begin(), other.end(), _arrayPtr);
	}

	// Move ctor
	MSArray(MSArray&& other) noexcept
		: _arrayPtr(other._arrayPtr),
		_arraySize(other._arraySize)

	{
		other._arrayPtr = nullptr;
	}

	// Copy op
	MSArray& operator=(const MSArray& other)
	{
		MSArray copy(other);
		mswap(copy);
		return *this;
	}

	// Move op
	MSArray& operator=(MSArray&& other) noexcept {
		mswap(other);
		return *this;
	}

	// ***** MSArray: General public operators *****
public:

	// op[] non-const & const
	// Pre:
	//		0 <= index < arrays' size
	value_type& operator[](size_type index)
	{
		return _arrayPtr[index];
	}

	const value_type& operator[](size_type index) const
	{
		return _arrayPtr[index];
	}

	// op==
	// Pre:		
	//		value_type of lhs = value_type of rhs
	friend bool operator==(const MSArray& lhs, const MSArray& rhs) {
		if (lhs.size() == rhs.size()) {
			for (auto i = 0; i < lhs.size(); i++) {
				if (lhs[i] != rhs[i]) {
					return false;
				}
				
			}
			return true;
		}
		return false;
	}


	// ***** MSArray: General public functions *****
public:

	// size - non-const & const
	// Return size of the current array.
	// Pre:
	//		array size >= 0
	const size_type size() const {
		return _arraySize;
	}

	size_type size() {
		return _arraySize;
	}

	// begin - non-const & const
	// Return pointer to start of array
	// Pre:
	//		array size >= 0
	value_type* begin() {
		return _arrayPtr;
	}

	const value_type* begin() const {
		return _arrayPtr;
	}

	// end - non-const & const
	// Return pointer to end of an array + 1
	// Pre:
	//		array size >= 0

	value_type* end() {
		return _arrayPtr + _arraySize;
	}

	const value_type* end() const {
		return _arrayPtr + _arraySize;

	}

	// swap
	// Calls private mswap function
	// Pre:
	//		array size >= 0
	friend void swap(MSArray& a, MSArray& b) noexcept {
		a.mswap(b);
	}

	// ***** MSArray: Data members *****
private:

	value_type* _arrayPtr; // Pointer to the dynamic array
	size_type _arraySize; // Size of the array

	void mswap(MSArray& other) noexcept { // function to swap pointer values
		std::swap(_arrayPtr, other._arrayPtr);
		std::swap(_arraySize, other._arraySize);
	}


};  // End class MSArray


// *********************************************************************
// class MSArray - Declarations of associated global operators
// *********************************************************************

// op!=
// Requirements on Types: Valtype must have a valid type
template <typename ValType>
bool operator!=(const ValType& lhs, const ValType& rhs) {
	return !(lhs == rhs);
}

//op<=, op>=
// Requirements on Types: Valtype must have a valid type
template <typename ValType>
bool operator<=(const ValType& lhs, const ValType& rhs) {
		return !(rhs < lhs);
}

template <typename ValType>
bool operator>=(const ValType& lhs, const ValType& rhs) {
		return !(lhs < rhs);
}

// op<, op>
// Requirements on Types: Valtype must have a valid type
template <typename Valtype>
bool operator<(const Valtype& lhs, const Valtype& rhs) {
	return std::lexicographical_compare(lhs.begin(),
		lhs.end(), rhs.begin(), rhs.end());
}

template <typename Valtype>
bool operator>(const Valtype& lhs, const Valtype& rhs) {
	return rhs < lhs;
}
#endif // !MSARRAY_H_
