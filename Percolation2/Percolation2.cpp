//Percolation Program by Tyler Owens
//Will ouput the proportion of vacant cells to the total cells in grid.
//Maximize console output to see entire results.
#pragma once
#include "Cell.h"
#include "Grid.h"
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	Grid * grid = new Grid();

	while (grid->checkPercolation() == false) //Keep adding vacant cell until grid percolates
	{
		//grid->drawGrid(); //Uncomment to visually see the grid in action
		grid->addVacant();
	}
	grid->drawGrid();
	cout << "Number of Vacant = " << grid->getVacantNum() << endl;
	cout << "Number of Cells = " << grid->getTotalCells() << endl;
	cout << "p = " << grid->getProportion();

	delete grid;
	cin.get();

	return 0;
}