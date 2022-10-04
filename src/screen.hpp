#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "frame.hpp"

class Screen {

	int _height, _width; 	//The screen's height and width
	WINDOW * _stdscr;	 	//Pointer to the screen created by a call to initscr()
	Frame * _game_map;	 	//Pointer to the game map draw frame
	Frame * _viewport; 	 	//Pointer to the play area viewport
	Frame * _message_block; //Pointer to the message viewport
	Frame * _stat_window;	//Pointer to the status viewport, 
	Frame * _popup_box;		//Pointer to a popup box frame
	
	
public:
	// Initialize the ncurses library
	Screen();

	// Clear ncurses
	~Screen();

	// Print a message on the screen
	void add(const char* message);

	// Get the screen height
	int height();

	// Get the screen width
	int width();

	// Initialize color pairs
	void initColor();

	void colorTest();

	WINDOW* getStdScr();

	void set_game_map(Frame* game_map);
	void set_viewport(Frame* viewport);
	void set_message_box(Frame* message_box);
	void stat_window(Frame* stat_window);
	void popup_box(Frame* popup_box);

	Frame* game_map();
	Frame* message_box();
	Frame* stat_window();
	Frame* popup_box();

};

#endif
