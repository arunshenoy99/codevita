#include<stdio.h>

int main(void)
{
    int p[10], d[10], slots[10], count = 0, slot, profit = 0;
    int n, i, j;
    printf("Enter the number of jobs:");
    scanf("%d", &n);
    printf("Enter the profits for the jobs in decreasing order\n");
    for (i = 0; i < n; i++)
    {
        slots[i] = -1;
        scanf("%d", &p[i]);
    }
    printf("Enter the deadlines for the jobs\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    for (i = 0; i < n; i++)
    {
        slot = d[i] - 1;
        for (j = slot; j >= 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                count++;
                profit += p[i];
                break;
            }
        }
    }
    printf("The jobs are:\t");
    for (i = 0; i < count; i++)
    {
        printf("%d\t", slots[i]);
    }
    printf("\nThe total profit is:%d", profit);
}