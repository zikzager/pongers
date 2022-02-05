//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
int fieldDraw(25/*widgth*/, 80/*lenght*/) {
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
            }
            if(x==80) { //абзац в конце строки
                printf("%c",'\n');
                continue;
            }
            if((y!=0)&&(y!=25)) { //ПРОБЕЛЫ
                printf("%c",' ');
                
            }
        }
    }
}


cd .
