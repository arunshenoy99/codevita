#include<stdio.h>

struct edge
{
    int src;
    int dst;
    int weight;
};

typedef struct edge Edge;

int find(int i, int parent[])
{
    if (parent[i] == i)
    {
        return i;
    }
    return find(parent[i], parent);
}


void unify(int i, int j, int parent[])
{
    parent[i] = j;
}

int main(void)
{
    int n, a[10][10], i, j, parent[10], count=0, temp, s, d;
    Edge e[10];
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            e[count].src = i;
            e[count].dst = j;
            e[count].weight = a[i][j];
            count++;
        }
    }
    for(i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if(e[j].weight > e[j+1].weight)
            {
                temp = e[j].src;
                e[j].src = e[j+1].src;
                e[j+1].src = temp;
                temp = e[j].dst;
                e[j].dst = e[j+1].dst;
                e[j+1].dst = temp;
                temp = e[j].weight;
                e[j].weight = e[j+1].weight;
                e[j+1].weight = temp;
            }
        }
    }
    for(i = 0; i < count; i++)
    {
        s = find(e[i].src, parent);   
        d = find(e[i].dst, parent);
        if(s != d)
        {
            unify(s, d, parent);
            printf("%d -> %d\t%d\n", e[i].src, e[i].dst, e[i].weight);
        }
    }
}