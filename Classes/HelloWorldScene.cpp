/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 

 ****************************************************************************/

#include "HelloWorldScene.h"
#include "FirstLevel.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer =HelloWorld::create();
    scene->addChild(layer);
    return scene ;
}



// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1
    if (!Layer::init()) {
        return false;
    }
    // 2
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getVisibleSize();
    // 3
    auto background = DrawNode::create();
    background->drawSolidRect(origin, winSize, Color4F(1.4, 0.6,0.7, 1.0));
    this->addChild(background,0);

    //6
     auto menu_item_1 = MenuItemImage::create("CloseNormal.png","CloseSelected.png", CC_CALLBACK_1(HelloWorld::GAME, this));
   
    auto menu_item_2 = MenuItemFont::create("Play",CC_CALLBACK_1(HelloWorld::Play,this));
    
    auto* menu = Menu::create(menu_item_1, menu_item_2,NULL);
    menu->alignItemsVertically();
    this->addChild(menu,3);

    return true;

}
void HelloWorld::Play(cocos2d::Ref* pSender) {
    CCLOG("Play");
    auto scene = FirstLevel::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}
void HelloWorld::GAME(cocos2d::Ref* pSender) {
    CCLOG("GAME");
}



/*void HelloWorld::update(float delta)
{
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    sprite->setPosition(position);


}*/
