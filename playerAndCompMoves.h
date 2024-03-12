#include <stdlib.h>
#include "onePmatchEnd.h"
//checks for the last available empty slot in column chosen by player 1 and places the respective marker in said slot
void playerMove(int input, char (*board)[7]){
    for(int i = 0; i < 7; i++){
        if(*(*(board + i) + input - 1) != ' '){
            *(*(board + (i - 1)) + input - 1) = 'X';
            break;
        }
    }
}

//checks for the last available empty slot in column chosen by computer and places the respective marker in said slot
void compMove(int input, char (*board)[7]){
    for(int i = 0; i < 7; i++){
        if(*(*(board + i) + input - 1) != ' '){
            *(*(board + (i - 1)) + input-1) = 'O';
            break;
        }
    }
}



// bool thinkAhead(int input, int rowPos, char (*board)[7]){
//     //make a trial move for the opponent in the column they last their move in
//     playerMove(input, board);

//     //check the row in which trial move was made
//     for(int j = 0; j < 4; j++){
//         if(*(*(board + rowPos - 1) + j) == 'X'){
//             if(*(*(board + rowPos - 1) + j + 1) == 'X'){
//                 if(*(*(board + rowPos - 1) + j + 2) == 'X'){
//                     if(*(*(board + rowPos - 1) + j + 3) == 'X'){
//                         //undo the trial move
//                         undoMove(input, board);
//                         //block that win by making computer move there
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

int findBestMove(int input, char (*board)[7]){
    //check the column in which player made move
    for(int i = 0; i < 5; i++){
        if(*(*(board + i) + input - 1) == 'X'){
            if(*(*(board + i + 1) + input - 1) == 'X'){
                return input;
            }
        }
    }
}
