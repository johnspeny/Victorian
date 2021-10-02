#include "GameSprite.h"

USING_NS_CC;

using namespace cocos2d;

GameSprite::GameSprite()
{
	_screenSize = Director::getInstance()->getVisibleSize();
}

GameSprite::~GameSprite()
{
}
