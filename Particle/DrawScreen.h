/*
 * DrawScreen.h
 *
 *  Created on: Jun. 17, 2020
 *      Author: user
 */

#ifndef DRAWSCREEN_H_
#define DRAWSCREEN_H_

#include <iostream>
#include <SDL.h>



class DrawScreen {
private:
	SDL_Window *window;
	SDL_Renderer *ren;
	SDL_Texture *text;
	Uint32 *buffer;

public:
	const static int WINDOWHEIGHT = 600;
	const static int WINDOWWIDTH = 800;
	DrawScreen();
	~DrawScreen();
	bool init();
	void deallocate();
	bool eventProcess();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
};


#endif /* DRAWSCREEN_H_ */
