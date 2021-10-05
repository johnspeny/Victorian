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
	
	void onMouseBegan(cocos2d::Event* event);
	void onMouseEnded(cocos2d::Event* event);

public:
	virtual bool init();
	virtual void update(float dt);
};


#endif // !__GAMELAYER_H__
