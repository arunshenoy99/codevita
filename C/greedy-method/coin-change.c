#include<stdio.h>

int main(void)
{
    int denom[] = {1, 2, 5, 10, 20, 50, 100};
    int n=0, amount, i;
    printf("Enter the amount:");
    scanf("%d", &amount);
    for(i = 6; i >= 0; i--)
    {
        while(denom[i] <= amount)
        {
            amount = amount - denom[i];
            n++;
        }
        if(amount == 0)
        {
            break;
        }
    }
    if (amount != 0)
    {
        printf("Problemo");
    }
    else
    {
        printf("No of coins:%d\n", n);
    }
    
}