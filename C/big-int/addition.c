#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(void)
{
    int carry=0,i,j,m,n,p;
    char a[100],b[100], c[100];
    printf("Enter the first number");
    scanf("%s", a);
    printf("Enter the second number");
    scanf("%s", b);
    m = strlen(a);
    n = strlen(b);
    if (m > n)
    {
        for(i = n - 1; i < m; i++)
        {
            b[i] = '0';
        }
        b[i] = '\0';
        n = i;
    }
    else if (n > m)
    {
        for (i = m - 1; i < n; i++)
        {
            a[i] = '0';
        }
        a[i] = '\0';
        m = i;
    }
    else ;
    strrev(a);
    strrev(b);
    for(i = 0; i < m; i++)
    {
        p = (a[i] - '0') + (b[i] - '0') + carry;
        c[i] = p%10;
        carry = p/10;
    }
    while(carry != 0)
    {
        c[i++] = carry%10;
        carry = carry/10;
    }
    for(j = i - 1; j >=0; j--)
    {
        printf("%d", c[j]);
    }
}