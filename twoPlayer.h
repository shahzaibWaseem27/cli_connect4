#include <stdio.h>
#include <stdbool.h>
#include "playersMoves.h"
#include "matchEnd.h"
#include "display.h"

void twoPlayerMode(char (*board)[7]){
//display board
    displayBoard(board);
//declare input to be used by players
    int input;
//keep going in a loop until the match ends
    while(true){
        //player 1 move prompt
        printf("Player 1 move\n");
        scanf("%d", &input);
        //keep taking input until player enters valid input
        while(true){
            if(input >= 1 && input <= 7){
                if(isColFull(input, board)){
                    printf("Column is full. Please choose another column\n");
                    printf("Player 1 move\n");
                    scanf("%d", &input);
                } else {
                    //make move, then exit this loop
                    player1Move(input, board);
                    break;
                }
            } else {
                //else prompt user again, and start loop again
                printf("Invalid move - input should be from 1 to 7\n");
                printf("Player 1 move\n");
                scanf("%d", &input);
            }
        }
        //display boards
        displayBoard(board);
        //if player 1 wins, end game
        if(checkMatchWin(input, board)){
            printf("Player 1 Wins!");
            break;
        }
        //if match is a draw, end game
        if(checkMatchDraw(board)){
            printf("All columns are full. Game over\n");
            break;
        }
        //repeat for player 2, and go over loop again
        printf("Player 2 move\n");
        scanf("%d", &input);
        while(true){
            if(input >= 1 && input <= 7){
                if(isColFull(input, board)){
                    printf("Column is full. Please choose another column\n");
                    printf("Player 2 move\n");
                    scanf("%d", &input);
                } else {
                    //make move, then exit this loop
                    player2Move(input, board);
                    break;
                }
            } else {
                //else prompt user again, and start loop again
                printf("Invalid move - input should be from 1 to 7\n");
                printf("Player 2 move\n");
                scanf("%d", &input);
            }
        }
        displayBoard(board);
        //if player 2 wins, end game
        if(checkMatchWin(input, board)) {
            printf("Player 2 Wins!");
            break;
        }
        //if match is a draw, end game
        if(checkMatchDraw(board)){
            printf("All columns are full. Game over\n");
            break;
        }
    }
}


