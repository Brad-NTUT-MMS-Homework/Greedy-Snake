#include <stdio.h>

#include "../include/draw.h"
#include "../include/data.h"

void Draw(Snake *snake, BaseSetup *baseSetup) {
	// Implementation of the Draw function
	// Use snake and baseSetup structures for drawing
	system("cls");
	for (int i = 0; i < baseSetup->width + 2; i++)
		printf("#");
	printf("\n");

	for (int i = 0; i < baseSetup->height; i++) {
		for (int j = 0; j < baseSetup->width; j++) {
			if (j == 0)
				printf("#");
			if (i == snake->pos[i].xPos && j == snake->pos[j].xPos)
				printf("O");
			else if (i == baseSetup->fruit.yPos && j == baseSetup->fruit.xPos)
				printf("F");
			else {
				int printTail = 0;
				for (int k = 1; k < snake->length; k++) {
					if (i == snake->pos[k].yPos && j == snake->pos[k].xPos) {
						printf("o");
						printTail = 1;
					}
				}
				if (!printTail)
					printf(" ");
			}
			if (j == baseSetup->width - 1)
				printf("#");
		}
		printf("\n");
	}
}
