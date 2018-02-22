#include "Grid.h"

Grid::Grid()
{
	this->nVacant = 0;
	this->percolates = false;

	//Set id of each object to itself
	for (int i = 0; i < ((SIZE * SIZE)); i++)
	{
		this->id[i] = i;
	}

	//Initialize all cells in the grid
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			cell[x][y] = new Cell();
}

Grid::~Grid()
{
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			delete cell[x][y];
}

void Grid::drawGrid()
{
	system("cls");
	for (int x = 0; x < SIZE; x++)
	{
		std::cout << "|";
		for (int y = 0; y < SIZE; y++)
		{
			if (cell[x][y]->isVacant() == true)
			{
				std::cout << " |";
			}
			else
			{
				std::cout << (char)254u << "|";
			}
		}
		std::cout << std::endl;
	}
}

void Grid::addVacant()
{
	int a;
	int b;
	bool found = false;

	//Check a random cell, if it is not vacant, make it vacant
	//keep checking until it finds a not vacant cell
	while (!found)
	{
		a = rand() % SIZE;
		b = rand() % SIZE;
		if (cell[a][b]->isVacant() == false)
		{
			cell[a][b]->setVacant();
			found = true;
		}
	}
	this->nVacant++;
	checkNeighbors(a, b); //Union with neighboring cells if possible
}

int Grid::getVacantNum()
{
	return this->nVacant;
}

double Grid::getProportion()
{
	return this->nVacant / (SIZE * SIZE * 1.0);
}

//chase parent pointers until reach root, then return root
int Grid::find(int i)
{
	while (i != id[i])
	{
		i = id[i];
	}
	return i;
}

//change root of p to point to root of q
void Grid::quickUnion(int p, int q)
{
	int i = find(p);
	int j = find(q);
	id[i] = j;
}

//Union vacant cell to neighbors if also vacant
void Grid::checkNeighbors(int x, int y)
{
	int arrayId = ((x * SIZE) + y);

	//check top
	if (x > 0 && (cell[x - 1][y]->isVacant()))
	{
		quickUnion(arrayId, (arrayId - SIZE));
	}

	//check bottom
	if (x < (SIZE - 1) && (cell[x + 1][y]->isVacant()))
	{
		quickUnion((arrayId + SIZE), arrayId);
	}
	
	//Check left
	if (y > 0 && (cell[x][y - 1]->isVacant()))
	{
		quickUnion((arrayId - 1), arrayId);
	}

	//check right
	if (y < (SIZE - 1) && (cell[x][y + 1]->isVacant()))
	{
		quickUnion(arrayId, (arrayId + 1));
	}

}

bool Grid::checkPercolation()
{
	int total = (SIZE * SIZE) - 1;
	for (int w = 0; w < SIZE; w++)
	{
		
		if (find((total - w)) < SIZE)
		{
			return true;
		}
	}
	return false;
}

int Grid::getTotalCells()
{
	return SIZE * SIZE;
}

