#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "GameSprite.h"


class Block : public GameSprite {
private:
	float width;
	float height;
public:
	Block();
	~Block();

	void setupBlock(int blockW, int blockH, int type);
};

#endif // !__BLOCK_H__
