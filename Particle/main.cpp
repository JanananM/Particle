#include <iostream>
#include <SDL.h>
//local
#include "DrawScreen.h"
#include <stdlib.h>
#include <time.h>
#include "Random.h"
using namespace std;

int main(){

	srand(time(NULL));


	DrawScreen display;

	if(display.init() == false){
		cout << "Error intitalization" << endl;
		return 1;
	}
	cout << "successful0" << endl;

	Random r;

	//game loop


	while(true){

		int i;

		cout << "successful1" << endl;
		//draw particles

		const Animation * const pBubbles = r.getBubbles();

		for(i=0;i<Random::N;i++){
			Animation animation = pBubbles[i];

			//mapping bubbles space to screen space
			int x = (animation.move_x + 1)* DrawScreen::WINDOWWIDTH/2;
			int y = (animation.move_y + 1)* DrawScreen::WINDOWHEIGHT/2;
			cout << "successfulset" << endl;
			display.setPixel(x,y,128,0,255);
			cout << "successfulset1" << endl;
		}

		/*for(int y =0; DrawScreen::WINDOWHEIGHT;y++){
			for(int x= 0; x< DrawScreen::WINDOWWIDTH;x++){
				display.setPixel(x,y,128,0,255);
			}
		}*/

		//update particles
		cout << "successfulset" << endl;
		display.update();
		cout << "successful3" << endl;

		//check for quit event

		if (display.eventProcess() == false){
			cout << "Error Event" << endl;
			break;
		}
	}

	cout << "successful4" << endl;
	display.deallocate();


	return 0;
}
