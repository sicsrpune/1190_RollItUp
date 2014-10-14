/*
 * CBall.h
 *
 *  Created on: 17-Aug-2014
 *      Author: chaitany
 */

#ifndef CBALL_H_
#define CBALL_H_

#include "cocos2d.h"

USING_NS_CC;

class CBall : public cocos2d::Sprite{

private:


	float _currentLane;
	float _screenWidth;
	float _speedX;
	float _currX;
	float _currY;



	void ReachedEndOfScreen();

public:

	unsigned int score;
	unsigned int attempts;

	CBall(){
		attempts = 0;
		score = 0;
	}

	float xOffset;
	int State;

	static CBall *createWithFileName(char *fileName);
	void Update(float dt);
	void Start(float dt);
	void Stop();
	void SetSpeedAndWidth(const float speed, const float width);
	void Reset();
	void Accelerated(cocos2d::Acceleration *accelerated);
	cocos2d::Rect getCollisionBox();
	void MoveUp();
	void MoveDown();

};


#endif /* CBALL_H_ */
