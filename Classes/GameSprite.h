#ifndef __GAMESPRITE_H__
#define __GAMESPRITE_H__

#include "cocos2d.h"

class GameSprite : public cocos2d::Sprite{
public:
	GameSprite();
	~GameSprite();

	cocos2d::Size _screenSize;

	CC_SYNTHESIZE(float, _width, Width);
	CC_SYNTHESIZE(float, _height, Height);

};

#endif // !__GAMESPRITE_H__
