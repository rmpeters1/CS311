// counthsw.cpp
// Rose Peters
// Created 2020-09-28
// Updated 2020-10-06
//
// For CS 311 Fall 2020
// Counts all possible holey spider walks on a board.

#include "counthsw.h"

// See header for Docs.
int countHSW(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y)
{
	vector<vector<int>> board(dim_x, vector<int>(dim_y, 0));
	board[hole_x][hole_y] = 1;

	int squaresLeft = dim_x * dim_y - 1;
	int curr_x = start_x;
	int curr_y = start_y;

	return countHSW_recurse(board, dim_x, dim_y, finish_x,
		finish_y, curr_x, curr_y, squaresLeft);
}

// See header for docs.
int countHSW_recurse(vector<vector<int>> board,
	int dim_x, int dim_y,
	int finish_x, int finish_y,
	int curr_x, int curr_y,
	int squaresLeft)
{
	int total = 0;
	
	if (curr_x >= dim_x || curr_x < 0 || curr_y >= dim_y || curr_y < 0) { // Check if current tile is outside index
		return 0;
	}


	if (board[curr_x][curr_y] == 1 // If the current tile is visited already / hole 
		/*&& curr_x != finish_x && curr_y != finish_y*/) {
		return 0;
	}
	board[curr_x][curr_y] = 1;
	squaresLeft--;
	if (squaresLeft > 0 && curr_x == finish_x && curr_y == finish_y) {
		return 0;
	}
	if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y) { // If we have a full solution
		return 1;
	}

	total +=
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x - 1, curr_y, squaresLeft) + // left
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x + 1, curr_y, squaresLeft) + // right
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x, curr_y + 1, squaresLeft) + // up
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x, curr_y - 1, squaresLeft) +// down
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x + 1, curr_y + 1, squaresLeft) + // upright
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x - 1, curr_y + 1, squaresLeft) + // upleft
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x + 1, curr_y - 1, squaresLeft) + // downright
		countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x - 1, curr_y - 1, squaresLeft); // downleft
		
	return total;
}