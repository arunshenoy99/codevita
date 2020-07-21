#include<stdio.h>

int partition(int low, int high, float w[], int weights[], int profits[])
{
    int pivot, i , j, temp;
    pivot = w[low];
    i = low;
    j = high + 1;
    while(1)
    {
        while(w[++i] <= pivot)
        {
            if (i == high)
            {
                break;
            }
        }
        while(w[--j] >= pivot)
        {
            if (j == low)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        temp = w[i];
        w[i] = w[j];
        w[j] = temp;
        temp = weights[i];
        weights[i] = weights[j];
        weights[j] = temp;
        temp = profits[i];
        profits[i] = profits[j];
        profits[j] = temp;
    }
    temp = w[low];
    w[low] = w[j];
    w[j] = temp;
    temp = weights[low];
    weights[low] = weights[j];
    weights[j] = temp;
    temp = profits[low];
    profits[low] = profits[j];
    profits[j] = temp;
    return j;
}


void quick_sort(int low, int high, float w[], int weights[], int profits[])
{
    if (low < high)
    {
        int pivot;
        pivot = partition(low, high, w, weights, profits);
        quick_sort(low, pivot - 1, w, weights, profits);
        quick_sort(pivot + 1, high, w, weights, profits);
    }
}

void sort_greedy(int w[], int p[], int n)
{
    int i;
    double pw;
    float greedy_w[10];
    for (i = 0; i < n; i++)
    {
        pw = p[i]/w[i];
        greedy_w[i] = pw;
    }
    printf("\n\n");
    quick_sort(0, n - 1, greedy_w, w, p);
}


int main(void)
{
    int m, n, p[10], w[10], i;
    float pw, total = 0;
    printf("Enter the value of knapsack:");
    scanf("%d", &m);
    printf("Enter the number of weights:");
    scanf("%d", &n);
    printf("Enter the weights\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter the profits\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    sort_greedy(w, p, n);
    for (i = n - 1; i >= 0; i--)
    {
        if (w[i] <= m)
        {
            m = m - w[i];
            total += p[i];
        }
        else
        {
            break;
        }
    }
    if (i >= 0)
    {
        pw = (float)m/w[i];
        total += pw *p[i];
    }
    printf("%.2f", total);
}