#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ticboard(int table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d  ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == 0)
            {
                printf("*   ");
            }
            else if (table[i][j] == 1)
            {
                printf("O   ");
            }
            else if (table[i][j] == 2)
            {
                printf("X   ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
void tic_tac_toe()
{
    int board[3][3];
    char move[1000];
    int a = 1;
    int p = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
    }
    while (1)
    {
        printf("To stop playing tic-tac-toe, type: s\n");
        int draw = 9;
        draw = 9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] != 0)
                {
                    draw--;
                }
            }
        }
        if (draw == 0)
        {
            printf("\nIt's a draw!\n\n");
            break;
        }
        printf("\nAvailable moves:\n\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] == 0)
                {
                    if (i == 0)
                        printf("a%d\n", j + 1);
                    else if (i == 1)
                        printf("b%d\n", j + 1);
                    else if (i == 2)
                        printf("c%d\n", j + 1);
                }
            }
        }
        printf("\n");
        printf("   A   B   C\n");
        ticboard(board);
        if (a % 2 != 0)
            p = 1;
        else
            p = 2;
        printf("Player %d move\n", p);
        fgets(move, 1000, stdin);
        if (move[0] == 's')
        {
            return;
        }
        a++;
        switch (move[0])
        {
        case 'a':
        case 'A':
            if (move[1] == '1')
            {
                if (board[0][0] == 0)
                    board[0][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves. A\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][0] == 0)
                    board[1][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][0] == 0)
                    board[2][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        case 'b':
        case 'B':
            if (move[1] == '1')
            {
                if (board[0][1] == 0)
                    board[0][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][1] == 0)
                    board[1][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][1] == 0)
                    board[2][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        case 'c':
        case 'C':
            if (move[1] == '1')
            {
                if (board[0][2] == 0)
                    board[0][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][2] == 0)
                    board[1][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][2] == 0)
                    board[2][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        default:
            printf("Unavailable move, please choose one of available moves.\n");
            a--;
            break;
        }
        if ((draw != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][1] != 0) || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != 0) || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
        else if ((draw != 0 && board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] != 0) || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != 0) || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
        else if ((draw != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0) || (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
    }
}
int main()
{
    tic_tac_toe();
}