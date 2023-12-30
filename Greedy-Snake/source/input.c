#include <conio.h>
#include "../include/data.h"

void Input(Snake *snake) {
	// Implementation of the Input function
	// Use the snake structure for processing input
	if (generalKbhit()) {
		switch (_getch()) {
		case 'a':
		case '\x1b[D':
		case 75:
			snake->direction = LEFT;
			break;
		case 'd':
		case '\x1b[C':
		case 77:
			snake->direction = RIGHT;
			break;
		case 'w':
		case '\x1b[A':
		case 72:
			snake->direction = UP;
			break;
		case 's':
		case '\x1b[B':
		case 80:
			snake->direction = DOWN;
			break;
		case 'x':
			snake->gameover = 1;
			break;
		default:
			break;
		}
	}
}
