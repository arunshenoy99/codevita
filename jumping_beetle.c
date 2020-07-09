#include<stdio.h>

struct coord
{
    int row, col;
};


int main(void)
{
    int m, a, b, i, j, row,col, new_row, new_col;
    struct coord board[21][21];
    scanf("%d,%d,%d", &m, &a, &b);
    for(i = 1; i <= m;i++)
    {
        for(j = 1; j <= m; j++)
        {
            if (j == m)
            {
                scanf("%d,%d",&(board[i][j].row), &(board[i][j].col));
            }
            else
            {
                scanf("%d,%d;", &(board[i][j].row), &(board[i][j].col));
            }      
        }
    }
    scanf("%d,%d", &row, &col);
    for(i = 1; i <= (a*b); i++)
    {
        new_row = board[row][col].row ;
        new_col = board[row][col].col;
        row = new_row;
        col = new_col;
    }
    printf("%d,%d", row, col);
}