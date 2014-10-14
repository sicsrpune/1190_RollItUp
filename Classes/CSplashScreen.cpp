/*
 * CSplashScreen.cpp
 *
 *  Created on: 21-Sep-2014
 *      Author: chaitany
 */

#include "CSplashScreen.h"
#include "constants.h"
#include "CGameManager.h"

USING_NS_CC;

Scene* CSplashScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = CSplashScreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CSplashScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
/*
    char FileName[32];


	GETFILENAME(FileName,32,"TutorialSplashScreen",".png");
	CCLog("_________________________ %s",FileName);
*/
    auto splash = Sprite::create("TutorialSplashScreenOn.png");
    /*SCALENODE_X(splash);
    SCALENODE_Y(splash);
*/
    splash->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(splash,rZIndexBG);

    scheduleOnce(schedule_selector(CSplashScreen::RunGameScreen),splashScreenTime);

    return true;
}

void CSplashScreen::RunGameScreen(float dt)
{
	CGameManager::Instance()->RunScene(rSceneGame);

}
