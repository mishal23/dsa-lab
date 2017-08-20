/*
    Program to reverse the linked list
*/
#include<stdio.h>
#include<stdlib.h>
void display();
void insert();
void reverse();
struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter 1 to insert to Linked List");
        printf("\nEnter 2 to display Linked List");
        printf("\nEnter 3 to reverse the Linked List");
        printf("\nEnter 10 to Exit\n");
        printf("Your choice: ");
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
            reverse();
            break;

        case 10:
            exit(0);
            break;

        default:
            printf("\nWrong Choice");
        }
    }
}
void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ptr=start;
        printf("The elements of the list are:\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void insert()
{
    struct node *temp,*ptr;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of memory space\n");
        return;
    }
    printf("Enter the position at which you ant to be inserted: ");
    scanf("%d",&pos);
    printf("Enter the data to be added to List: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(pos==0){
        temp->next=start;
        start=temp;
    }
    else{
        for(i=0,ptr=start;i<pos-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Position not found");
                return;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void reverse()
{
    struct node *p,*q,*r;
    p=q=r=start;
    p=p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    start=q;

    printf("Elements reversed\nEnter 2 to display elements\n");
}
