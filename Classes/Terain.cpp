#include "Terain.h"

USING_NS_CC;

using namespace cocos2d;

Terain::Terain(void)
{
	_minTerainWidth = 0;
	_screenSize = Director::getInstance()->getVisibleSize();
	_currentTerainWidth = 0;
}

Terain::~Terain()
{
}

Terain* Terain::create()
{
    Terain* terain = new Terain();
	if (terain && terain->initWithFile("box.png"))
	{
		terain->setAnchorPoint(Vec2(0, 0));
		terain->initTerain();
		terain->autorelease();
		return terain;
	}
	CC_SAFE_DELETE(terain);
    return nullptr;
}

void Terain::initTerain()
{
	// add blocks to a blocks pool
	for (size_t i = 0; i < 20; i++)
	{
		Block* block = Block::create();
		block->addChild(block);
		_blockPool.push_back(block);
	}

	_minTerainWidth = _screenSize.width * 1.5f;

	
	// add blocks if current terain width is less than mini terain width required
	_currentTerainWidth = 0;
	while (_currentTerainWidth < _minTerainWidth)
	{
		int _blockpoolIndex = 0;
		auto block = _blockPool.at(_blockpoolIndex);
		_blockpoolIndex++;
		if (_blockpoolIndex == _blockPool.size())
		{
			_blockpoolIndex = 0;
		}

		// while adding init block(make them visible)
		block->setupBlock(1, 1, 1);

		// blocks width continue to be added
		_currentTerainWidth += block->getWidth();


		// we create a terain body and add blocks into it
		_blocks.push_back(block);

	}
	
	// when done with adding blocks, position them in the terain
}
