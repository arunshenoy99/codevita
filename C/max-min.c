#include<stdio.h>

int max0, min0;
int max1, min1;

void max_min(int low, int high, int a[], int *max, int *min)
{
    int mid;
    if (low == high)
    {
        *min = *max = a[low];
    }
    if (low == high - 1)
    {
        if (a[low] > a[high])
        {
            *max = a[low];
            *min = a[high];
        }
        else
        {
            *max = a[high];
            *min = a[low];
        }
    }
    else
    {
        mid = (low+high)/2;
        max_min(low, mid, a, &max0, &min0);
        max_min(mid+1, high, a, &max1, &min1);
        if (max0 < max1)
        {
            max0 = max1;
        }
        if (min0 > min1)
        {
            min0 = min1;
        }
    }
}

int main(void)
{
    int a[] = {2, 3, 5, 5};
    max_min(0, 3, a, &max0, &min0);
    printf("Max:%d, Min:%d", max0, min0);
    return 0;
}