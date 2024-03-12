#include <stdlib.h>
bool onePcheckMatchDraw(char (*board)[7]){
    int fullColCount = 0;
    for(int j = 0; j < 7; j++){
        if(*(*(board) + j) != ' '){
            fullColCount++;
        }
    }
    if(fullColCount == 7){
        return true;
    }
    return false;
}

//checks the corresponding row, column, and diagonals for the move made
bool onePcheckMatchWin(int input, char (*board)[7]){
    //vertical check
    for(int i = 0; i < 3; i++){
        
            //vertical check player 1
            if(*(*(board + i) + input - 1) == 'X'){
                if(*(*(board + i + 1) + input - 1) == 'X'){
                    if(*(*(board + i + 2) + input - 1) == 'X'){
                        if(*(*(board + i + 3) + input - 1) == 'X'){
                            return true;
                        }
                    }
                }
            }
            //vertical check player 2
            if(*(*(board + i) + input - 1) == 'O'){
                if(*(*(board + i + 1) + input - 1) == 'O'){
                    if(*(*(board + i + 2) + input - 1) == 'O'){
                        if(*(*(board + i + 3) + input - 1) == 'O'){
                            return true;
                        }
                    }
                }
            }
        
    }
    //horizontal check
    int rowPos;

    for(int i = 0; i < 6; i++){
        if(*(*(board + i) + input - 1) != ' '){
            rowPos = i;
            break;
        }
    }
    for(int j = 0; j < 4; j++){
        
            //horizontal check player 1
            if(*(*(board + rowPos) + j) == 'X'){
                if(*(*(board + rowPos) + j + 1) == 'X'){
                    if(*(*(board + rowPos) + j + 2) == 'X'){
                        if(*(*(board + rowPos) + j + 3) == 'X'){
                            return true;
                        }
                    }
                }
            }
            //horizontal check player 2
            if(*(*(board + rowPos) + j) == 'O'){
                if(*(*(board + rowPos) + j + 1) == 'O'){
                    if(*(*(board + rowPos) + j + 2) == 'O'){
                        if(*(*(board + rowPos) + j + 3) == 'O'){
                            return true;
                        }
                    }
                }
            }
        
    }
//diagonal check
    int rowEdge;
    int colEdge;
    //get the coordinates of the bottom left edge of diagonal in which move was made
    int p = 1;
    int q = 1;
    while(true){
        if(rowPos + p > 5 || input - 1 - q < 0) {
            rowEdge = rowPos + p - 1;
            colEdge = input - 1 - q + 1;
            break;
        }
        p++;
        q++;
    }
    //start at the edge, and check for 4 consecutive same inputs in diagonals

        // printf("The element on the edge of this diagonal is as follows:\n");
        // printf("%c", *(*(board + rowEdge) + colEdge));
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(*(*(board + rowEdge - i) + colEdge + j) == 'X' && (rowEdge - i >= 0 || colEdge + j < 7)){
                if(*(*(board + rowEdge - i - 1) + colEdge + j + 1) == 'X' && (rowEdge - i - 1 >= 0 || colEdge + j + 1 < 7)){
                    if(*(*(board + rowEdge - i - 2) + colEdge + j + 2) == 'X' && (rowEdge - i - 2 >= 0 || colEdge + j + 2 < 7)){
                        if(*(*(board + rowEdge - i - 3) + colEdge + j + 3) == 'X' && (rowEdge - i - 3 >= 0 || colEdge + j + 3 < 7)){
                            return true;
                        }
                    }
                } 
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(*(*(board + rowEdge - i) + colEdge + j) == 'O' && (rowEdge - i >= 0 || colEdge + j < 7)){
                if(*(*(board + rowEdge - i - 1) + colEdge + j + 1) == 'O' && (rowEdge - i - 1 >= 0 || colEdge + j + 1 < 7)){
                    if(*(*(board + rowEdge - i - 2) + colEdge + j + 2) == 'O' && (rowEdge - i - 2 >= 0 || colEdge + j + 2 < 7)){
                        if(*(*(board + rowEdge - i - 3) + colEdge + j + 3) == 'O' && (rowEdge - i - 3 >= 0 || colEdge + j + 3 < 7)){
                            return true;
                        }
                    }
                } 
            }
        }
    }


//get the coordinates of the top left edge of diagonal in which move was made
    int r = 1;
    int s = 1;
    while(true){
        if(rowPos - r < 0 || input - 1 - s < 0){
            rowEdge = rowPos - r + 1;
            colEdge = input - 1 - s + 1;
            break;
        }
        r++;
        s++;
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(*(*(board + rowEdge + i) + colEdge + j) == 'X' && (rowEdge + i < 6 || colEdge + j < 7)){
                if(*(*(board + rowEdge + i + 1) + colEdge + j + 1) == 'X'&& (rowEdge + i  + 1 < 6 || colEdge + j  + 1< 7)){
                    if(*(*(board + rowEdge + i + 2) + colEdge + j + 2) == 'X'&& (rowEdge + i + 2 < 6 || colEdge + j + 2 < 7)){
                        if(*(*(board + rowEdge + i + 3) + colEdge + j + 3) == 'X'&& (rowEdge + i + 3 < 6 || colEdge + j + 3 < 7)){
                            return true;
                        }
                    }
                } 
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(*(*(board + rowEdge + i) + colEdge + j) == 'O' && (rowEdge + i < 6 || colEdge + j < 7)){
                if(*(*(board + rowEdge + i + 1) + colEdge + j + 1) == 'O' && (rowEdge + i + 1 < 6 || colEdge + j + 1 < 7)){
                    if(*(*(board + rowEdge + i + 2) + colEdge + j + 2) == 'O' && (rowEdge + i + 2 < 6 || colEdge + j + 2< 7)){
                        if(*(*(board + rowEdge + i + 3) + colEdge + j + 3) == 'O' && (rowEdge + i  + 3 < 6 || colEdge + j + 3 < 7)){
                            return true;
                        }
                    }
                } 
            }
        }
    }

    return false;
}