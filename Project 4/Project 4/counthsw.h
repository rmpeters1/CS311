// counthsw.h
// Rose Peters
// For CS 311 Project 4
// Created 2020-09-28

#ifndef CountHSW_H_
#define CountHSW_H

#include <vector>
using std::vector;



int countHSW(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y);

int countHSW_recurse(vector<vector<int>> board, int dim_x, int dim_y, int finish_x,
	int finish_y, int curr_x, int curr_y, int squaresLeft);


#endif // !CountHSW_H_

