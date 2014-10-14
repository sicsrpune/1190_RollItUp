/*
 * CBrick.h
 *
 *  Created on: 29-Aug-2014
 *      Author: chaitany
 */

#ifndef CBRICK_H_
#define CBRICK_H_

#include <cocos2d.h>

USING_NS_CC;

class CBrick : public cocos2d::Sprite{
private:

	float _screenHeight;

public:

	float yOffset;
		int State;
		float _speedY;


		void ReachedEndOfScreen(float dt);
		float GenerateRandomColumn();



	CBrick(){}




	static CBrick* generateWithFileName(char *fileName);

	cocos2d::Rect brickCollisonBox();
	void Update(float dt);
	void Start(float dt);
	void Stop();
	void SetSpeedAndHeight(const float speed, const float height);
	void Reset(float column);
	//void Setup(float column);



};


#endif /* CBRICK_H_ */
