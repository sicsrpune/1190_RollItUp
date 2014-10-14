/*
 * CBrick.cpp
 *
 *  Created on: 29-Aug-2014
 *      Author: chaitany
 */

#include "CBrick.h"
#include "constants.h"
#include "CGameManager.h"
#include "HelloWorldScene.h"


USING_NS_CC;

	cocos2d::Rect CBrick::brickCollisonBox()
	{
			return this->getBoundingBox();
	}

	CBrick* CBrick::generateWithFileName(char *fileName)
	{
	auto sprite_brick = new CBrick;
		if(sprite_brick && sprite_brick->initWithFile(fileName))
		{
			sprite_brick->autorelease();
			return sprite_brick;
		}

			CC_SAFE_DELETE(sprite_brick);
			return nullptr;

	}

	void CBrick::Update(float dt){

		this->Start(dt);
	}

	void CBrick::Start(float dt){

/*

		float currentY = getPositionY();
		float distance =  currentY + yOffset;
		float time = distance*10 / _speedY;

this->State = sBricksStateMoving;
this->setVisible(true);
		Vec2 destination = Vec2(this->getPositionX(),distance);
		auto actionMove =  MoveTo::create(time,destination);
		this->runAction(actionMove);
*/

		float offset = _speedY * dt;
		float currentY = getPositionY();
		this->setPositionY(currentY+offset);


		if(currentY > _screenHeight+120)
		{
			ReachedEndOfScreen(dt);
		}


	}
//
//	void CBrick::Stop()
//	{
//		this->State = sBricksStateStopped;
//		this->stopAllActions();
//		this->Reset();
//		//Scored=false;
//	}

	void CBrick::SetSpeedAndHeight(const float speed, const float height){
		_speedY =  speed;
		_screenHeight = height;
		yOffset = this->getBoundingBox().size.width;
		this->State = sBricksStateStopped;
		//Scored = false;
	}

	void CBrick::ReachedEndOfScreen(float dt){

		float col = GenerateRandomColumn();
		this->Reset(col);


		//return;
	}

	void CBrick::Reset(float column)
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
			 Vec2 origin = Director::getInstance()->getVisibleOrigin();
		//this->setPosition(Vec2(this->getPositionX(),origin.y));
		float random_y_pos;
	//	random_y_pos = static_cast <float>(rand())/(static_cast <float> (RAND_MAX/(6.0/7.0)));
		random_y_pos = static_cast <float>(rand())/(static_cast <float> (RAND_MAX));
	//	CCLog("\n==%f==\n",random_y_pos);
//		this->setPosition(Vec2(this->getPositionX(),visibleSize.height*random_y_pos-350));
		//this->setPosition(Vec2(this->getPositionX(),-visibleSize.height*random_y_pos));


		this->setPosition(Vec2(visibleSize.width * (column/HelloWorld::number_of_columns),-visibleSize.height*random_y_pos));
	}

//	void CBrick::Setup(float column)
//	{
//		Size visibleSize = Director::getInstance()->getVisibleSize();
//					 Vec2 origin = Director::getInstance()->getVisibleOrigin();
//					 //CCLog("aaaaaaaaaaaaaaa %d ", HelloWorld::number_of_columns);
//				this->setPosition(Vec2(visibleSize.width * (column/HelloWorld::number_of_columns) ,visibleSize.height/2));
//
//	}

	float CBrick::GenerateRandomColumn()
	{
		static int counter = 0;
		counter++;
		static std::vector<float> all_columns;

		if(counter > HelloWorld::number_of_columns)
		{
			all_columns.clear();
			float num = rand() % HelloWorld::number_of_columns;
			all_columns.push_back(num);
			counter = 0;
			return num;
		}


		float num;
		bool flag = true;

		while(1)
		{
			num = rand() % HelloWorld::number_of_columns;
			flag = true;
			for(float f : all_columns)
			{
				if(f == num)
				{
					flag = false;
					break;

				}

			}
			if(flag)
			{
				break;
			}

		}
		all_columns.push_back(num);
		return num;

	}





