#include<stdio.h>

int partition(int low, int high, int a[])
{
    int pivot = a[low];
    int i, j, temp;
    i = low;
    j = high + 1;
    while(1)
    {
        while(a[++i] <= pivot)
        {
            if (i == high)
            {
                break;
            }
        }
        while(a[--j] >= pivot)
        {
            if(j == low)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}


void quick_sort(int low, int high, int a[])
{
    if (low < high)
    {
        int pivot;
        pivot = partition(low, high, a);
        quick_sort(low, pivot - 1, a);
        quick_sort(pivot + 1, high, a);
    }
}

int main(void)
{
    int i;
    int a[] = {1, 2, 4, 3};
    quick_sort(0, 3, a);
    for (i = 0; i < 4; i++)
    {
        printf("%d", a[i]);
    }
}