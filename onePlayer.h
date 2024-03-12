#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "onePdisplay.h"
#include "playerAndCompMoves.h"

void onePlayerMode(bool preventWin, bool winItself, char (*board)[7]){
    int input;
    //display board
    onePdisplayBoard(board);
    while(true){
        printf("Your move\n");
        scanf("%d", &input);
            while(true){
                if(input >= 1 && input <= 7){
                    if(isColFull(input, board)){
                        printf("Column is full. Please choose another column\n");
                        printf("Your move\n");
                        scanf("%d", &input);
                    } else {
                        //make move, then exit this loop
                        playerMove(input, board);
                        printf("Player move is in column: %d\n", input);
                        break;
                    }
                } else {
                    //else prompt user again, and start loop again
                    printf("Invalid move - input should be from 1 to 7\n");
                    printf("Your move\n");

                    scanf("%d", &input);
                }
            }
            //display board
            onePdisplayBoard(board);
            //if player 1 wins, end game
            if(onePcheckMatchWin(input, board)){
                printf("You Win!");
                break;
            }
            //if match is a draw, end game
            if(onePcheckMatchDraw(board)){
                printf("All columns are full. Game over\n");
                break;
            }
            //calculate computer move
            int bestMove = findBestMove(input, board);
            //make computer move
            compMove(bestMove, board);
            //display board
            onePdisplayBoard(board);
            //if computer wins, end game
            if(onePcheckMatchWin(bestMove, board)){
                printf("Computer Wins!");
                break;
            }
            //if match is a draw, end game
            if(onePcheckMatchDraw(board)){
                printf("All columns are full. Game over\n");
                break;
            }
    }
}





