#include "triangle_routines.h"
#include <stdio.h>

#define NMOVES 36
#define NPEGS 15



int moves[NMOVES][3] =
{
    {0, 1, 3},
    {0, 2, 5},
    {1, 3, 6},
    {1, 4, 8},
    {2, 4, 7},
    {2, 5, 9},
    {3, 1, 0},
    {3, 4, 5},
    {3, 6, 10},
    {3, 7, 12},
    {4, 7, 11},
    {4, 8, 13},
    {5, 2, 0},
    {5, 4, 3},
    {5, 8, 12},
    {5, 9, 14},
    {6, 3, 1},
    {6, 7, 8},
    {7, 4, 2},
    {7, 8, 9},
    {8, 4, 1},
    {8, 7, 6},
    {9, 5, 2},
    {9, 8, 7},
    {10, 6, 3},
    {10, 11, 12},
    {11, 7, 4},
    {11, 12, 13},
    {12, 7, 3},
    {12, 8, 5},
    {12, 11, 10},
    {12, 13, 14},
    {13, 8, 4},
    {13, 12, 11},
    {14, 9, 5},
    {14, 13, 12},

};


int npegs(int board[]);
int valid_move(int board[], int move[]);
void make_move(int board[], int move[]);
void unmake_move(int board[], int move[]);
int solve(int board[]);

int main(void)
{
    int board[NPEGS];
    triangle_input(board);

    solve(board);

    return 0;
}


/* gives num of pegs on board */
int npegs(int board[])
{
    int i;
    int count;
    count = 0;

    for (i = 0; i < NMOVES; i++)
    {
        if (board[i] == 1)
        {
            count ++;
        }
    }

    return count;
}


/* returns 1 if valid move on given board, else 0 */

int valid_move(int board [], int move[])
{
    /* requirments for being able to make move */

    if (board[move[0]] == 1)
    {
        if (board[move[1]] == 1)
        {
            if (board[move[2]] == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

/* makes given move on a given board */
void make_move(int board[], int move[])
{
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
}

/* take back a move */
void unmake_move(int board[], int move[])
{
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;

}

/* solve the given board returning 1 if solvable and 0 if not */

int solve(int board[])
{
    int i;

    /* BASE CASE: check is board is solved */
    if (npegs(board) == 1)
    {
        return 1;
    }

    for (i = 0; i < NMOVES; i++)
    {
        /* check each move for validity on current board*/
        if (valid_move(board, moves[i]) == 1)
        {
            /* if yes we make move and run recursively ! */
            make_move(board, moves[i]);

            /* if our call leads to a base case we have solved with this move */
            if (solve(board) == 1)
            {
                triangle_print(board);
                unmake_move(board, moves[i]);
                return 1;
            }

            /* if move doesn't lead to solve, unmake move */
            unmake_move(board, moves[i]);
        }
    }
    /* no solution :( */
    return 0;
}