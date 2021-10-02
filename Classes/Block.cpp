#include "Block.h"

#define TILE_WIDTH 6
#define TILE_HEIGHT 3

Block::Block()
{
	// 480 320
	width = _screenSize.width / TILE_WIDTH;
	height = _screenSize.height / TILE_HEIGHT;
}

Block::~Block()
{
}

void Block::setupBlock(int blockW, int blockH, int type)
{
	_width = width * blockW; 
	_height = height * blockH; 
}
