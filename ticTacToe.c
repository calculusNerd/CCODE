#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int option; 
int playerScore = 0, computerScore = 0;
char response;
int draw; // 1 if draw, 0 if no draw
int winner; // 1 if player, 0 if computer

void drawBoard();
void playerMove();
void computerMove();
int isDraw();
int checkWinner();
void initialInterface();
void startGame();
void resetBoard();

int main() {

    srand(time(0));

    while(1) {
        initialInterface();
        if(option == 1) {
            resetBoard();
            startGame();
        } else if(option == 2) {
            printf("\nYour score: %d", playerScore);
            printf("\nComputer score: %d", computerScore);
            while(1) {
                printf("\nPlay? (Y/N): ");
                scanf(" %c", &response);
                if(tolower(response) == 'y') {
                    resetBoard();
                    startGame(); 
                    break;
                } else if(tolower(response) == 'n') {
                    printf("\nThanks for playing!! Game made with Love <3");
                    exit(0);
                } else {
                    printf("\nInvalid choice. Try again: \n");
                }
            }
        } else {
            printf("\nInvalid choice. Try again: \n");
        }
    }

    return 0;
}

void drawBoard() {
    for(int i = 0; i < 9; i++) {
        if(i != 2 && i != 5 && i != 8) {
            printf(" %c |", board[i]);
        } else {
            if(i != 8) {
                printf(" %c \n", board[i]);
                printf("---+---+---\n");
            } else {
                printf(" %c \n", board[i]);
            }
        }
    }
}

void playerMove() {
    int move;
    while(1) {
        printf("\nEnter a move: ");
        scanf("%d", &move);
        if(move >= 1 && move <= 9 && board[move - 1] != 'X' && board[move - 1] != 'O') {
            board[move - 1] = 'X';
            drawBoard();
            printf("You played at position %d\n", move); 
            break;
        } else {
            printf("\nInvalid move. Please try again: \n");
        }
    }
}

void computerMove() {
    int move;
    while(1) {
        move = rand() % 9;
        if(board[move] != 'X' && board[move] != 'O') {
            board[move] = 'O';
            drawBoard();
            printf("The computer played at position %d\n", move + 1);
            break;
        } 
    }
}

int isDraw() {
    if(board[0] != '1' && board[1] != '2' && board[2] != '3' 
        && board[3] != '4' && board[4] != '5' && board[5] != '6' 
        && board[6] != '7' && board[7] != '8' && board[8] != '9') {
        return 1;
    } 
    return 0;
}

int checkWinner() {
    if((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
    (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
    (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
    (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
    (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
    (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
    (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
    (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') ) {
        playerScore++;
        return 1;
    } 
    if((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
    (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
    (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
    (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
    (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
    (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
    (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
    (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') ) {
        computerScore++;
        return 0;
    }
    return -1;
}

void initialInterface() {
    printf("++++++TIC TAC TOE++++++");
    printf("\n1. Play Game ");
    printf("\n2. See score ");
    printf("\nChoose an option: ");
    scanf("%d", &option);
}

void startGame() {
    while(1) {
        drawBoard();
        playerMove();
        winner = checkWinner();
        if(winner == 1) {
            printf("\n+++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nCongratulations!! You have Won!!!\n");
            return;
        } else if(winner == 0) {
            printf("\n+++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nYou lost :(\n");
            return;
        }
        draw = isDraw();
        if(draw == 1) {
            printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nThis game is a draw!!\n");
            return;
        }
        computerMove();
        winner = checkWinner();
        if(winner == 1) {
            printf("\n+++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nCongratulations!! You have Won!!!\n");
            return;
        } else if(winner == 0) {
            printf("\n+++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nYou lost :(\n");
            return;
        }
        draw = isDraw();
        if(draw == 1) {
            printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n");
            drawBoard();
            printf("\nThis game is a draw!!\n");
            return;
        }
    }
}

void resetBoard() {
    for(int index = 0; index < 9; index++) {
        board[index] = '1' + index;
    }
}


/*

    </> = Completed

    Future edits: 
    </> Add a draw and win detection system
    </> Add a score counter
    </> Add an interface to ask the user if they want to see the score or play game
    Add an interface inside play game to ask the user for the computer strength
    </> After a game ends, take the user to the initial interface
*/
