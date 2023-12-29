#ifndef DRAW_H_
#define DRAW_H_

#include "data.h" // Include necessary headers

void Draw(Snake *snake, BaseSetup *baseSetup);
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() printf("\033[2J\033[H")
#endif

#endif // DRAW_H_
