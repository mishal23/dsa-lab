/*
	Depth First Search using Adjacency List
    Iterative Approach

    The nodes are assumed to start from 1(not 0)
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
}*adj[1000];

bool visited[100];
int stack[1000],top=-1;

void stack_push(int element)
{
    if(top==999)
    {
        printf("Stack is full\n");
        return;
    }
    ++top;
    stack[top]=element;

}

int stack_top()
{
    return stack[top];
}

void stack_pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
        return;
    }
    top--;
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

struct node *newNode(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insert(int nodeA,int nodeB)
{
    struct node *tempadj,*temp;
    temp=newNode(nodeB);
    if(adj[nodeA]==NULL)
    {
        adj[nodeA]=temp;
    }
    else
    {
        tempadj=adj[nodeA];
        while(tempadj->next!=NULL)
            tempadj=tempadj->next;
        tempadj->next=temp;
    }
    return ;
}

void iterative_DFS(int node)
{
    stack_push(node);
    visited[node]=true;
    printf("%d ", node);
    while(!isEmpty())
    {
        int num=stack_top();
        stack_pop();
        struct node *temp=adj[num];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {   
                stack_push(temp->data);
                printf("%d ",temp->data);
                visited[temp->data]=true;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    int no_of_nodes,no_of_edges,nodeA,nodeB,i;
    printf("Enter the number of nodes and edges:- ");
    scanf("%d %d",&no_of_nodes,&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter the edges: ");
        scanf("%d %d",&nodeA,&nodeB);
        insert(nodeA,nodeB);
        insert(nodeB,nodeA);
    }

    printf("Graph representation:\n");
    for(i=1;i<=no_of_nodes;i++)
    {
        printf("%d : ",i);
        struct node *temp=adj[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    int element;
    printf("Enter the node from which you want DFS: ");
    scanf("%d",&element);
    printf("DFS of graph :\n");
    iterative_DFS(element);
    return 0;
}
