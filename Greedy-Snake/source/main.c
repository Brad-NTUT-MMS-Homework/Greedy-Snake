#include <stdio.h>

#include "../include/data.h"
#include "../include/draw.h"
#include "../include/input.h"
#include "../include/logic.h"
#include "../include/sleep.h"


int main() {
	Snake snake = { RIGHT, false, 1, 0 };
	BaseSetup baseSetup = { 20, 50, {20 / 2, 50 / 2} };

	while (!snake.gameover) {
		Draw(&snake, &baseSetup);
		Input(&snake);
		Logic(&snake, &baseSetup);
		sleep_ms(1000);
	}
}