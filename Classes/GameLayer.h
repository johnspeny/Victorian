#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "cocos2d.h"
#include "Terain.h"

enum {
	GameForeground,
	GameMiddleground,
	GameBackground
};

class GameLayer : public cocos2d::Scene {
private:
	Terain* terain;
	cocos2d::SpriteBatchNode* _gameBatchNode;
public:
	bool virtual init();
};


#endif // !__GAMELAYER_H__
