#include "Sudoku.h"
#include<iostream>
using namespace std;

void Sudoku::setGrid(vector<vector<int>> gridArray) {
	this->gridArray = gridArray;
}

bool Sudoku::isSafe(vector<vector<int>>& grid, int row, int col, int num) {
	//is num present in row already
	for (int i = 0; i < 9; i++) {
		if (grid[row][i] == num) {
			return false;
		}
	}

	//is num present in col already
	for (int i = 0; i < 9; i++) {
		if (grid[i][col] == num) {
			return false;
		}
	}

	//is num present in 3x3 grid already
	int subgridRow = row - row % 3;
	int subgridCol = col - col % 3;
	for (int i = subgridRow; i < subgridRow + 3; i++) {
		for (int j = subgridCol; j < subgridCol + 3; j++) {
			if (grid[i][j] == num) {
				return false;
			}
		}
	}

	return true; //place num safely
}

bool Sudoku::solveSudoku(vector<vector<int>>& grid) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {

			//is cell empty
			if (grid[row][col] == 0) {

				//place numbers 1-9
				for (int num = 1; num <= 9; num++) {
					if (isSafe(grid, row, col, num)) {
						(grid[row][col] = num); //place num safely

						//recursive solving of remaining grid
						if (solveSudoku(grid)) {
							return true; // if puzzle solved
						}

						//if placing num doesnt lead to solution, backtrack
						grid[row][col] = 0;
					}
				}

				return false; //if no num can be places safely
			}
		}
	}

	return true; //if all cells filled
}

void Sudoku::displayGrid() {
	for (auto& row : gridArray) {
		for (auto& x : row) {
			cout << x << " ";
		}
		cout << endl;
	}
}

void Sudoku::solvePuzzle() {
	if (solveSudoku(gridArray)) {
		cout << "Puzzle solved!" << endl;
	}
	else {
		cout << "No solution for given puzzle." << endl;
	}
}