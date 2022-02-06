//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>


void fieldDraw(int width, int lenght, int posBoardCenterPlayer1, int posBoardCenterPlayer2, int posBallX, int posBallY) {
    for (int y = 0; y<=width; y++) {
        for (int x = 0; x<=lenght; x++) {
                if (((x==0) || (x==lenght))){ //отрисовка горизонтальных черт
                       printf("%c",'|');
                    if (x==80)
                        printf("%c", '\n');
                continue;
            }
            if((y==0)||(y==width)){ //отрисовка горизонтальных черты
                printf("%c",'-');
                continue;
            }
            if ((y == posBallY) && (x == posBallX)) { // отрисовка мяча
                printf("o");
                continue;
            }
            if(x==lenght) { //абзац в конце строки (лишнее ибо первое условие)
                printf("%c",'\n');
                continue;
            }
            if (((y == posBoardCenterPlayer1) || (y == posBoardCenterPlayer1+1) || (y == posBoardCenterPlayer1-1)) && x == 1) { // отрисовка ракетки 1ого игрока
                printf("]");
                continue;
            }
            if (((y == posBoardCenterPlayer2) || (y == posBoardCenterPlayer2+1) || (y== posBoardCenterPlayer2-1)) && x == lenght-1) { // отрисовка ракетки 2ого игрока
                printf("[");
                continue;
            }
            if((y!=0)&&(y!=width)) { // заполнение поля отрисовки
                printf("%c",' ');
            }
        }
    }
}

int nextBallPosX(int posBall, int prevBallPos, int width) { // след позиция по Х
    if (posBall == (width-1)){
        return (posBall-1); // left
    }
    if (posBall == 1){
        return (posBall+1); // right
    }
    if (prevBallPos > posBall) {
        return (posBall-1); // left
    }
    if (prevBallPos < posBall) {
        return (posBall+1); // right
    }
    return 0;
}

int nextBallPosY(int posBall, int prevBallPos, int width) { // след позиция по Y
    
    if(posBall == 1) {
        return (posBall+1); // down
    }
    if (posBall == width) {
         return (posBall-1); // up
    }
    if (prevBallPos > posBall) {
        return (posBall-1); // up
    }
    if (prevBallPos < posBall){
        return (posBall+1); // down
    }
    return (posBall);
}


int shiftPosYplayer1(int pos, int widthY) { // смешение центра ракетки 1ого игрока
    char input = ' ';
    printf("Player 1 turn:");
    scanf("%c", &input);
    getc(stdin);
    if (input == '\n') {
        return pos;
    }
    if ((input == 'a') && (pos != 1)) {
        return (pos-1);
    }
    if ((input == 'z') && (pos != widthY)) {
        return (pos+1);
    }
    return pos;
}

int shiftPosYplayer2(int pos, int widthY) { // смещение ракетки 2ого игрока
        char input = ' ';
        printf("Player 2 turn:");
        scanf("%c", &input);
        getc(stdin);
        if (input == '\n') {
            return pos;
            
        }
        if ((input == 'k') && (pos != 1)) {
            return (pos-1);
        }
        if ((input == 'm') && (pos != widthY)) {
            return (pos+1);
        }
        return pos;
    }

int main(){
    int posBallX = 0, posBallY= 0, prevPosBallX = 0, prevPosBallY = 0, nextPosBallX =0, nextPosBallY = 0; // позиция мяча
    int posBoardCenterPlayer1 = 0, posBoardCenterPlayer2 = 0; // позиции ракеток
    int widthY = 25, lenghtX = 80; // размеры поля
    int score1 = 0, score2 = 0; // очки игроков
    posBoardCenterPlayer2 = posBoardCenterPlayer1 = posBallY = widthY/2;
    posBallX = lenghtX/2;
    prevPosBallX = posBallX-1;
    prevPosBallY = posBallY-1;
    do {
        // printf("nextX:%d nextY:%d posX:%d posY:%d play1:%d play2:%d\n", posBallX,posBallY,prevPosBallX, prevPosBallY, posBoardCenterPlayer1, posBoardCenterPlayer2);
        // getc(stdin); отладка
        printf("Score %d ; %d\n", score1, score2);
        fieldDraw(widthY+1, lenghtX, posBoardCenterPlayer1, posBoardCenterPlayer2, posBallX, posBallY);
        nextPosBallX = nextBallPosX(posBallX, prevPosBallX, lenghtX);
        nextPosBallY = nextBallPosY(posBallY, prevPosBallY, widthY);
        prevPosBallY=posBallY;
        prevPosBallX=posBallX;
        posBallX=nextPosBallX;
        posBallY=nextPosBallY;
        posBoardCenterPlayer1 = shiftPosYplayer1(posBoardCenterPlayer1,widthY); // считывание команд управления 1 игрока
        posBoardCenterPlayer2 = shiftPosYplayer2(posBoardCenterPlayer2,widthY); // считывание команд управления 2 игрока
        if (prevPosBallX == 1) { // проверка совпадения левой доски и мяча
            if ((prevPosBallY != posBoardCenterPlayer1)||(prevPosBallY != posBoardCenterPlayer1-1)||(prevPosBallY != posBoardCenterPlayer1+1)) {
                score2++;
                posBoardCenterPlayer2 = posBoardCenterPlayer1 = posBallY = widthY/2;
                posBallX = lenghtX/2;
                prevPosBallX = posBallX-1;
                prevPosBallY = posBallY-1;
            }
        }
        if (prevPosBallX == (lenghtX-1)) { // проверка совпадения правой доски и мяча
            if ((prevPosBallY != posBoardCenterPlayer1)||(prevPosBallY != posBoardCenterPlayer2-1)||(prevPosBallY != posBoardCenterPlayer2+1)) {
                score1++;
                posBoardCenterPlayer2 = posBoardCenterPlayer1 = posBallY = widthY/2;
                posBallX = lenghtX/2;
                prevPosBallX = posBallX+1;
                prevPosBallY = posBallY+1;
            }
        }
        system ("clear");
    } while((score1 < 21) && (score2 < 21));
    return 0;
}
