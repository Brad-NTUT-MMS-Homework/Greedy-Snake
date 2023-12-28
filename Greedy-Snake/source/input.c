#include <conio.h>
#include "../include/data.h"

void Input(Snake *snake) {
	// Implementation of the Input function
	// Use the snake structure for processing input
	switch (_getch()) {
	case 'a':
	case '\x1b[D':
		snake->direction == LEFT;
		break;
	case 'd':
	case '\x1b[C':
		snake->direction == RIGHT;
		break;
	case 'w':
	case '\x1b[A':
		snake->direction == UP;
		break;
	case 's':
	case '\x1b[B':
		snake->direction == DOWN;
		break;
	case 'x':
		snake->gameover = 1;
		break;
	default:
		break;

	}
	for (int i = 0; i < snake->length; i++) {

		if (snake->direction == UP) {
			snake->pos[i].yPos--;
		}
		if (snake->direction == DOWN) {
			snake->pos[i].yPos++;
		}
		if (snake->direction == LEFT) {
			snake->pos[i].xPos--;
		}
		if (snake->direction == RIGHT) {
			snake->pos[i].xPos++;
		}
	}

}
