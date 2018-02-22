#include "Cell.h"

Cell::Cell()
{
	this->vacant = false;
}

Cell::~Cell()
{
}


void Cell::setVacant()
{
	this->vacant = true;
}

bool Cell::isVacant()
{
	return this->vacant;
}
