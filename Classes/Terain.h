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

};

#endif // !__TERAIN_H__
