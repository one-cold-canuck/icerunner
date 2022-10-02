
#include "entity.h"

// Create a character

Entity::Entity(char symbol, int row_0, int col_0)
{
	_symbol = symbol;
	_row = row_0;
	_col = col_0;
}

// Change a character's position
void Entity::pos(int row_0, int col_0)
{
	_row = row_0;
	_col = col_0;
}

// Get the character's current row (y)
int Entity::row()
{
	return _row;
}

int Entity::col()
{
	return _col;
}

char Entity::symbol()
{
	return _symbol;
}


