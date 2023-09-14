#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

// Function responsible for obtaining the winner of a row.
char get_winner_in_row (char board[3][3], char winner){
    bool aux;

    for (unsigned int row = 0; row < 3; ++row){
        aux = true;
        for (unsigned int colum = 0; colum < 2; ++colum){
            aux = aux && (board[row][colum] == board[row][colum+1]);

            if (colum == 1 && aux)
                if (board[row][colum+1] != '-') winner = board[row][colum+1];
        }
        if (winner != '-') break;
    }

    return winner;
}

// Function responsible for obtaining the winner of a column.
char get_winner_in_column (char board[3][3], char winner){
    bool aux;

    for (unsigned int colum = 0; colum < 3; ++colum){
        aux = true;
        for (unsigned int row = 0; row < 2; ++row){
            aux = aux && (board[row][colum] == board[row+1][colum]);

            if (row == 1 && aux)
                if (board[row+1][colum] != '-') winner = board[row+1][colum];
        }
        if(winner != '-') break;
    }

    return winner;
}

// Function responsible for obtaining the winner of a diagonal.
char get_winner_in_diagonal (char board[3][3], char winner){
    bool aux = true;

    for (unsigned int rocol = 0; rocol < 2; ++rocol){
        aux = aux && (board[rocol][rocol] == board[rocol+1][rocol+1]);

        if (rocol == 1 && aux)
            if (board[rocol][rocol] != '-') winner = board[rocol][rocol];
    }

    aux = true;
    for (unsigned int row = 0, colum = 2; row < 2 && colum > 0; ++row,--colum){
        aux = aux && (board[row][colum] == board[row+1][colum-1]);
        
        if (row == 1 && aux)
            if (board[row][colum] != '-') winner = board[row][colum];
    }

    return winner;
}

// Function responsible for giving the winner if there is.
char get_winner(char board[3][3])
{
    char winner = '-';

    // Obtaining the winner in any of the possible cases.
    winner = get_winner_in_row(board, winner);
    winner = get_winner_in_column(board, winner);
    winner = get_winner_in_diagonal(board, winner);

    return winner;
}

// Function responsible for knowing if there is a free cell.
bool has_free_cell(char board[3][3])
{
    bool free_cell = false;

    for (unsigned int row = 0; row < 3 && !free_cell; ++row){
        for (unsigned int colum = 0; colum < 3 && !free_cell; ++colum){
            free_cell = free_cell || (board[row][colum] == '-');
        }
    }

    return free_cell;
}

int main(void)
{
    printf("TicTacToe: \n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
