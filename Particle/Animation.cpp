/*
 * Animation.cpp
 *
 *  Created on: Jun. 18, 2020
 *      Author: user
 */

#include "Animation.h"
#include <stdlib.h>

Animation::Animation() {
	move_x = (2.0 * rand()/RAND_MAX) - 1;
	move_y = (2.0 * rand()/RAND_MAX) - 1;
}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

