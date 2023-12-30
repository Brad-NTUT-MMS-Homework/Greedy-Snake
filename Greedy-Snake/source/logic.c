#include <stdlib.h>
#include <stdbool.h>

#include "../include/data.h"

int addLength(Snake *snake);

Position moveSnake(Snake *snake);

void Logic(Snake *snake, BaseSetup *baseSetup) {
    // Implementation of the Logic function
    // Use snake and baseSetup structures for game logic

    moveSnake(snake);

    if (snake->pos[0].xPos >= baseSetup->width || snake->pos[0].xPos < 0 ||
        snake->pos[0].yPos >= baseSetup->height || snake->pos[0].yPos < 0) {
        snake->gameover = true;
    }


    if (snake->pos[0].xPos == baseSetup->fruit.xPos &&
        snake->pos[0].yPos == baseSetup->fruit.yPos) {
        snake->score += 10;
        addLength(snake);
        baseSetup->fruit.xPos = rand() % baseSetup->width;
        baseSetup->fruit.yPos = rand() % baseSetup->height;
    }
}

int addLength(Snake *snake) {
    // Calculate the new length of the position array
    int newLength = snake->length + 1;

    // Reallocate memory to accommodate the new length of positions
    Position *newPositions = (Position *) realloc(snake->pos, newLength * sizeof(Position));
    // Memory allocation failed
    if (newPositions == NULL) {
        return -1; // Or any appropriate error code
    }

    // Update the snake's position array and length
    snake->pos = newPositions;
    snake->length = newLength;

    switch (snake->direction) {
        case UP:
            snake->pos[snake->length - 1].yPos =
                    snake->pos[snake->length - 2].yPos - 1;
            snake->pos[snake->length - 1].xPos =
                    snake->pos[snake->length - 2].xPos;
            break;

        case DOWN:
            snake->pos[snake->length - 1].yPos =
                    snake->pos[snake->length - 2].yPos + 1;
            snake->pos[snake->length - 1].xPos =
                    snake->pos[snake->length - 2].xPos;
            break;

        case LEFT:
            snake->pos[snake->length - 1].xPos =
                    snake->pos[snake->length - 2].xPos + 1;
            snake->pos[snake->length - 1].yPos =
                    snake->pos[snake->length - 2].yPos;
            break;

        case RIGHT:
            snake->pos[snake->length - 1].xPos =
                    snake->pos[snake->length - 2].xPos - 1;
            snake->pos[snake->length - 1].yPos =
                    snake->pos[snake->length - 2].yPos;
            break;
        default:
            break;
    }

    return 0; // Successful addition of length
}

Position moveSnake(Snake *snake) {
    int newX = snake->pos[0].xPos;
    int newY = snake->pos[0].yPos;

    // Update the head position based on the direction
    if (snake->direction == UP) {
        newY = snake->pos[0].yPos - 1;
    }
    if (snake->direction == DOWN) {
        newY = snake->pos[0].yPos + 1;
    }
    if (snake->direction == LEFT) {
        newX = snake->pos[0].xPos - 1;
    }
    if (snake->direction == RIGHT) {
        newX = snake->pos[0].xPos + 1;
    }

    // Update the body positions
    for (int i = snake->length - 1; i > 0; i--) {
        snake->pos[i].xPos = snake->pos[i - 1].xPos;
        snake->pos[i].yPos = snake->pos[i - 1].yPos;
    }

    // Set the new head position
    snake->pos[0].xPos = newX;
    snake->pos[0].yPos = newY;

    // Return the new head position
    Position newHeadPosition = {newX, newY};
    return newHeadPosition;
}

