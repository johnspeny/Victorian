#include "GameLayer.h"

using namespace cocos2d;

USING_NS_CC;

bool GameLayer::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}
