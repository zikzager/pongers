//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
int fieldDraw(25/*widgth*/, 80/*lenght*/, int posBoardCenterPlayer1, int posBoardCenterPlayer2, int posBallX, int posBallY) {
    for (int y = 0; y<=25; y++) {
        for (int x = 1; x<=80; x++) {
                if (((x==1) || (x==80)) && (y!=0)){ //отрисовка горизонтальных черт
                    printf("%c",'|');
                    if (x==80)
                        printf("%c", '\n');
                continue;
            }
            if((y==0)||(y==25)){ //отрисовка горизонтальных черты
                printf("%c",'_');
                continue;
            }
            if(x==80) { //абзац в конце строки (лишнее ибо первое условие)
                printf("%c",'\n');
                continue;
            }
            if (((y == posBoardCenterPlayer1) || (y == posBoardCenterPlayer1+1) || (y == posBoardCenterPlayer1-1)) && x == 2) {
                printf("]");
                continue;
            }
            if (((y == posBoardCenterPlayer2) || (y == posBoardCenterPlayer2+1) || (y== posBoardCenterPlayer2-1)) && x == 79) {
                printf("[");
                continue;
            }
            if((y!=0)&&(y!=25)) { //ПРОБЕЛЫ
                printf("%c",' ');
                
            }
        }
    }
}

int nextBallPosX(int posBall, int prevBallPos, width) {юб // след позиция по Х
    if ((prevBallPos > posBall) || posBall == (width-1)) {
        return (posBall-1); // left
    }
    if ((prevBallPosX < posBallX) || posBall == (1)) {
        return (posBall+1); // right
    }
}

int nextBallPosY(int posBall, int prevBallPos, hight) { // след позиция по Y
    
    if ((prevBallPos > posBall) || posBall == (hight-1)) {
        return (posBall-1);// up
    }
    if (prevBallPos < posBall) || (posBall == 1){
        return (posBall+1);// down
    }
    return (posBall);
}


int shiftPosYplayer1(int pos) {
    getc(stdin); //фитрация ввода после  enter
    char endCheck='\n';
    scanf("%c%c", input, endCheck);
    if (input == '\n')
        return pos;
    if (endCheck=='\n'){
        if (input == 'a')
            return (pos-1);
        if (input == 'z') {
            return (pos+1);
        }
    } else {
        return pos;
    }
}

int shiftPosYplayer2(int pos) {
    getc (stdin); //фитрация ввода после  enter
    char endCheck='\n';
    scanf("%c%c", input, endCheck);
    if (input == '\n')
        return pos;
    if (endCheck=='\n'){
        if (input == 'k')
            return (pos-1);
        if (input == 'm') {
            return (pos+1);
        }
    } else {
        return pos;
    }
}


