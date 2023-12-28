#ifndef DATA_H_
#define DATA_H_

#include <stdbool.h>

typedef enum eDirection {
	STOP = 0, LEFT, RIGHT, UP, DOWN
} Direction;

typedef struct sPos {
	int xPos;
	int yPos;
} Position;

typedef struct sSnake {
	Direction direction;
	Position *pos;
	bool gameover;
	int length;
	int score;
} Snake;

typedef struct sBaseSetup {
	int width;
	int height;
	Position fruit;
} BaseSetup;

#endif
