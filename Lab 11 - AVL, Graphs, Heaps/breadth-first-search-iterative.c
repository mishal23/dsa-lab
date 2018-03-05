/*
	Breadth First Search using Adjacency List
    Iterative Approach
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
int queue[1000],front=-1,rear=-1;

void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=0;rear=0;
        queue[front]=x;
        return ;
    }

    if(rear==999)
    {
        printf("Queue is full\n");
        return ;
    }

    rear++;
    queue[rear]=x;
    return ;
}

bool isEmpty()
{
    if((front==-1&&rear==-1))
    {
        return true;
    }
    return false;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        return ;
    }
    if(front==rear&&rear!=0)
    {
        front=-1;rear=-1;
        return ;
    }
    front++;
    return ;
}

int front_()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        exit(0);
    }
    return queue[front];
}

struct node *newNode(int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(ptr));
    ptr->data=x;
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

void iterative_BFS(int node)
{
    enqueue(node);
    visited[node]=true;
    printf("%d ",node);
     
    while(!isEmpty())
    {
        int num=front_();
        dequeue();
        struct node *temp=adj[num];
        while(temp!=NULL)
        {
            if(visited[temp->data]==false)
            {
                enqueue(temp->data);
                printf("%d\n",temp->data);
                visited[temp->data]=true;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    int no_of_nodes,no_of_edges,i,nodeA,nodeB;
    printf("Enter the number of nodes and edges :");
    scanf("%d %d",&no_of_nodes,&no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter the edge :");
        scanf("%d %d",&nodeA,&nodeB);
        insert(nodeA,nodeB);
        insert(nodeB,nodeA);
    }

    printf("Graph representation :\n");
    for(i=1;i<=no_of_nodes;i++)
    {
        printf("%d: ",i);
        struct node *temp=adj[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    int element;
    printf("Enter the node from which you want BFS :");
    scanf("%d",&element);

    printf("BFS traversal :\n");

    iterative_BFS(element);

    return 0;
}
