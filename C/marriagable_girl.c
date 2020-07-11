#include<stdio.h>
#include<stdlib.h>

struct girl
{
    int row,col,qualities;
};

struct girl verify(int*, int, int, int, int);


int main(void)
{
    int n,m,i,j,count=0, max = 0, d1, d2, temp1, temp2, temp3;
    scanf("%d %d", &n, &m);
    int *grid = (int*)malloc(sizeof(int)*n*m);
    struct girl *mg = (struct girl*)malloc(sizeof(struct girl)*n*m);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", (grid + i*m + j));
        }
    }
    *grid = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {    
            if(i == 0 && j == 0)
            {
                continue;
            }
            if(*(grid + i*m + j) == 1)
            {
                *(mg + count) = verify(grid, i, j, m, n);
                count++;
            }
        }
    }
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if ((*(mg + j)).qualities < (*(mg + j + 1)).qualities)
            {
                temp1 = (*(mg + j)).qualities;
                temp2 =(*(mg + j)).row;
                temp3 = (*(mg + j)).col;
                (*(mg + j)).qualities = (*(mg + j + 1)).qualities;
                (*(mg + j)).row = (*(mg + j + 1)).row;
                (*(mg + j)).col = (*(mg + j + 1)).col;
                (*(mg + j + 1)).qualities = temp1;
                (*(mg + j + 1)).row = temp2;
                (*(mg + j + 1)).col = temp3;
            }
        }
    }
    max = 0;
    for (i = 1; i < count; i++)
    {
        if((*(mg + i)).qualities == (*(mg + max)).qualities)
        {
            d1 = (*(mg + max)).row + (*(mg + max)).col;
            d2 = (*(mg + i)).row + (*(mg + i)).col;
            if (d1 > d2)
            {
                max = i;
            }
            else if (d2 > d1);
            else 
            {
                printf("Polygamy not allowed!");
                return 0;
            }
        }
    }
    printf("%d:%d:%d", ((*(mg + max)).row + 1), ((*(mg + max)).col + 1), (*(mg + max)).qualities);
}

struct girl verify(int *grid, int i, int j, int m, int n)
{
    struct girl mg;
    mg.row = i;
    mg.col = j;
    if(i == 0)
    {
        if(j == m - 1)
        {
            mg.qualities = *(grid + i*m + (j-1)) + *(grid +(i+1)*m + (j-1)) + *(grid + (i+1)*m + (j));
        }
        else
        {
            mg.qualities = *(grid + i*m + (j-1)) + *(grid + (i+1)*m + (j-1)) + *(grid + (i+1)*m + j) + *(grid + (i+1)*m + (j+1)) + *(grid + i*m + (j+1));
        }
    }
    else if (i == n - 1)
    {
        if (j == 0)
        {
            mg.qualities = *(grid + (i-1)*m + j) + *(grid + i*m + (j+1)) + *(grid + (i-1)*m + (j+1));
        }
        else if (j == m - 1)
        {
            mg.qualities = *(grid + (i-1)*m + (j-1))+ *(grid + (i-1)*m + j) + *(grid + i*m + (j-1));
        }
        else
        {
            mg.qualities = *(grid + (i-1)*m + j) + *(grid + (i-1)*m + (j-1)) + *(grid + i*m + (j-1)) + *(grid + i*m + (j+1));
        }
    }
    else
    {
        if (j == 0)
        {
            mg.qualities = *(grid + (i-1)*m + j) + *(grid + i*m + (j+1)) + *(grid + (i+1)*m + j) + *(grid + (i+1)*m + (j+1)) + *(grid + (i-1)*m + (j+1));
        }
        else if (j == m - 1)
        {
            mg.qualities = *(grid + (i-1)*m + (j-1))+ *(grid + (i-1)*m + j) + *(grid + i*m + (j-1)) + *(grid + (i+1)*m + (j-1)) + *(grid + (i+1)*m + j);
        }
        else
        {
            mg.qualities = *(grid + (i-1)*m + j) + *(grid + (i-1)*m + (j-1)) + *(grid + i*m + (j-1)) + *(grid + (i+1)*m + (j-1)) + *(grid + (i+1)*m + j) + *(grid + (i+1)*m + (j+1)) + *(grid + i*m + (j+1)) + *(grid + (i-1)*m + (j+1));
        }
    }
    return mg;
}