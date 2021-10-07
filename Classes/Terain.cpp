#include "Terain.h"

USING_NS_CC;

using namespace cocos2d;

int types[] = {1, 2, 3, 1, 3, 2, 1, 3};

int patterns[] = {1, 1, 2, 1, 3};

int widths[] = {2, 2, 3};

int heights[] = { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,4 };

std::vector<int> _blockTypes(types, types + sizeof(types)/sizeof(int));
std::vector<int> _blockwidths(widths, widths + sizeof(widths)/sizeof(int));
std::vector<int> _blockheights(heights, heights + sizeof(heights)/sizeof(int));
std::vector<int> _blockpattern(patterns, patterns + sizeof(patterns)/sizeof(int));

Terain::Terain(void)
{
	_minTerainWidth = 0;
	_screenSize = Director::getInstance()->getVisibleSize();
	_currentTerainWidth = 0;
	_blockpoolIndex = 0;
	_currentTypeIndex = 0;
	_startTerain = false;
	_showGap = false;

	_currentWidthIndex = 0;
	_currentHeightIndex = 0;
	_currentPatternCnt = 0;
	_currentPatternIndex = 0;
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

			






			// while adding init block(make them visible)
				// more to this
			int blockWidth;
			int blockHeight;

			
			int _type = _blockTypes[_currentTypeIndex];
			if (_currentTypeIndex == _blockTypes.size())
			{
				_currentTypeIndex = 0;
			}
			_currentTypeIndex++;



			if (_startTerain)
			{
				if (_showGap)
				{

					int gap = rand() % 2;
					if (gap < 2) gap = 2;

					block->setupBlock(gap, 0, BlockGap);

					log("gap %d", gap);
					_showGap = false;
				}
				else
				{

					// get widths
					blockWidth = _blockwidths[_currentWidthIndex];
					if (_currentWidthIndex == _blockwidths.size())
					{
						std::random_shuffle(_blockwidths.begin(), _blockwidths.end());
						_currentWidthIndex = 0;
					}
					_currentWidthIndex++;

					// get heights
					if (_blockheights[_currentHeightIndex] != 0)
					{
						blockHeight = _blockheights[_currentHeightIndex];
						log("not 0 heights %d", blockHeight);
						if (blockHeight - _lastblockHeight > 2 && _gapSize == 2)
						{
							blockHeight = 1;
						}
					}
					else {
						blockHeight = _lastblockHeight;
						log("0 heights %d", blockHeight);
					}

					if (_currentHeightIndex == _blockheights.size())
					{
						_currentHeightIndex = 0;
						std::random_shuffle(_blockheights.begin(), _blockheights.end());
					}
					_currentHeightIndex++;

					// get patterns
					_currentPatternCnt++;
					if (_currentPatternCnt > _blockpattern[_currentPatternIndex])
					{

						_showGap = true;
						// start new pattern
						_currentPatternIndex++;
						if (_currentPatternIndex == _blockpattern.size())
						{
							std::random_shuffle(_blockpattern.begin(), _blockpattern.end());
							_currentPatternIndex = 0;
						}
						log("pCnt %d", _currentPatternCnt);
						_currentPatternCnt = 1;
					}


					// apply to setupBlock
					// show gap when pattern 

					block->setupBlock(blockWidth, blockHeight, _type);
					_lastblockWidth = blockWidth;
					_lastblockHeight = blockHeight;
				}

			}








			while (width_cnt < _minTerainWidth)
			{

				int blockWidth;
				int blockHeight;

				auto block = _blockPool.at(_blockpoolIndex);
				_blockpoolIndex++;
				if (_blockpoolIndex == _blockPool.size())
				{
					_blockpoolIndex = 0;
				}

				// while adding init block(make them visible)
				// more to this
							   
							   
				
				if (_startTerain)
				{
					if (_showGap)
					{
						
						int gap = rand() % 2;
						if (gap < 2) gap = 2;

						block->setupBlock(gap, 0, BlockGap);

						log("gap %d", gap);
						_showGap = false;
					}
					else
					{

						// get widths
						blockWidth = _blockwidths[_currentWidthIndex];
						if (_currentWidthIndex == _blockwidths.size())
						{
							std::random_shuffle(_blockwidths.begin(), _blockwidths.end());
							_currentWidthIndex = 0;
						}
						_currentWidthIndex++;

						// get heights
						if (_blockheights[_currentHeightIndex] != 0)
						{
							blockHeight = _blockheights[_currentHeightIndex];
							log("not 0 heights %d", blockHeight);
							if (blockHeight - _lastblockHeight > 2 && _gapSize == 2)
							{
								blockHeight = 1;
							}
						}
						else {
							blockHeight = _lastblockHeight;
							log("0 heights %d", blockHeight);
						}

						if (_currentHeightIndex == _blockheights.size())
						{
							_currentHeightIndex = 0;
							std::random_shuffle(_blockheights.begin(), _blockheights.end());
						}
						_currentHeightIndex++;

						// get patterns
						_currentPatternCnt++;
						if (_currentPatternCnt > _blockpattern[_currentPatternIndex])
						{

							_showGap = true;
							// start new pattern
							_currentPatternIndex++;
							if (_currentPatternIndex == _blockpattern.size())
							{
								std::random_shuffle(_blockpattern.begin(), _blockpattern.end());
								_currentPatternIndex = 0;
							}
							log("pCnt %d", _currentPatternCnt);
							_currentPatternCnt = 1;
						}


						// apply to setupBlock
						// show gap when pattern 

						block->setupBlock(blockWidth, blockHeight, _type);
						_lastblockWidth = blockWidth;
						_lastblockHeight = blockHeight;
					}

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
	_gapSize = 2;

	// add blocks to a blocks pool
	for (size_t i = 0; i < 20; i++)
	{
		Block* block = Block::create();
		this->addChild(block);
		_blockPool.push_back(block);
	}

	// shuffle
	std::random_shuffle(_blockpattern.begin(), _blockpattern.end());
	std::random_shuffle(_blockwidths.begin(), _blockwidths.end());
	std::random_shuffle(_blockheights.begin(), _blockheights.end());

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
