#include "Terain.h"

USING_NS_CC;

using namespace cocos2d;

int types[] = {1, 2, 3, 1, 3, 2, 1, 3};

std::vector<int> _blockTypes(types, types + sizeof(types)/sizeof(int));

Terain::Terain(void)
{
	_minTerainWidth = 0;
	_screenSize = Director::getInstance()->getVisibleSize();
	_currentTerainWidth = 0;
	_blockpoolIndex = 0;
	_currentTypeIndex = 0;
	_startTerain = false;
}

Terain::~Terain()
{
}

Terain* Terain::create()
{
    Terain* terain = new Terain();
	if (terain && terain->initWithFile("box.png"))
	{
		terain->autorelease();
		terain->setAnchorPoint(Vec2(0, 0));
		terain->initTerain();
		return terain;
	}
	CC_SAFE_DELETE(terain);
    return nullptr;
}

void Terain::move(float xSpeed)
{
	if (_startTerain)
	{
		// move the terain to the left
		this->setPositionX(this->getPositionX() - xSpeed);

		// wen a block leaves the screen we move it to the end of _blocks array
		// and reinitialise it as a new block
		auto block = _blocks.at(0);
		//log("pos %f", _position.x);
		if (_position.x + block->getWidth() < 0)
		{
			auto firstBlock = _blocks.at(0);
			_blocks.erase(_blocks.begin() + 0);
			_blocks.push_back(firstBlock);
			// position of terain and new block is set to zero
			_position.x += block->getWidth();

			// get the current width of terain
			float width_cnt = this->getWidth() - block->getWidth() - (_blocks.at(0))->getWidth();
			//log("block width %f", block->getWidth());
			//log("total width %f", (_blocks.at(0))->getWidth());

			

			while (width_cnt < _minTerainWidth)
			{
				auto block = _blockPool.at(_blockpoolIndex);
				_blockpoolIndex++;
				if (_blockpoolIndex == _blockPool.size())
				{
					_blockpoolIndex = 0;
				}

				// while adding init block(make them visible)
				// more to this
				int _type = _blockTypes[_currentTypeIndex];
				if (_currentTypeIndex == _blockTypes.size())
				{
					_currentTypeIndex = 0;
				}
				_currentTypeIndex++;



				if (_startTerain)
				{
					_lastblockHeight = 2;
					_lastblockWidth = rand() % 2 + 2;
					block->setupBlock(_lastblockWidth, _lastblockHeight, _type);
				}
				

				// blocks width continue to be added
				width_cnt += block->getWidth();


				// we create a terain body and add blocks into it
				_blocks.push_back(block);

			}


			// ditribute the blocks
			for (size_t i = 0; i < _blocks.size(); i++)
			{
				auto block = _blocks.at(i);

				// block at index (0, 0) to be at position (0, 0)
				if (i != 0)
				{
					auto prev_block = _blocks.at(i - 1);

					block->setPositionX(prev_block->getPositionX() + prev_block->getWidth());
				}
				else
				{
					block->setPositionX(0);
				}

			}
		}

	}
}

void Terain::initTerain()
{
	// add blocks to a blocks pool
	for (size_t i = 0; i < 20; i++)
	{
		Block* block = Block::create();
		this->addChild(block);
		_blockPool.push_back(block);
	}

	_minTerainWidth = _screenSize.width * 1.5f;

	// add blocks if current terain width is less than mini terain width required
	while (_currentTerainWidth < _minTerainWidth)
	{
		auto block = _blockPool.at(_blockpoolIndex);
		_blockpoolIndex++;
		if (_blockpoolIndex == _blockPool.size())
		{
			_blockpoolIndex = 0;
		}

		// while adding init block(make them visible)
		// more to this
		int _type = _blockTypes[_currentTypeIndex];
		if (_currentTypeIndex == _blockTypes.size())
		{
			_currentTypeIndex = 0;
		}
		_currentTypeIndex++;



		if (_startTerain)
		{
		}
		else {
			_lastblockHeight = 2;
			_lastblockWidth = rand() % 2 + 2;
			block->setupBlock(_lastblockWidth, _lastblockHeight, _type);

		}

		// blocks width continue to be added
		_currentTerainWidth += block->getWidth();



		// we create a terain body and add blocks into it
		_blocks.push_back(block);

	}
	
	// when done with adding blocks, position them in the terain
	for (size_t i = 0; i < _blocks.size(); i++)
	{
		auto block = _blocks.at(i);

		// block at index (0, 0) to be at position (0, 0)
		if (i != 0)
		{
			auto prev_block = _blocks.at(i-1);

			block->setPositionX(prev_block->getPositionX() + prev_block->getWidth());
		}
		else
		{
			block->setPositionX(0);
		}

	}
}
