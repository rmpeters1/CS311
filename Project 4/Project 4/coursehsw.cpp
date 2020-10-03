#include "counthsw.h"

int countHSW(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y)
{
	vector<vector<int>> board(dim_x, vector<int>(dim_y, 0));
	board[hole_x][hole_y] = 1;
	board[start_x][start_y] = 1;

	int squaresLeft = dim_x * dim_y - 2; //this is a partial solution
	int curr_x = start_x;
	int curr_y = start_y;
	if (start_x == finish_x && start_y == finish_y) {
		squaresLeft = 0;
	}

	return countHSW_recurse(board, dim_x, dim_y, finish_x,
		finish_y, curr_x, curr_y, squaresLeft);
}


int countHSW_recurse(vector<vector<int>> board,
	int dim_x, int dim_y,
	int finish_x, int finish_y,
	int curr_x, int curr_y,
	int squaresLeft)
{
	int total = 0;
	bool outOfBounds = false;
	if (curr_x > dim_x || curr_x < 0 || curr_y > dim_y || curr_y < 0) { // Check if current tile is outside index
		outOfBounds = true;
	}
	if (outOfBounds == true) { // If the current tile is outside the board
		return 0;
	}
	if (board[curr_x][curr_y] == 1 && (curr_x != finish_x && curr_y != finish_y)) { // If the current tile is a hole
		return 0;
	}
	if (board[curr_x][curr_y] == 0) { // Set current tile to visited
		board[curr_x][curr_y] = 1;
		squaresLeft--;
	}
	if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y) {// If we start with a full solution
		return 1;
	}

	for (int newrow = 0; newrow < dim_y; newrow++) {
		for (int newcol = 0; newcol < dim_x; newcol++) {
			if (board[newcol][newrow] == 1)
				return 1;
		}
	}



	
	for (int newrow = 0; newrow < dim_y; newrow++) {
		for (int newcol = 0; newcol < dim_x; newcol++) {
			
				total += 
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x-1, curr_y, squaresLeft) + // left
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x+1, curr_y, squaresLeft) + // right
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x, curr_y+1, squaresLeft) + // up
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x, curr_y-1, squaresLeft) + // down
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x+1, curr_y+1, squaresLeft) + // upright
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x-1, curr_y+1, squaresLeft) + // upleft
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x+1, curr_y-1, squaresLeft) + // downright
					countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, curr_x-1, curr_y-1, squaresLeft); // downleft
			}
	}
	return total;
}