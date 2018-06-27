#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "tic-tac-toe.h"

void displayInstructions() {
  char answer;
  printf("\nShall we play a game? > ");
  scanf(" %c\n", &answer);

  while (tolower(answer) != 'y') {
    printf("How about a nice friendly game of tic-tac-toe? > ");
    scanf(" %c\n", &answer);
  }

  printf("\n\t\b\b*- Let's play Tic-Tac-Toe! -*\n\n");
  printf("*- A very boring game implemented in C -*\n\n");
  printf("Cells are numbered\n\n");
  printf("  1    2    3\n  4    5    6\n  7    8    9\n\n");
  printf("Choose a cell to play!\n\n");
  return;
}

void displayBoard(char board[SIDE][SIDE]) {
  printf("\n");
  printf("\t %c | %c | %c \n", board[0][0], board[1][0], board[2][0]);
  printf("\t --------- \n");
  printf("\t %c | %c | %c \n", board[0][1], board[1][1], board[2][1]);
  printf("\t --------- \n");
  printf("\t %c | %c | %c \n", board[0][2], board[1][2], board[2][2]);
  return;
}

void initBoard(char board[SIDE][SIDE]) {
  srand(time(NULL));

  for (int i = 0; i < SIDE; i++) {
    for (int j = 0; j < SIDE; j++) {
      board[i][j] = ' ';
    }
  }
  return;
}

int rowCrossed(char board[SIDE][SIDE]) {
  for (int i = 0; i < SIDE; i++) {
    if (board[i][0] == board[i][1]
      && board[i][1] == board[i][2]
      && board[i][0] != ' ') {
       return 1;
     }
  }
  return 0;
}

int columnCrossed(char board[SIDE][SIDE]) {
  for (int i = 0; i < SIDE; i++) {
    if (board[0][i] == board[1][i]
      && board[1][i] == board[2][i]
      && board[0][i] != ' ') {
        return 1;
      }
  }
  return 0;
}

int diagonalCrossed(char board[SIDE][SIDE]) {
  if (board[0][0] == board[1][1]
    && board[1][1] == board[2][2]
    && board[0][0] != ' ') {
      return 1;
  }

  if (board[0][2] == board[1][1]
    && board[1][1] == board[2][0]
    && board[0][2] != ' ') {
      return 1;
  }
  return 0;
}

int gameOver(char board[SIDE][SIDE]) {
  return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}

void declareWinner(int turn) {
  switch (turn) {
    case 1: {
      printf("PLAYER 1 has won, sorry PLAYER 2.\n");
      return;
    }
    case 2: {
      printf("PLAYER 2 has won, sorry PLAYER 1.\n");
      return;
    }
    default: {
      printf("It is a draw.\n");
      return;
    }
  }
}

void playGame(int turn) {
  char board[SIDE][SIDE];

  displayInstructions();
  initBoard(board);

  char moveIndex;
  int moveNumber = 0;
  int x, y;

  while (gameOver(board) == 0 && moveNumber < 9) {
    printf("\nEnter the number of the square you choose to play in > ");
    scanf(" %c", &moveIndex);

    int num = (int)moveIndex;
    switch (num) {
      case 1: {
        x = 0;
        y = 0;
        break;
      }
      case 2: {
        x = 1;
        y = 0;
        break;
      }
      case 3: {
        x = 2;
        y = 0;
        break;
      }
      case 4: {
        x = 0;
        y = 1;
        break;
      }
      case 5: {
        x = 1;
        y = 1;
        break;
      }
      case 6: {
        x = 2;
        y = 1;
        break;
      }
      case 7: {
        x = 0;
        y = 2;
        break;
      }
      case 8: {
        x = 1;
        y = 2;
        break;
      }
      case 9: {
        x = 2;
        y = 2;
        break;
      }
      default: {
        x = 0;
        y = 0;
      }
    }

    board[x][y] = turn % 2 == 1 ? PLAYER1MOVE : PLAYER2MOVE;

    if (turn % 2 == 1) {
      printf("\nPLAYER 1 has put a '%c' in cell %c\n", PLAYER1MOVE, num);
      printf("x - %d, y - %d", x, y);
      turn = PLAYER2;
    } else {
      printf("\nPLAYER 2 has put an '%c' in cell %c\n", PLAYER2MOVE, num);
      printf("x- %d, y-%d", x, y);
      turn = PLAYER1;
    }

    displayBoard(board);
    moveNumber += 1;
  }

  if (gameOver(board) == 0 && moveIndex == SIDE * SIDE) {
    printf("It's a draw\n");
  } else {
    if (turn == PLAYER1) {
      turn = PLAYER2;
    } else if (turn == PLAYER2) {
      turn = PLAYER1;
    }
    declareWinner(turn);
  }
  return;
}

int main() {
  playGame(PLAYER1);
  return 0;
}