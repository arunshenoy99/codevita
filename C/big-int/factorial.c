#include<stdio.h>

int main(void)
{
    int nd=1,carry=0,m,i,j,p;
    int fact[100];
    printf("Enter the number to find the factorial:");
    scanf("%d", &m);
    fact[0] = 1;
    for(i = 2; i <= m; i++)
    {
        for(j = 0; j < nd; j++)
        {
            p = fact[j] * i + carry;
            fact[j] = p%10;
            carry = p/10; 
        }
        while(carry!=0)
        {
            fact[nd++] = carry % 10;
            carry = carry/10;
        }
    }
    for(i = nd - 1; i >= 0; i--)
    {
        printf("%d", fact[i]);
    }
}