/*
 * Random.h
 *
 *  Created on: Jun. 18, 2020
 *      Author: user
 */

#include "Animation.h"

#ifndef RANDOM_H_
#define RANDOM_H_

class Random {
private:
	Animation * pAnimation;
public:
	const static int N = 1000;
	Random();
	~Random();

	Animation *getBubbles(){ return pAnimation;};
};

#endif /* RANDOM_H_ */
