#include <stdlib.h>
#include <stdio.h>
//there is only one board created in the entire program - takes the board as argument and displays it
void onePdisplayBoard(char (*board)[7]){
    printf("1 2 3 4 5 6 7\n\n");
    int colCount = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            colCount++;
            printf("%c ", *(*(board + i) + j)); //equivalent to board[i][j]
            if(colCount == 7){
                colCount = 0;
                printf("\n");
            }
        }
    }
}