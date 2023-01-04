/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 

 ****************************************************************************/

#include "FirstLevel.h"

USING_NS_CC;

Scene* FirstLevel::createScene()
{
    auto scene = Scene::create();
    auto layer = FirstLevel::create();
    scene->addChild(layer);
    return scene ;
}



// on "init" you need to initialize your instance
bool  FirstLevel::init()
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
    background->drawSolidRect(origin, winSize, Color4F(1, 1, 1, 1.0));
    this->addChild(background, 0);
    //ground
    auto ground = DrawNode::create();
    ground->drawSolidRect(origin, winSize, Color4F(0, 0.5, 0, 1.0));
    ground->setPosition(Point(0, -270));
    this->addChild(ground, 1);

    // 4

    sprite = Sprite::create("CloseNormal.png");
    auto moveTo = MoveTo::create(3, Vec2(60, 0));
    //sprite->runAction( moveTo);
    auto moveBy = MoveBy::create(3, Vec2(60, 0));
    //sprite->runAction(moveBy);
    auto jumpto = JumpTo::create(3.0, Vec2(80, 0),45,5);
    //sprite->runAction(jumpto);
    auto jumpby = JumpBy::create(3.0, Vec2(80, 0), 45, 5);
    //sprite->runAction(jumpby);
    auto moveby = MoveBy::create(3, Vec2(150, 0));
    auto jump = JumpBy::create(3.0, Vec2(250, 0), 60, 6);
    auto action = Sequence::create(moveBy, jumpby, moveby, jump, NULL);
    sprite->runAction(action);
    sprite->setPosition(40, 65);
    this->addChild(sprite, 2);
    //5 

    //touch code
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(FirstLevel::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(FirstLevel::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(FirstLevel::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(FirstLevel::onTouchCancelled, this);
    this->getEventDispatcher() -> addEventListenerWithSceneGraphPriority(listener, this);
    isTouching = false;
    touchPosition = 0;
   /* sprite = Sprite::create("CloseSelected.png");

    sprite->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(sprite);*/
    //6
}
  //touch code
bool FirstLevel::onTouchBegan(cocos2d::Touch* touch,
    cocos2d::Event* event)
{
    isTouching = true;
    touchPosition = touch->getLocation().x;
    return true;
}
void FirstLevel::onTouchMoved(cocos2d::Touch* touch,
    cocos2d::Event* event)
{
    // not used for this game
}
void FirstLevel::onTouchEnded(cocos2d::Touch* touch,
    cocos2d::Event* event)
{
    isTouching = false;
}
void FirstLevel::onTouchCancelled(cocos2d::Touch* touch,
    cocos2d::Event* event)
{
    onTouchEnded(touch, event);
}
//code
void FirstLevel::update(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    // check if the screen is being touched
    if (true == isTouching)
    {
        // check which half of the screen is being touched
        if (touchPosition < visibleSize.width / 2)
        {
            // move the space pod left
            sprite->setPositionX(sprite->getPosition().x - (0.50 * visibleSize.width * dt));
            // check to prevent the space pod from going off the screen(left side)
                if (sprite->getPosition().x <= 0 +(sprite->getContentSize().width / 2))
                {
                    sprite->setPositionX(sprite->getContentSize().width / 2);
                }
        }
        else
        {
            // move the space pod right
            sprite->setPositionX(sprite->getPosition().x + (0.50 * visibleSize.width * dt));
            // check to prevent the space pod from going off the screen(right side)
                if (sprite->getPosition().x >=
                    visibleSize.width - (sprite->getContentSize().width / 2))
                {
                    sprite->setPositionX(visibleSize.width -(sprite->getContentSize().width / 2));
                }
        }
    }
}

/*void HelloWorld::update(float delta)
{
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    sprite->setPosition(position);


}*/
