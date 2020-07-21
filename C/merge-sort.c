#include<stdio.h>


void merge(int low, int mid, int high, int a[])
{
    int b[10];
    int i, j, k;
    i = j = low;
    k = mid + 1;
    while((j<=mid) && (k<=high))
    {
        if (a[j] <= a[k])
        {
            b[i] = a[j];
            j = j + 1;
        }
        else
        {
            b[i] = a[k];
            k = k + 1;
        }
        i = i + 1;
    }
    while(j <= mid)
    {
        b[i++] = a[j++];
    }
    while(k <= high)
    {
        b[i++] = a[k++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}


void merge_sort(int low, int high, int a[])
{
    int mid;
    if (low < high)
    {
        mid = (low + high)/2;
        merge_sort(low, mid, a);
        merge_sort(mid+1, high, a);
        merge(low, mid, high, a);
    }
}

int main(void)
{
    int a[] = {2, 4, 3, 1};
    int i;
    merge_sort(0, 3, a);
    for (i = 0; i < 4; i++)
    {
        printf("%d\t", a[i]);
    }
}