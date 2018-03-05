/*
	Min heap
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "limits.h"
int max_size=100;
int heap_size;
int heap[100];

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return (2*i + 1);
}
int right(int i)
{
    return (2*i + 2);
}
int insert(int data)
{
    if(heap_size==max_size)
    {
        printf("Heap Full\n");
    }
    heap_size++;
    int i=heap_size-1;
    heap[i]=data;

    while(i!=0 && heap[parent(i)]<heap[i])
    {
        swap(&heap[i],&heap[parent(i)]);
        i=parent(i);
    }

}

void printLevelOrder()
{
    int i;
    for(i=0;i<heap_size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void MaxHeapify(int i)
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l>=heap_size) //&& heap[l]<heap[i])
        return;
    if(r>=heap_size && heap[l]>heap[smallest])
        smallest=r;
    if(smallest!=i)
    {
        swap(&heap[i],&heap[smallest]);
        MinHeapify(smallest);
    }
}

void decrease(int i,int new_value)
{
    heap[i]=new_value;
    while(i!=0 && heap[parent(i)]>heap[i])
    {
        swap(&heap[i],&heap[parent(i)]);
        i=parent(i);
    }
}

int extractMin()
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        heap_size--;
        return heap[0];
    }
    int root=heap[0];
    heap[0]=heap[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void delete(int i)
{
    decrease(i,INT_MIN);
    extractMin();
}

int main()
{
    int choice,element,data;
    printf("Enter 1 to insert an element\nEnter 2 to delete an element\nEnter 3 for level order traversal\nEnter 4 to exit\n");

    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&element);
                insert(element);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d",&data);
                delete(data);
                break;

            case 3:
                printLevelOrder();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong choice\n");
                break;
        }
    }
}