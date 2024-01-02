#include <stdio.h>
#include <stdlib.h>


void Welcome() {
    puts("貪食蛇遊戲！\n\
    學妹被你的敵人，也就是阿明，搶走了，這時學妹提出一個荒謬的解法：\n\
    那就玩貪食蛇吧!如果誰的分數越高，我就和他走！\n\
    雖然這實在是太荒謬，不過看在學妹的份上，你還是接受了\n\
    操作方法：\n\
    利用WASD控制方向（上、下、左、右）\n\
    按下Enter鍵開始爭奪遊戲！");

    // while(getchar() != '\n')
    switch (getchar()) {
        case '\n':
            break;

        default:
            exit(0);
            break;
    }
}

void End() {
    puts("\n\n\n\n\t\t游戲結束 :(");
    puts("\n\t\t你很傷心，因為這代表你和學妹的戀情也到此為止");
    puts("\n\t\t請按任意鍵結束遊戲");
    getchar();
}