
#include "character.h"

// Create a character

Character::Character(char symbol, int row_0, int col_0)
{
	_symbol = symbol;
	_row = row_0;
	_col = col_0;
}

// Change a character's position
void Character::pos(int row_0, int col_0)
{
	_row = row_0;
	_col = col_0;
}

// Get the character's current row (y)
int Character::row()
{
	return _row;
}

int Character::col()
{
	return _col;
}

char Character::symbol()
{
	return _symbol;
}


