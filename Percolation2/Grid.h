#pragma once
#include "Cell.h"

class Grid
{

public:
	static const int SIZE = 40; //Change SIZE to reflect the grid size
	Cell * cell[SIZE][SIZE] = { new Cell };
	int id[SIZE * SIZE];
	bool percolates;

	Grid();
	~Grid();
	void drawGrid();
	void addVacant();
	int getVacantNum();
	double getProportion();
	int find(int i);
	void quickUnion(int p, int q);
	void checkNeighbors(int x, int y);
	bool checkPercolation();
	int getTotalCells();

private:
	int nVacant;
};