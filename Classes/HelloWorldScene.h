/****************************************************************************

 
 http://www.cocos2d-x.org
 

 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld :  public cocos2d::Layer
{

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    // a selector callback
   // void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    void Play(Ref* pSender);
    void GAME(Ref* pSender);
   
};

#endif // __HELLOWORLD_SCENE_H__
