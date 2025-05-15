/*
 * DrawScreen.cpp
 *
 *  Created on: Jun. 17, 2020
 *      Author: user
 */
#include <iostream>
#include "DrawScreen.h"


DrawScreen::DrawScreen() {
	window = NULL;
	ren = NULL;
	text = NULL;
	buffer = NULL;
}

DrawScreen::~DrawScreen() {
	// TODO Auto-generated destructor stub
}


bool DrawScreen::init(){
	//initializing system check
		if(SDL_Init(SDL_INIT_VIDEO)<0){
			return false;
		}

		window = SDL_CreateWindow("Particles",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOWWIDTH, WINDOWHEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL){
			SDL_Quit();
			return false;
		}
		//cout << "successful" << endl;

		//renderer sync with screen refresh
		ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
		//creates texture for render: points to text
		text = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,WINDOWWIDTH,WINDOWHEIGHT);

		if(ren == NULL){
			//out << "RENDER FAILED" << endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}

		if(text == NULL){
			//cout << "TEXTURE FAILED" << endl;
			SDL_DestroyRenderer(ren);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}


		//allocate memory for pixels: info used to update texture
		buffer = new Uint32[WINDOWHEIGHT * WINDOWWIDTH];


		//fill block of memory
		memset(buffer, 0, WINDOWWIDTH*WINDOWHEIGHT*sizeof(Uint32));



		//buffer[20000] = 0xFFFFFFFF;



		return true;
}



bool DrawScreen::eventProcess(){
	SDL_Event event;
	//loop until poll event is false,loop through all waiting events
	while (SDL_PollEvent(&event)){
		//access the type member
		if(event.type == SDL_QUIT){
			return false;
		}
	}
	return true;
}

void DrawScreen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

	//check to see if plotting pixels are not off the screen
	if(x < 0 || x >= WINDOWWIDTH || y < 0 || y >= WINDOWHEIGHT){
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<= 8; //set color and shift 1 byte to left
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	//cout << color << endl;

	buffer[(y * WINDOWWIDTH) + x] = color; // to control/set the pixel at each location

}

void DrawScreen::update(){
	//updating draw
	SDL_UpdateTexture(text, NULL, buffer, WINDOWWIDTH * sizeof(Uint32));
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren,text,NULL,NULL);
	SDL_RenderPresent(ren);//renders to window
}

void DrawScreen::deallocate(){
	delete [] buffer;
	SDL_DestroyRenderer(ren);
	SDL_DestroyTexture(text);
	//if window is created, these commands and exit and deallocate memory
	SDL_DestroyWindow(window);
	SDL_Quit();
}

