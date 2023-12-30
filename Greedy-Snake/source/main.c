#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include "../include/data.h"
#include "../include/draw.h"
#include "../include/input.h"
#include "../include/logic.h"
#include "../include/sleep.h"

#define WIDTH 20
#define HEIGHT 10
#define INITIAL_LENGTH 1

int main() {
    srand(time(NULL));

    Position *pos = malloc(INITIAL_LENGTH * sizeof(Position));
    pos->xPos = rand() % WIDTH ; pos->yPos = rand() % HEIGHT;

    Snake snake = {RIGHT, pos, false, 1, 0};
    BaseSetup baseSetup = {
            WIDTH, HEIGHT, {WIDTH / 2, HEIGHT / 2}
    };

    while (!snake.gameover) {
        Draw(&snake, &baseSetup);
        Input(&snake);
        Logic(&snake, &baseSetup);
        sleep_ms(1000);
    }
}
