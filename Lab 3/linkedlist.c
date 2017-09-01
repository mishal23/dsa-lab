/*
    Program to Insert, Display, Search, Delete elements of a Linked list at any position
*/
#include<stdio.h>
#include<stdlib.h>
void display();
void insert();
void delete();
struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
int main()
{
    int choice,ans,key;
    while(1)
    {
        printf("\nEnter 1 to insert to Linked List");
        printf("\nEnter 2 to display Linked List");
        printf("\nEnter 3 to delete element");
        printf("\nEnter 4 to search");
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
            delete();
            break;

        case 4:
            printf("Enter element to search: ");
            scanf("%d",&key);
            ans=search(key);
            if(ans==-1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Position found at %d\n",ans);
            }
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
    printf("Enter the position at which you want to insert: ");
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

void delete()
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }
    else
    {
        printf("Enter the position of the node to be deleted: ");
        scanf("%d",&pos);
        if(pos==0)
        {
            ptr=start;
            start=start->next;
            printf("The deleted element is %d\n",ptr->data);
            free(ptr);
        }
        else
        {
            ptr=start;
            for(i=0;i<pos;i++)
            {
                temp=ptr;
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("Position not found\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("The deleted element is %d\n",ptr->data);
            free(ptr);
        }
    }
}

int search(int key)
{
    int count=0,position_found=-1;
    while(start!=NULL)
    {
        if(start->data == key)
        {
            position_found = count;
            break;
        }
        start = start->next;
        count++;
    }
    return position_found;
}
