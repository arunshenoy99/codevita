#include<stdio.h>

int binary_search(int low, int high, int a[], int key)
{
    int mid;
    if (low == high)
    {
        return low;
    }
    if (low < high)
    {
        mid = (low+high)/2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return binary_search(low, mid-1, a, key);
        }
        else
        {
            return binary_search(mid+1, low, a, key);
        }
    }
    return -1;
}

int main(void)
{
    int a[] = {1,2,3,4};
    int index = binary_search(0, 3, a, 1);
    printf("%d", index);
}
