#ifndef CHARACTER_H
#define CHARACTER_H
class Character
{
	int _row, _col;
	char _symbol;

public:
	// Create a character
	Character(char symbol, int row_0, int col_0);

	// Set the character's position
	void pos(int row_0, int col_0);

	// Get the character's row (y)
	int row();

	// Get the character's col (x)
	int col();

	// Get the character's symbol
	char symbol();
};

#endif
