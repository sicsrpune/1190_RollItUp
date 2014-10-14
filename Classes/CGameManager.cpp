/*
 * CGameManager.cpp
 *
 *  Created on: 16-Aug-2014
 *      Author: chaitany
 */

#include "CGameManager.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "CSplashScreen.h"
#include "CSplashScreen.cpp"

USING_NS_CC;

#define rExtMD "-MD"
#define rExtHD "-HD"
#define rExtUHD "-UHD"
#define rExtUUHD "-UUHD"

CGameManager *CGameManager::_pInstance = NULL;


CGameManager* CGameManager::Instance(){
	if(!_pInstance)
	{
		_pInstance = new CGameManager;
	}
	return _pInstance;
}

void CGameManager::RunScene(int scene)
{
	Scene *pScene = NULL;

	if(scene == rSceneGame)
	{
		pScene = HelloWorld::createScene();
	}
	else if(scene == rSceneSplash)
	{
		pScene = CSplashScreen::createScene();
	}

	if(CCDirector::sharedDirector()->getRunningScene() == NULL)
	{
		CCDirector::sharedDirector()->runWithScene(pScene);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(pScene);
	}

}


float CGameManager::GetScaleX(){
return _scaleX;
}

float CGameManager::GetScaleY(){
return _scaleY;
}

float CGameManager::GetScaleFactor(){
return _scaleFactor;
}

void CGameManager::SetUpScaleFactors(){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	_extension = (char *)rExtHD;
	_scaleFactor = 1.0;
	//_scaleFactor = 0.5;



	 if ((visibleSize.height * visibleSize.width) >= (1900*1070))
			{
						_extension = (char *)rExtUUHD;
						_scaleFactor = 2.5;

			}

	 else if((visibleSize.height * visibleSize.width) < (1900*1070) && (visibleSize.height * visibleSize.width) > (900*500))
	 	{
	 			_extension = (char *)rExtUUHD;
	 			_scaleFactor = 2.0;
	 			//_scaleFactor = 1.0;
	 	}

	else if((visibleSize.height * visibleSize.width) <= (900*500) && (visibleSize.height * visibleSize.width) > (600*300))
	{
			_extension = (char *)rExtUHD;
			_scaleFactor = 1.2;
			//_scaleFactor = 1.0;
	}
	else if ((visibleSize.height * visibleSize.width) <= (600*300))
	{
				_extension = (char *)rExtMD;
				_scaleFactor = 1.0;
				//_scaleFactor = 0.25;
	}

	_scaleX = visibleSize.width /(960 * _scaleFactor);
	_scaleY = visibleSize.height /(540 * _scaleFactor);

}

void CGameManager::GetFileName(char *array, const int len, const char *name, const char *fileExt){
memset(array,0,sizeof(char)*len);
sprintf(array,"%s%s%s",name,_extension,fileExt);

}
