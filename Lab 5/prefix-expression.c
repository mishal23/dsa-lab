/*

 * Evaluate Prefix expression using Stack

*/
#include<stdio.h>
#include<string.h>
int stack[100];
int top=-1;

void push(int val)
{
    top++;
    stack[top]=val;
}

int pop()
{
    return(stack[top--]);

}

int type(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}

void main()
{
    char prefix[10];
    int len,val,i,opr1,opr2,res;
    printf("Enter the prefix Expression: ");
    scanf("%s",prefix);
    len=strlen(prefix);
    for(i=len-1;i>=0;i--)
    {
        int x=type(prefix[i]);
        switch(x)
        {
            case 0:
                val=prefix[i]-'0';
                push(val);
            break;

            case 1: opr1=pop();
                opr2=pop();
                switch(prefix[i])
                {
                    case '+':
                        res=opr1+opr2;
                        break;
                    case '-':
                        res=opr1-opr2;
                        break;
                    case '*':
                        res=opr1*opr2;
                        break;
                    case '/':
                        res=opr1/opr2;
                        break;
                }
                push(res);
        }
    }
    printf("Answer:- %d",stack[0]);
}






