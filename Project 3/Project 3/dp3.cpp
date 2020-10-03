// dp3.cpp 
// Rose Peters
// Created 2020-09-19
// Updated 2020-09-26
//
// For CS 311 Fall 2020
// Source for dp3.h functions

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

// didItThrow
// See header for documentation.
void didItThrow(const function<void()>& ff,
	bool& threw)
{
	try {
		ff();
	}
	catch (...) {
		threw = true;
		
	}
	ff();
	
}

// gcd
// See header for documentation.
int gcd(int a,
	int b)
{
	if (a < 0 || b < 0) {
		return 0;
	}
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}

	int dummy = a;

	if (a == 0) {
		return 1;
	}

	a = b % dummy;
	b = dummy;
	dummy = a;

	if (a == 0) {
		return b;
	}
	gcd(a, b);

}

