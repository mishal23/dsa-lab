/*
    Problem:- Convert infix expression to Postfix using Stack

    How to Use:- Enter the expression in terms of variables a,b,c,d.... and get the
                 postfix expression of it.
*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
char oprt[12345];
int top=-1;

void push(char element)
{
  if(top==12344)
  {
    printf("Stack is full\n");
  }
  else
  {
    top++;
    oprt[top]=element;
  }
}

int top1()
{
  return oprt[top];
}

void pop()
{
  if(top==-1)
  {
    printf("Stack is empty\n");
  }
  else
    top--;
}

int empty()
{
    if(top==-1)
      return 1;
    else
      return 0;

}

int main()
{
    int i;
    char str[400];
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(isalpha(str[i]))
            printf("%c",str[i]);
        else if(str[i]==')' && !empty())
        {
            char temp;
            do
            {
                temp=top1();
                pop();
                if(temp!='(')
                  printf("%c",temp);
            }
            while(temp!='(');
        }
        else
            push(str[i]);
    }
    while(!empty())
    {
        printf("%c",top1());
        pop();
    }

    printf("\n");
}


