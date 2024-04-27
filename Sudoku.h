#pragma once
#ifndef SUDOKU_H
#define SUDOKU_H

#include<vector>
#include<iostream>
using namespace std;

class Sudoku {
private:
	vector<vector<int>>gridArray;

public:
	void setGrid(vector<vector<int>> gridArray);
	void displayGrid();
	void solvePuzzle();
	bool solveSudoku(vector<vector<int>>& grid);
	bool isSafe(vector<vector<int>>& grid, int row, int col, int num);
};
#endif // !SUDOKU_H