#ifndef __TERAIN_H__
#define __TERAIN_H__

#include "cocos2d.h"
#include "Block.h"

class Terain : public cocos2d::Sprite
{
public:
	Terain(void);
	~Terain();

	static Terain* create();

	CC_SYNTHESIZE(bool, _startTerain, StartTerain);

	void move(float xSpeed);

private:

	cocos2d::Size _screenSize;

	float _lastblockHeight;
	float _lastblockWidth;

	int _currentTypeIndex;

	int _blockpoolIndex;

	std::vector<Block*> _blockPool;
	std::vector<Block*> _blocks;

	float _currentTerainWidth;
	float _minTerainWidth;

	void initTerain();

	inline float getWidth() { 
		float width = 0;
		Block* block;
		for (size_t i = 0; i < _blocks.size(); i++)
		{
			block = _blocks.at(i);
			width += block->getWidth();
		}
		return width;
	};

};

#endif // !__TERAIN_H__
