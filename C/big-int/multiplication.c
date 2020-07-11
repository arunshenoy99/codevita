#include<stdio.h>
#include<string.h>

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
    char a[10], b[10];
    int c[10], t[10];
    int m,n,i,j,carry=0,p, nd1=0, nd2 = 0, k, z=0;
    printf("Enter the first number:");
    scanf("%s", a);
    printf("Enter the second number:");
    scanf("%s", b);
    m = strlen(a);
    n = strlen(b);
    strrev(a);
    strrev(b);
    for(i = 0; i < (m + n); i++)
    {
        c[i] = 0;
        t[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        nd1 = i;
        for(j = 0; j < m; j++)
        {
            p = (a[j] - '0') * (b[i] - '0') + carry;
            t[nd1++] = p % 10;
            carry = p / 10;
        }
        while(carry != 0)
        {
            t[nd1++] = carry % 10;
            carry = carry / 10;
        }
        for (k = 0; k < nd1; k++)
        {
            p = t[k] + c[k] + z;
            c[k] = p % 10;
            z = p / 10;
            t[k] = 0;
        }
        while (z != 0)
        {
            c[k++] = z % 10;
            z = z / 10;
        }
        nd2 = k;
    }
    for (i = nd2 - 1; i >=0 ; i--)
    {
        printf("%d", c[i]);
    }
}