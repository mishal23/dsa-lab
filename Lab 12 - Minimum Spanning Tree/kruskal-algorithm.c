/*
    Kruskal's algorithm
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int u,v,w;
}B[1000],sortest_path[1000];

int cntd[1234];

void init()
{
    int i;
    for(i=0;i<1224;i++)
        cntd[i]=-1;
    return ;
}

void sort(int E)
{
    int i,j,temp;
    for(i=0;i<E-1;i++)
    {
        for(j=i+1;j<E;j++)
        {
            if(B[i].w>B[j].w)
            {
                temp=B[j].w;
                B[j].w=B[i].w;
                B[i].w=temp;

                temp=B[i].v;
                B[i].v=B[j].v;
                B[j].v=temp;

                temp=B[j].u;
                B[j].u=B[i].u;
                B[i].u=temp;

            }
        }
    }
}

int root(int x)
{
    if(cntd[x]==-1)
        return x;
    return root(cntd[x]);
}

void make_union(int x,int y)
{
    int x_root=root(x);
    int y_root=root(y);
    cntd[x_root]=y_root;
}

int main()
{
    int i,N,E;
    printf("Enter the number of nodes and edges :");
    scanf("%d %d",&N,&E);
    init();
    for(i=0;i<E;i++)
    {
        printf("Enter the edge in u v w form :");
        scanf("%d %d %d",&B[i].u,&B[i].v,&B[i].w);
    }

    sort(E);

    /*for(i=0;i<E;i++)
    {
        printf("%d %d %d\n",B[i].u,B[i].v,B[i].w);
    }*/

    int cost=0,indx=0;

    for(i=0;i<E;i++)
    {
        if(root(B[i].u)!=root(B[i].v))
        {
             cost+=B[i].w;
             sortest_path[indx].u=B[i].u;
             sortest_path[indx].v=B[i].v;
             sortest_path[indx].w=B[i].w;

             make_union(B[i].u,B[i].v);
             indx++;
        }
    }

    printf("Minimum cost: %d\nSortest Path:\nu v w\n",cost);
    for(i=0;i<indx;i++)
        printf("%d %d %d\n",sortest_path[i].u,sortest_path[i].v,sortest_path[i].w);
    return 0;
}