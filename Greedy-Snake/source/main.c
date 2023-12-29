#include <stdio.h>
#include <stdlib.h>

#include "../include/data.h"
#include "../include/draw.h"
#include "../include/input.h"
#include "../include/logic.h"
#include "../include/sleep.h"

#define WIDTH 20
#define HEIGHT 10

int main() {
	srand(time(NULL));

	Position position[1] = { rand() % (WIDTH / 2) + 1, rand() % (HEIGHT / 2) + 1 };
	Snake snake = { RIGHT, position, false, 1, 0 };
	BaseSetup baseSetup = { WIDTH, HEIGHT, {20 / 2, 50 / 2} };

	while (!snake.gameover) {
		Draw(&snake, &baseSetup);
		Input(&snake);
		Logic(&snake, &baseSetup);
		sleep_ms(1000);
	}
}