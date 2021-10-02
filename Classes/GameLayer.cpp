#include "GameLayer.h"

using namespace cocos2d;

USING_NS_CC;

bool GameLayer::init()
{
	if (!Scene::init())
	{
		return false;
	}

		// create a game batch 
		_gameBatchNode = SpriteBatchNode::create("box.png");
		this->addChild(_gameBatchNode, GameMiddleground);

		terain = Terain::create();
		_gameBatchNode->addChild(terain, GameMiddleground);
	
	return true;
}
