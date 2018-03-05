/*
    Program to check if Linked List is circular or not
*/
#include<stdio.h>
#include<stdlib.h>

//Detect loop in a linked list

struct node {
  int data;
  struct node* next;
};

struct node* head = NULL;

void insert(int pos, int data) {
  struct node* newptr = (struct node*)malloc(sizeof(struct node*));
  newptr->data = data;
  newptr->next = NULL;
  if(head == NULL)
    head = newptr;
  else if(pos == 1) {
    newptr->next = head;
    head = newptr;
  }
  else {
    int count = 1, total = 0;
    struct node* temp = head;
    while(count < pos-1 && temp != NULL) {
      temp = temp->next;
      count++;
    }
    struct node* t = temp->next;
    temp->next = newptr;
    newptr->next = t;
  }
}

void detect() {
	struct node *ptr1= head, *ptr2 = head;
	while(ptr1 && ptr2 && ptr2->next) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if(ptr1 == ptr2) {
			printf("\nLoop found");
			return;
		}

	}
	printf("\nLoop not found");
}

void main () {
	insert(1,12);
	insert(1,13);
	insert(1,2);
	insert(1,41);
	insert(1,526);

	    /* Create a loop for testing */
    head->next->next->next->next = head;
    detect(head);

}

