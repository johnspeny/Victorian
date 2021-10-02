#include "Block.h"


#define TILE_WIDTH 8
#define TILE_HEIGHT 6


Block::Block()
{
	// 480 320
	width = _screenSize.width / TILE_WIDTH;
	height = _screenSize.height / TILE_HEIGHT;
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
}
