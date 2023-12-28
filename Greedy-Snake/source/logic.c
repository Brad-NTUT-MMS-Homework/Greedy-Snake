#include <stdlib.h>
#include "../include/data.h"

void Logic(Snake *snake, BaseSetup *baseSetup) {
	// Implementation of the Logic function
	// Use snake and baseSetup structures for game logic
	int prevX = snake->pos.xPos;
	int prevY = snake->pos.yPos;
	int prev2X, prev2Y;
	snake->pos.xPos = prevX;
	snake->pos.yPos = prevY;

	for (int i = 1; i < snake->length; i++) {
		prev2X = snake->pos.xPos;
		prev2Y = snake->pos.yPos;
		snake->pos.xPos = prevX;
		snake->pos.yPos = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}
