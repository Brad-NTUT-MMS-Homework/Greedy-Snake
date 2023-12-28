#include <stdlib.h>
#include "../include/data.h"

int addLength(Snake *snake, int newXPos, int newYPos) {
	// Calculate the new length of the position array
	int newLength = snake->length + 1;

	// Reallocate memory to accommodate the new length of positions
	Position *newPositions = (Position *)realloc(snake->pos, newLength * sizeof(Position));
	
	// Memory allocation failed
	if (newPositions == NULL) {
		return -1; // Or any appropriate error code
	}

	// Update the snake's position array and length
	snake->pos = newPositions;
	snake->length = newLength;

	// Add the new position to the end of the position array
	snake->pos[newLength - 1].xPos = newXPos;
	snake->pos[newLength - 1].yPos = newYPos;

	return 0; // Successful addition of length
}

void Logic(Snake *snake, BaseSetup *baseSetup) {
	// Implementation of the Logic function
	// Use snake and baseSetup structures for game logic

	int snakeLength = snake->length;
	int prevX, prevY;
	if (snakeLength != 1) {
		snake->pos[snakeLength - 1].xPos;
		snake->pos[snakeLength - 1].yPos;
	}

	int prev2X, prev2Y;
	snake->pos[snakeLength].xPos = prevX;
	snake->pos[snakeLength].yPos = prevY;

	for (int i = 1; i < snake->length; i++) {
		prev2X = snake->pos[i].xPos;
		prev2Y = snake->pos[i].yPos;
		snake->pos[i].xPos = prevX;
		snake->pos[i].yPos = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if (snake->pos[0].xPos >= baseSetup->width || snake->pos[0].xPos < 0 || snake->pos[0].yPos >= baseSetup->height || snake->pos[0].yPos < 0)
		snake->gameover = 1;

	for (int i = 1; i < snake->length; i++) {
		if (snake->pos[0].xPos == snake->pos[i].xPos && snake->pos[0].yPos == snake->pos[i].yPos)
			snake->gameover = 1;
	}

	if (baseSetup->width == baseSetup->fruit.xPos && baseSetup->height == baseSetup->fruit.yPos) {
		snake->score += 10;
		snake->length++;
		baseSetup->fruit.xPos = rand() % baseSetup->width;
		baseSetup->fruit.yPos = rand() % baseSetup->height;
	}
}
