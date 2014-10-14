#include "HelloWorldScene.h"
#include "CGameManager.h"
#include "CBall.h"
#include "constants.h"
#include "CBall.cpp"
#include "SimpleAudioEngine.h"
#include "CBrick.h"
#include "CBrick.cpp"

USING_NS_CC;

int HelloWorld::number_of_columns = 0;

cocos2d::Label * HelloWorld::_startLabel = NULL;
cocos2d::Label * HelloWorld::_scoreLabel = NULL;
cocos2d::Label * HelloWorld::_highScoreLabel = NULL;
cocos2d::Touch * HelloWorld::touch_point = NULL;
cocos2d::Sprite * HelloWorld::reset_button = NULL;
cocos2d::Sprite * HelloWorld::exit_button = NULL;

bool HelloWorld::game_over_flag = false;



Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    UserDefault* def = UserDefault::sharedUserDefault();
    /*
    def->setIntegerForKey("HIGH_SCORE", 1);
    def->flush();
*/
   // CCLog("abc==========%u",def->getIntegerForKey("HIGH_SCORE"));


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    CGameManager::Instance()->SetUpScaleFactors();

    _touchFlag = false;

    char FileName[32];


    GETFILENAME(FileName,32,"ball-basket",".png");
    auto _ball = CBall::createWithFileName(FileName);
    SCALENODE_X(_ball);
    SCALENODE_Y(_ball);
    _ball->Reset();
    this->addChild(_ball,rZIndexBall);
    _ball->SetSpeedAndWidth(rBallStartSpeedX, visibleSize.width);
    _ball->State = rBallStateStopped;
    //       _ball->retain();
    global_ball = _ball;

    HelloWorld::number_of_columns = visibleSize.width/((1.5)*_ball->getBoundingBox().size.width);


    //Chaitany edit test background
    	GETFILENAME(FileName,32,"BG1",".png");
        auto bg = Sprite::create(FileName);
        //CCLog("%s",FileName);
        SCALENODE_X(bg);
        SCALENODE_Y(bg);
        bg->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
        this->addChild(bg,rZIndexBG);
    //chaitany edit end

        GETFILENAME(FileName,32,"brick_brown",".png");
        auto brick1 = CBrick::generateWithFileName(FileName);
        SCALENODE_X(brick1);
         SCALENODE_Y(brick1);


         float col_num = GenerateRandomColumn();
         CCLog("#$#$ 1: %f", col_num);
        brick1->Reset(col_num);
        brick1->SetSpeedAndHeight(sBrickStartSpeedY,visibleSize.height);
        this->addChild(brick1,rZIndexBricks);
        _bricks.pushBack(brick1);



        GETFILENAME(FileName,32,"brick_brown",".png");
              auto brick3 = CBrick::generateWithFileName(FileName);
              SCALENODE_X(brick3);
              SCALENODE_Y(brick3);
             // CCLog("#$#$ %f", col_num);
              col_num = GenerateRandomColumn();
              CCLog("#$#$ 2: %f", col_num);
              brick3->Reset(col_num);
              brick3->SetSpeedAndHeight(sBrickStartSpeedY,visibleSize.height);
              this->addChild(brick3,rZIndexBricks);
              _bricks.pushBack(brick3);


        GETFILENAME(FileName,32,"brick_brown",".png");
        auto brick2 = CBrick::generateWithFileName(FileName);
        SCALENODE_X(brick2);
         SCALENODE_Y(brick2);
         //CCLog("#$#$ %f", col_num);
         col_num = GenerateRandomColumn();
         CCLog("#$#$ 3: %f", col_num);
        brick2->Reset(col_num);
        brick2->SetSpeedAndHeight(sBrickStartSpeedY,visibleSize.height);
        this->addChild(brick2,rZIndexBricks);
        _bricks.pushBack(brick2);

        GETFILENAME(FileName,32,"brick_brown",".png");
        auto brick4 = CBrick::generateWithFileName(FileName);
        SCALENODE_X(brick4);
         SCALENODE_Y(brick4);
         col_num = GenerateRandomColumn();
         CCLog("#$#$ 4: %f", col_num);
        brick4->Reset(col_num);
        brick4->SetSpeedAndHeight(sBrickStartSpeedY,visibleSize.height);
        this->addChild(brick4,rZIndexBricks);
        _bricks.pushBack(brick4);

        HelloWorld::exit_button = Sprite::create("exit.png");
        HelloWorld::exit_button->setPosition(Vec2(visibleSize.width*(3.0/7.0),visibleSize.height/2));
        this->addChild(HelloWorld::exit_button,rZIndexBall);
        HelloWorld::exit_button->setVisible(false);

        HelloWorld::reset_button = Sprite::create("reset.png");
        HelloWorld::reset_button->setPosition(Vec2(visibleSize.width*(4.0/7.0),visibleSize.height/2));
        this->addChild(HelloWorld::reset_button,rZIndexBall);
        HelloWorld::reset_button->setVisible(false);

//
//        GETFILENAME(FileName,32,"brick_brown",".png");
//                auto brick5 = CBrick::generateWithFileName(FileName);
//                SCALENODE_X(brick5);
//                 SCALENODE_Y(brick5);
//                brick5->Setup(GenerateRandomColumn(true));
//                brick5->SetSpeedAndHeight(sBrickStartSpeedY,visibleSize.height);
//                this->addChild(brick5,rZIndexBricks);
//                _bricks.pushBack(brick5);
//

//                /CCLog("====================%f  || %f || %f ",GenerateRandomColumn(false),GenerateRandomColumn(false),GenerateRandomColumn(false));





        /* GETFILENAME(FileName,32,"broken_brick_brown",".png");
        auto broken_brick =  CBrick::generateWithFileName(FileName);
        SCALENODE_X(broken_brick);
         SCALENODE_Y(broken_brick);
        broken_brick->setPosition(Vec2(origin.x+visibleSize.width/1.5,visibleSize.height /2));
        brick1->SetSpeedAndHeight(sBrickStartSpeedX,visibleSize.height);
        this->addChild(broken_brick,rZIndexBricks);
        _bricks.pushBack(broken_brick);
*/



/*
       auto life1 = Sprite::create("heart_no_life.png");
       SCALENODE_X(life1);
       SCALENODE_Y(life1);
       life1->setPosition(Vec2(visibleSize.width-3*(2+life1->getBoundingBox().width)),visibleSize.height-(life1->getBoundingBox().height));
       this->addChild(life1);


       auto life2 = Sprite::create("heart_life.png");
       SCALENODE_X(life2);
       SCALENODE_Y(life2);
       life2->setPosition(Vec2(visibleSize.width-2*(2+life1->getBoundingBox().width)),visibleSize.height-(life2->getBoundingBox().height));
       this->addChild(life2);


       auto life3 = Sprite::create("heart_life.png");
       SCALENODE_X(life2);
       SCALENODE_Y(life2);
       life2->setPosition(Vec2(visibleSize.width-(2+life1->getBoundingBox().width)),visibleSize.height-(life2>getBoundingBox().height));

       this->addChild(life2);
*/





       auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

        Device::setAccelerometerEnabled(true);
        auto acclerometer_listener = EventListenerAcceleration::create(CC_CALLBACK_2(HelloWorld::onAcceleration,this));
        _eventDispatcher->addEventListenerWithSceneGraphPriority(acclerometer_listener,this);


        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("roll_bg.mp3",true);

        HelloWorld::_startLabel = AddLabel(LabelFontSize, "Tap The Screen To Start", Vec2(0.5 , 0.5),
                							 Vec2(visibleSize.width / 2, visibleSize.height * 3 / 4));
    	HelloWorld::_scoreLabel = AddLabel(LabelFontSize,"Score:", Vec2(0.0, 1.0),Vec2(10, visibleSize.height - 10));
    	HelloWorld::_highScoreLabel = AddLabel(LabelFontSize,"Best:", Vec2(0.0, 1.0),Vec2(10, visibleSize.height - 90));

    	sprintf(high_score_str,"%d",def->getIntegerForKey(HIGH_SCORE));
    			char str_high[30];
    			strcpy(str_high, "Best: ");
    			strcat(str_high, high_score_str);
    			HelloWorld::_highScoreLabel->setString(str_high);



          HelloWorld::_startLabel->setVisible(false);



        schedule(schedule_selector(HelloWorld::update));
        //scheduleUpdate();

    return true;
}


float HelloWorld::GenerateRandomColumn()
	{

		static std::vector<float> all_columns;


		if(all_columns.size() >=  HelloWorld::number_of_columns)
		{
			all_columns.clear();
			float num = rand() % HelloWorld::number_of_columns;
			all_columns.push_back(num);

			return num;
		}


		float num;
		bool flag = true;
		int counter = 0;
		while(counter++ < HelloWorld::number_of_columns)
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

void HelloWorld::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *aEvent)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("aou.wav");


/*

	auto _ball = global_ball;
	_ball->Accelerated(acc);
	CCLOG("#### x = %f || y = %f || z = %f \n",acc->x,acc->y,acc->z);
*/

}

bool HelloWorld::onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *pEvent)
{

	HelloWorld::touch_point = pTouches;

	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("shift.wav");


	auto location = pTouches->getLocationInView();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	location = Director::sharedDirector()->convertToGL(location);

	auto _ball = global_ball;
	if(location.x > (float)visibleSize.width/2)
	{
	_ball->MoveDown();
	}
	else
	{
		_ball->MoveUp();
	}

	if(_ball->State == rBallStateStopped)
	{
		_ball->Reset();
		_ball->State = rBallStateMoving;
		_ball->setVisible(true);
	}
	return true;

}


void HelloWorld::update(float dt)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    CBall *_ball = global_ball;
	sprintf(score_str,"%u",_ball->score);
		char str[30];
		strcpy(str, "Score: ");
		strcat(str, score_str);
		HelloWorld::_scoreLabel->setString(str);

// CCLog("=======%f\n",dt);
if(HelloWorld::game_over_flag == false)
{


		if(_ball->State == rBallStateMoving)
		{
				_ball->Update(dt);
				HelloWorld::_startLabel->setVisible(false);


				for(auto brick : _bricks)
				{
					brick->Update(dt);

				}

				for(auto brick : _bricks)
					{
							if( _ball->getCollisionBox().intersectsRect(brick->brickCollisonBox()))
									{
										_ball->Stop();
										_ball->attempts++;

										if(_ball->attempts % 2 == 0)
										{

										}

										_ball->State = rBallStateStopped;
										for(auto all_brick: _bricks)
										{
											float col = GenerateRandomColumn();
											CCLog("12345---- %f", col);
											all_brick->Reset(col);
										}

										  SpriteBatchNode* spritebatch = SpriteBatchNode::create("exp.png");
											SpriteFrameCache* cache = SpriteFrameCache::getInstance();
											cache->addSpriteFramesWithFile("exp.plist");
											auto m_pSprite1 = Sprite::createWithSpriteFrameName("0.png");
											m_pSprite1->setPosition(Vec2(_ball->getPositionX(),_ball->getPositionY()));
											spritebatch->addChild(m_pSprite1);
											this->addChild(spritebatch,500);

											Vector<SpriteFrame*> animFrames(15);

												char str[100] = {0};

												for(int i = 0; i <= NUMBER_OF_FRAMES; i++)
												{
													sprintf(str, "%d.png", i);
													SpriteFrame* frame = cache->getSpriteFrameByName( str );
													animFrames.pushBack(frame);
												}

												Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.07);
												CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("kaboom.wav");
												m_pSprite1->runAction( Animate::create(animation) );
												_ball->setVisible(false);

									}

					}
		}
		else
		{
			HelloWorld::_startLabel->setVisible(true);
			_ball->Stop();
		}


	}
	else
	{

		char str_over[30];
				strcpy(str_over, "Game Over \n \n Your score is ");
				strcat(str_over, score_str);



		HelloWorld::_startLabel->setString(str_over);
		HelloWorld::_startLabel->setVisible(true);
		HelloWorld::_scoreLabel->setVisible(false);
		_ball->setVisible(false);

		if(_ball->score > def->getIntegerForKey(HIGH_SCORE))
		{
		  def->setIntegerForKey(HIGH_SCORE,_ball->score);
		    def->flush();
		}

		HelloWorld::exit_button->setVisible(true);
		HelloWorld::reset_button->setVisible(true);



		if(HelloWorld::exit_button->getBoundingBox().containsPoint(HelloWorld::touch_point->getLocation()))
		{
			this->setTouchEnabled(false);
			ExitApp();

		}
		if(HelloWorld::reset_button->getBoundingBox().containsPoint(HelloWorld::touch_point->getLocation()))
		{
			HelloWorld::game_over_flag = false;
			CGameManager::Instance()->RunScene(rSceneSplash);
		}

	}
}


Label* HelloWorld::AddLabel(const float fontSize, const char* text, const cocos2d::Vec2 anchor, const cocos2d::Vec2 position)
{
	Label *theLabel = Label::createWithTTF(text, rFontName, fontSize);
	theLabel->setAnchorPoint(anchor);
	theLabel->setPosition(position);
	theLabel->setColor(Color3B::BLACK);
	this->addChild(theLabel, rZIndexHeart);
	return theLabel;

}
void HelloWorld::ExitApp()
{
	CCDirector::sharedDirector()->end();

}
