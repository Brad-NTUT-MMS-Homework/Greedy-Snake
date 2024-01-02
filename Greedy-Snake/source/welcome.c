#include <stdio.h>

void Welcome()
{
    puts("貪食蛇遊戲\
    操作方法:\n\
    使用方法:WASD控制方向(上、下、左、右)\
    按下Enter鍵開始遊戲!\n");

    // while(getchar() != '\n')
    switch (getchar())
    {
    case '\x0D':
    case '13':

        break;

    default:
        return 0;
        break;
    }
}