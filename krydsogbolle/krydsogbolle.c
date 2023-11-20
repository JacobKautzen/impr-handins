#include <stdio.h>
#include <stdlib.h>
#include "krydsogbolle.h"

#define NO_WINNER -1

void kryds_og_bolle(void) {
    // Create an arena
    cell arena[3][3] = {{empty, empty, empty},
                        {empty, empty, empty},
                        {empty, empty, empty}};

    int whose_turn = 0;  // Who should perform the next move: Player 0 or Player/Computer 1?
    int the_winner;
    do {
        int move_x, move_y;
        scan_move(&move_x, &move_y);

        update_arena(arena, move_x, move_y, whose_turn);

        print_arena(arena);

        the_winner = winner(arena);

        // Switch to the other player.
        whose_turn = (whose_turn == 0) ? 1 : 0;
    } while (the_winner == NO_WINNER);

    // Print who won (the_winner).
    printf("Player %d won!\n", the_winner);

}


void scan_move(int *x, int *y) {
    printf("Indtast move:\n>");
    scanf(" %d", x);
    scanf(" %d", y);
    if (*x < 0 || *x > 2 || *y < 0 || *y > 2) {
        printf("Invalid move, out of bounds: %d, %d\n", *x, *y);
        exit(-1);
    }
}

void update_arena(cell arena[][3], int x, int y, int player) {
    if (arena[x][y] != empty) {
        printf("Invalid move, already taken: %d, %d\n", x, y);
        exit(-1);
    }
    if (player == 0) {
        arena[x][y] = kryds;
    } else {
        arena[x][y] = bolle;
    }
}

void print_cell(cell c) {
    switch (c) {
        case empty:
            printf("-");
            break;
        case kryds:
            printf("X");
            break;
        case bolle:
            printf("O");
            break;
        default:
            printf("\nInvalid cell.");
            exit(-1);
    }
}

void print_arena(cell arena[][3]) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            print_cell(arena[x][y]);
        }
        printf("\n");
    }
}

int player_of_cell(cell c) {
    switch (c) {
        case kryds:
            return 0;
        case bolle:
            return 1;
        case empty:
        default:
            return -1;
    }

}

int winner(cell arena[][3]) {
    // Check horisontal lines
    for (int x = 0; x < 3; x++) {
        if (arena[x][0] == arena[x][1] && arena[x][0] == arena[x][2] && arena[x][0] != empty) {
            return player_of_cell(arena[x][0]);
        }
    }

    // Check vertical lines
    for (int y = 0; y < 3; y++) {
        if (arena[0][y] == arena[1][y] && arena[0][y] == arena[2][y] && arena[0][y] != empty) {
            return player_of_cell(arena[0][y]);
        }
    }

    // Check diagonals
    if (arena[0][0] == arena[1][1] && arena[0][0] == arena[2][2] && arena[0][0] != empty) {
        return player_of_cell(arena[0][0]);
    }
    if (arena[2][0] == arena[1][1] && arena[2][0] == arena[0][2] && arena[2][0] != empty) {
        return player_of_cell(arena[2][0]);
    }

    return NO_WINNER;
}

