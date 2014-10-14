/*
 * CSplashScreen.h
 *
 *  Created on: 21-Sep-2014
 *      Author: chaitany
 */

#ifndef CSPLASHSCREEN_H_
#define CSPLASHSCREEN_H_

#include "cocos2d.h"

class CSplashScreen : public cocos2d::Layer
{

private:

	void RunGameScreen(float dt);

public:

    static cocos2d::Scene* createScene();

	virtual bool init();



    // implement the "static create()" method manually
    CREATE_FUNC(CSplashScreen);
};

#endif /* CSPLASHSCREEN_H_ */
