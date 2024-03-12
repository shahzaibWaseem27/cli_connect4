#include <stdio.h>
#include <stdlib.h>
#include "./twoPlayer/twoPlayer.h"
#include "./onePlayer/onePlayer.h"

int main(){
    //board creation
    char board[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    printf("Welcome to a game of Connect 4\nPlease choose the mode you would like to play\n");
    printf("1: One player mode\n2: Two player mode\n");
    int mode;
    scanf("%d", &mode);
    char compMode;
    while(true){
        if(mode == 1){
            printf("Please choose the mode for the computer:\n");
            printf("a: computer prevents you from winning\nb: computer tries to win itself\n");
            scanf(" %c", &compMode);
            while(true){
                if(compMode == 'a'){
                    onePlayerMode(true, false, board);
                    return 0;
                } else if(compMode == 'b'){
                    onePlayerMode(false, true, board);
                    return 0;
                } else {
                    printf("Please enter either a or b\n");
                    scanf(" %c", &compMode);
                }
            }
        } else if(mode == 2){
            printf("Starting two player mode..\n");
            twoPlayerMode(board);
            break;
        } else {
            printf("Please enter a valid input\n");
            scanf("%d", &mode);
        }
    }

    return 0;
}