#include "Block.h"


#define TILE_WIDTH 8
#define TILE_HEIGHT 6

using namespace cocos2d;

USING_NS_CC;


Block::Block()
{
	// 480 320
	width = _screenSize.width / TILE_WIDTH;
	height = _screenSize.height / TILE_HEIGHT;
	this->setVisible(false);
}


Block::~Block()
{
}


Block* Block::create()
{
	Block* block = new Block();
	if (block && block->initWithFile("box.png"))
	{
		block->autorelease();
		return block;
	}
	CC_SAFE_DELETE(block);
	return nullptr;
}


void Block::setupBlock(int blockW, int blockH, int type)
{
	_width = width * blockW; 
	_height = height * blockH; 
	int _type = type;

	this->setAnchorPoint(Vec2(0, 0));
	this->setTextureRect(Rect(0, 0, _width, _height));
	
	switch (_type)
	{
	case BlockGap:
		this->setVisible(false);
		return;

	case Block1:
		this->setColor(Color3B(200, 200, 200));
		break;

	case Block2:
		this->setColor(Color3B(150, 150, 150));
		break;

	case Block3:
		this->setColor(Color3B(50, 50, 50));
		break;
	}

	this->setVisible(true);
}
