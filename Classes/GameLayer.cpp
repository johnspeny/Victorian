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
	_gameBatchNode = SpriteBatchNode::create("box.png", 200);
	this->addChild(_gameBatchNode, GameMiddleground);

	terain = Terain::create();
	_gameBatchNode->addChild(terain, GameMiddleground);

	// event
	auto _mouseListener = EventListenerMouse::create();

	_mouseListener->onMouseDown = CC_CALLBACK_1(GameLayer::onMouseBegan, this);
	_mouseListener->onMouseUp = CC_CALLBACK_1(GameLayer::onMouseEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

	this->scheduleUpdate();
	
	return true;
}

void GameLayer::update(float dt)
{
	terain->move(0.5);
}


void GameLayer::onMouseBegan(cocos2d::Event* event)
{
	if (!terain->getStartTerain())
	{
		terain->setStartTerain(true);
	}
}

void GameLayer::onMouseEnded(cocos2d::Event* event)
{
}