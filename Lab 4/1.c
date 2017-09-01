/*
    Program to perform insert and delete operations on Doubly Linked List
*/
#include<stdio.h>
#include<stdlib.h>

void insert();
void display();
void delete();

// node structure for doubly linked list
struct node{
	int data;
	struct node* next;
	struct node* prev;
}*head,*temp,*temp2;

int count=0;
int main()
{
    int choice;
    head = NULL;
    temp = NULL;
    printf("\nDoubly Linked List\n");
    while(1)
    {
        printf("\n********************************************\nEnter 1 to insert at position\nEnter 2 to display the list\nEnter 3 to delete element at a position\nEnter 10 to exit\n********************************************\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Wrong Choice");
            break;
        }
    }
}

// create a doubly linked list
void create()
{
    int value;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter value to node: ");
    scanf("%d",&value);
    temp->data = value;
    count++;
}

// insert a element to doubly linked list
void insert()
{
    int pos,i=1;
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    temp2 = head;
    if(pos<0 || pos>=count+1)
    {
        printf("Position out of range\n");
        return;
    }
    if(temp2==NULL && pos!=0)
    {
        printf("Insert at position 0 only");
    }
    if(temp2==NULL && pos==0)
    {
        create();
        head = temp;
        return;
    }
    else
    {
        while(i<pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next = temp;
    }
}

// display the linked list
void display()
{
    int i=0;
    temp2 = head;
    if(temp2==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("Elements of the linked list are: ");
    while(i<count)
    {
        printf("%d ",temp2->data);
        i++;
        temp2=temp2->next;
    }
    printf("\n");
}

// delete a particular node of linked list
void delete()
{
    int pos,i=1;
    printf("Enter position to be deleted: ");
    scanf("%d",&pos);
    temp2 = head;
    if(pos<0 || pos>=count+1)
    {
        printf("Position out of range\n");
        return;
    }
    if(temp2==NULL)
    {
        printf("Cannot delete empty list");
    }
    else
    {
        while(i<pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if(i==1)
        {
            if(temp2->next==NULL)
            {
                printf("Node deleted\n");
                free(temp2);
                temp2=head=NULL;
                return;
            }
        }
        if(temp2->next==NULL)
        {
            temp2->prev->next=NULL;
            free(temp2);
            printf("Node deleted\n");
            return;
        }
        temp2->next->prev=temp2->prev;
        if(i!=1)
            temp2->prev->next = temp2->next;
        if(i==1)
            head=temp2->next;
        printf("Node deleted\n");
        free(temp2);
    }
    count--;
}
