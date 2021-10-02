#ifndef __TERAIN_H__
#define __TERAIN_H__

#include "cocos2d.h"
#include "Block.h"

class Terain : public cocos2d::Sprite
{
public:
	Terain();
	~Terain();

	static Terain* create();

private:

	void initTerain();

};

#endif // !__TERAIN_H__
