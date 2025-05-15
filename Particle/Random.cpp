/*
 * Random.cpp
 *
 *  Created on: Jun. 18, 2020
 *      Author: user
 */

#include "Random.h"

Random::Random() {
	pAnimation = new Animation[N];

}

Random::~Random() {
	delete [] pAnimation; //deallocate memory
}

