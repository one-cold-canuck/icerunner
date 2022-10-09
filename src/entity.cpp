
#include "entity.hpp"

// Create a character

Entity::Entity(char symbol, int row_0, int col_0)
{
	_symbol = symbol;  // The on-screen representation of the Entity
	_row = row_0; // The Entity's current row position
	_col = col_0; // The Entity's current column position
	
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

int Entity::color()
{
	return _color;
}

void Entity::setColor(int c) {
	_color = c;
}
