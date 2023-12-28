#include <conio.h>
#include "../include/data.h"

void Input(Snake *snake) {
	// Implementation of the Input function
	// Use the snake structure for processing input
	switch (_getch()) {
	case 'a':
		snake->direction == LEFT;
		break;
	case 'd':
		snake->direction == RIGHT;
		break;
	case 'w':
		snake->direction == UP;
		break;
	case 's':
		snake->direction == DOWN;
		break;
	case '\x1b[D':
		snake->direction == LEFT;
		break;
	case '\x1b[C':
		snake->direction == RIGHT;
		break;
	case '\x1b[A':
		snake->direction == UP;
		break;
	case '\x1b[B':
		snake->direction == DOWN;
		break;
	case 'x':
		snake->gameover = 1;

	if (snake->direction == UP) {
		snake->pos.yPos--;
	}
	if (snake->direction == DOWN) {
		snake->pos.yPos++;
	}
	if (snake->direction == LEFT) {
		snake->pos.xPos--;
	}
	if (snake->direction == RIGHT) {
		snake->pos.xPos++;
	}
}
