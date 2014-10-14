#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "constants.h"
#include "CBrick.h"
//#include "CBrick.cpp"

class CBall;
//class CBrick;

class HelloWorld : public cocos2d::Layer
{

private:
	float _gameOver;
	bool _touchFlag;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    CBall *global_ball;/*
    CBrick *global_brick;
    CBrick *global_brick2;*/
    cocos2d::Vector<CBrick *> _bricks;
    static int number_of_columns;
    static cocos2d::Label *_startLabel;
    static cocos2d::Label *_scoreLabel;
    static cocos2d::Label *_highScoreLabel;
    static cocos2d::Sprite *exit_button;
    static cocos2d::Sprite *reset_button;
    static cocos2d::Touch *touch_point;



    static bool game_over_flag;
    static unsigned int high_score;
    char score_str[20];
    char high_score_str[20];
    UserDefault* def;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback

    //void gameUpdate(float dt);
    void update(float dt);

    float GenerateRandomColumn();
    bool onTouchBegan(cocos2d::Touch *pTouches,cocos2d::Event *pEvent);
    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *aEvent);
    cocos2d::Label* AddLabel(const float fontSize,const char* text, const cocos2d::Vec2 anchor, const cocos2d::Vec2 position);
    void ExitApp();


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};
//int HelloWorld::number_of_columns = 0;
#endif // __HELLOWORLD_SCENE_H__
