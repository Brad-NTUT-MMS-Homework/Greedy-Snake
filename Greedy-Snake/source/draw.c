#include <stdio.h>

#include "../include/draw.h"
#include "../include/data.h"

void Draw(Snake *snake, BaseSetup *baseSetup) {
	// Implementation of the Draw function
	// Use snake and baseSetup structures for drawing
	CLEAR_SCREEN();
	for (int i = 0; i < baseSetup->width + 2; i++)
		printf("#");
	printf("\n");

	for (int height = 0; height < baseSetup->height; height++) {
		for (int width = 0; width < baseSetup->width; width++) {
			if (width == 0)
				printf("#");
			// Snake head
			if (height == snake->pos[0].yPos &&
				width == snake->pos[0].xPos)
				printf("O");
			else if (height == baseSetup->fruit.yPos &&
				width == baseSetup->fruit.xPos)
				printf("F");
			// Snake body and tail
			else {
				int printTail = 0;
				for (int posIdx = 0; posIdx < snake->length; posIdx++) {
					if (height == snake->pos[posIdx].yPos &&
						width == snake->pos[posIdx].xPos) {
						printf("o");
						printTail = 1;
					}
				}
				if (!printTail)
					printf(" ");
			}
			if (width == baseSetup->width - 1)
				printf("#");
		}
		printf("\n");
	}

	for (int i = 0; i < baseSetup->width + 2; i++)
		printf("#");
	printf("\n");
	printf("Score:%d\n", snake->score);
}
