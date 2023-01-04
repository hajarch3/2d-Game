/****************************************************************************

 
 http://www.cocos2d-x.org
 

 ****************************************************************************/

#ifndef __FIRSTLEVEL_H__
#define __FIRSTLEVEL_H__

#include "cocos2d.h"
using namespace cocos2d;

class FirstLevel :  public cocos2d::Layer
{

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    // a selector callback
   // void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(FirstLevel);

    cocos2d::Sprite* sprite;

//touch
    void update(float dt);
    
    
    //touch code
   bool onTouchBegan(cocos2d::Touch* touch, cocos2d::
    Event* event);
void onTouchMoved(cocos2d::Touch* touch, cocos2d::
    Event* event);
void onTouchEnded(cocos2d::Touch* touch, cocos2d::
    Event* event);
void onTouchCancelled(cocos2d::Touch* touch, cocos2d::
    Event* event);
bool isTouching;
float touchPosition;

};


#endif // __FIRSTLEVEL_H__
