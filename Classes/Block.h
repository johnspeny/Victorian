#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "GameSprite.h"

enum {
	BlockGap,
	Block1,
	Block2,
	Block3,
};

class Block : public GameSprite {
private:
	float width;
	float height;
public:
	Block();
	~Block();

	static Block* create();

	void setupBlock(int blockW, int blockH, int type);


};

#endif // !__BLOCK_H__
