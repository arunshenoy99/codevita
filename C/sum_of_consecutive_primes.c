#include<stdio.h>
#include<stdlib.h>

int generate_prime(unsigned long long int, unsigned long long int*);
int is_prime(unsigned long long int);

int main(void)
{
    unsigned long long int n,sum=0;
    int i=0,j=0,count=0;
    scanf("%llu", &n);
    if (n<2 || n > 12000000000)
    {
        return 0;
    }
    unsigned long long int *primes = (unsigned long long int*)malloc(sizeof(unsigned long long int) * n);
    int no_of_primes = generate_prime(n, primes);
    for(i=0;i<no_of_primes ;i++)
    {
        sum = *(primes + i);
        for(j=i+1; j<no_of_primes; j++)
        {
            sum = sum + (*(primes+j));
            if(sum >= n)
            {
                break;
            }
            if(is_prime(sum))
            {
                count++;
            }
        }
    }
    printf("%d", count);

}

int is_prime(unsigned long long int x)
{
    unsigned long long int j;
    for(j=2;j<x;j++)
    {
        if(x%j == 0)
        {
            return 0;
        }
    }
    return 1;
}

int generate_prime(unsigned long long int n, unsigned long long int *primes)
{
    unsigned long long int i;
    int p=0,j=0;
    for(i = 2; i <= n; i++)
    {
        p = is_prime(i);
        if(p == 0)
        {
            continue;
        }
        else
        {
            *(primes + j) = i;
            j++;
        }
    }
    return j;
}