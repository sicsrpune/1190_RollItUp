/*
 * CBall.cpp
 *
 *  Created on: 17-Aug-2014
 *      Author: chaitany
 */

#include "CBall.h"
#include "constants.h"
#include "CGameManager.h"

USING_NS_CC;

int temp = 0;

CBall* CBall::createWithFileName(char *fileName)
{
auto sprite_ball = new CBall;
	if(sprite_ball && sprite_ball->initWithFile(fileName))
	{
		sprite_ball->autorelease();
		return sprite_ball;
	}
CC_SAFE_DELETE(sprite_ball);
return nullptr;
}

void CBall::Update(float dt){

if(this->attempts > AllowedAttempts-1)
	HelloWorld::game_over_flag = true;

this->Start(dt);
//auto action = RotateBy::create(dt,10);
//this->runAction(action);
}


void CBall::Start(float dt){


	/*float currentX = getPositionX();
	float distance =  currentX + xOffset;
	float time = distance*4 / _speedX;



	Vec2 destination = Vec2(distance,this->getPositionY());
	auto actionMove =  MoveTo::create(time,destination);
	this->runAction(actionMove);

*/
float offset = _speedX * dt;
float currentX = getPositionX();
this->setPositionX(currentX+offset);

	if(currentX > _screenWidth+100)
	{
		ReachedEndOfScreen();
	}



}


void CBall::Stop()
{
		this->stopAllActions();
		_speedX = rBallStartSpeedX;

}

void CBall::SetSpeedAndWidth(const float speed, const float width){
	_speedX =  speed;
	_screenWidth = width;
	xOffset = this->getBoundingBox().size.width;
}

void CBall::ReachedEndOfScreen(){
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_speedX = _speedX + 100;
	this->setPosition(Vec2(origin.x-20,this->getPositionY()));

	this->score += ScoreReward;
	return;
}

void CBall::Reset()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
		 Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->stopAllActions();
	this->setPosition(Vec2(origin.x-100,visibleSize.height * (6.0/7.0)));
}

void CBall::Accelerated(cocos2d::Acceleration *accelerated)
{

/*

	if(accelerated->y > 0.0)
	{
		this->MoveUp();
	}
	else if(accelerated->y < 0.0)
	{
		this->MoveDown();
	}


CCLOG("x = %f || y = %f || z = %f \n",accelerated->x,accelerated->y,accelerated->z);
*/
//this->setPositionY(this->getPositionY() + accelerated->y);


}

cocos2d::Rect CBall::getCollisionBox()
{
	return this->getBoundingBox();
}

void CBall::MoveUp()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if(this->getPositionY() > visibleSize.height * (6.0/7.0))
	{
		this->setPositionY(visibleSize.height * (1.0/7.0));
	}
	else
	{
	this->setPositionY(this->getPositionY() + (visibleSize.height * (1.0/7.0)) );
	}
}

void CBall::MoveDown()
{
Size visibleSize = Director::getInstance()->getVisibleSize();

if(this->getPositionY() < visibleSize.height * (1.0/7.0))
{
	this->setPositionY(visibleSize.height * (6.0/7.0));
}
else
{
	this->setPositionY(this->getPositionY() - (visibleSize.height * (1.0/7.0)) );

}

}


/*
	void CBall::Reset(){
		State = rBallStateStopped;
		_speedX = rBallStartSpeedX;

		Size visibleSize = Director::getInstance()->getVisibleSize();
		 Vec2 origin = Director::getInstance()->getVisibleOrigin();

		 this->setPosition(Vec2(origin.x+visibleSize.width*0.1,visibleSize.height /2));


	}
	void CBall::Accelerate(){
		_speedX = _speedX*2.0;

	}
	void CBall::Decelerate(){
		_speedX = _speedX/2.0;
	}
*/





