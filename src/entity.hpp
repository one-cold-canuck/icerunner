#ifndef CHARACTER_H
#define CHARACTER_H

class Entity
{
	int _row; 				// The Entity's current y position
	int _col; 				// The Entity's current x position
	int _prev_row;			// The Entity's previous y position
	int _prev_col;  		// The Entity's previous x position

	int _color;  			// The Entity's color
	char _symbol;			// The character representation of the Entity

	bool _is_transparent; 	// TRUE if the entity can be seen through, FALSE otherwise.  Default FALSE
	bool _has_collision;  	// FALSE if Entity is passable, TRUE otherwise.  Default TRUE
	bool _is_actor; 		// TRUE if this entity can perform actions, FALSE otherwise
	bool _is_pickup;		// TRUE if the entity can be picked up, false otherwise

public:
	// Create a character
	Entity(char symbol, int row_0, int col_0);
	
	// Set the character's position
	void pos(int row_0, int col_0);

	// Get the character's row (y)
	int row();

	// Get the character's col (x)
	int col();

	// Get the character's symbol
	char symbol();

	// Get the character's color
	int color();

	void setColor(int c);
};

#endif
