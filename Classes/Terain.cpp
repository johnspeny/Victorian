#include "Terain.h"

USING_NS_CC;

using namespace cocos2d;

Terain::Terain()
{
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
	// add blocks if current terain width is less than mini terain width required
	// while adding init block(make them visible)
	// when done with adding blocks, position them in the terain
}
