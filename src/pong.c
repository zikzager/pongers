//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
int fieldDraw(25/*widgth*/, 80/*lenght*/, posBoardCenterPlayer1, posBoardCenterPlayer1, posBallX, poBallY) {
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
            if((y!=0)&&(y!=25)) { //ПРОБЕЛЫ
                printf("%c",' ');
                
            }
        }
    }
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


