// counthsw.h
// Rose Peters
// Created 2020-09-28
// Updated 2020-10-06
//
// For CS 311 Project 4
// Header for counthsw.cpp

#ifndef CountHSW_H_
#define CountHSW_H

#include <vector>
using std::vector;


// countHSW
// Return a recursive function to count possible paths
// for holey spider walk problem.
// Pre:
//		0 <= hole_x < dim_x, 0 <= hole_y < dim_y	
//		0 <= start_x < dim_x, 0 <= start_y < dim_y
//		0 <= finish_x < dim_x, 0 <= finish_y < dim_y
//		0 < dim_x, 0 < dim_y
int countHSW(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y);

// countHSW_recurse
// Given a partial solution, return all possible paths
// for holey spider walks.
// 
// Pre: 
//		0 < board.size()
//		0 <= curr_x < dim_x, 0 <= curr_y < dim_y
//		0 <= finish_x < dim_x, 0 <= finish_y < dim_y
//		0 < dim_x, 0 < dim_y
//		0 < squaresLeft
int countHSW_recurse(vector<vector<int>> board, int dim_x, int dim_y, int finish_x,
	int finish_y, int curr_x, int curr_y, int squaresLeft);


#endif // !CountHSW_H_

