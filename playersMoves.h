//checks for the last available empty slot in column chosen by player 1 and places the respective marker in said slot
void player1Move(int input, char (*board)[7]){
    for(int i = 0; i < 7; i++){
        if(*(*(board + i) + input - 1) != ' '){
            *(*(board + (i - 1)) + input - 1) = 'X';
            break;
        }
    }
}

//checks for the last available empty slot in column chosen by player 2 and places the respective marker in said slot
void player2Move(int input, char (*board)[7]){
    for(int i = 0; i < 7; i++){
        if(*(*(board + i) + input - 1) != ' '){
            *(*(board + (i - 1)) + input - 1) = 'O';
            break;
        }
    }
}

bool isColFull(int input, char (*board)[7]){
    if(*(*(board) + input - 1) != ' '){
        return true;
    } else {
        return false;
    }
}

