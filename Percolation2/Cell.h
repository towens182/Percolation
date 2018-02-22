#pragma once
#include <iostream>

class Cell
{
public:
	Cell();
	~Cell();
	void setVacant();
	bool isVacant();
private:
	bool vacant;
};