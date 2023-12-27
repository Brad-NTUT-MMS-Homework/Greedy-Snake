#ifndef DATA_H_
#define DATA_H_

#include <stdbool.h>

typedef enum eDirection {
	STOP = 0, LEFT, RIGHT, UP, DOWN
} Direction;

typedef struct sfruit {
	int xPos;
	int yPos;
} Fruit;

typedef struct sSnake {
	Direction direction;
	bool gameover;
	int length;
	int score;
} Snake;

typedef struct sBaseSetup {
	int width;
	int height;
	Fruit fruit;
} BaseSetup;

#endif
