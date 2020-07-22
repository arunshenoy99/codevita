#include<stdio.h>

int main(void)
{
    int n, a[10][10], i, j, v[10], w = 0, min = 999, count = 0, vx, u;
    printf("Enter the number of vertices");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            v[i] = 0;
            scanf("%d", &a[i][j]);
        }
    }
    i = 0;
    v[0] = 1;
    while (count < n)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {   
            for(j = 0; j < n; j++)
            {
                if (v[i] == 1 && a[i][j] < min && v[j] == 0)
                {
                    min = a[i][j];
                    u = i;
                    vx = j;
                }
            }
        }
        if (min == 999)
        {
            break;
        }
        printf("%d -> %d\n", u, vx);
        v[vx] = 1;
        w += min;
        count++;
    }   
    printf("The MST weight is %d", w);
}