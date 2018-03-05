#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[50];
int top=-1;

push(char elem)
{
    s[++top]=elem;
}

char pop()
{
    return(s[top--]);
}

int precd(char elem)
{
    switch(elem)
    {
        case '#':
            return 0;
        case ')':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
    }
}

main()
{
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\nEnter the Infix Expression: ");
    scanf("%s",infx);
    push('#');
    strrev(infx);
    while( (ch=infx[i++]) != '\0')
    {
        if(ch == ')')
            push(ch);
        else if(isalnum(ch))
                prfx[k++]=ch;
        else if( ch == '(')
        {
            while( s[top] != ')')
                prfx[k++]=pop();
            elem=pop();
        }
        else
        {
            while( precd(s[top]) >= precd(ch) )
                prfx[k++]=pop();
            push(ch);
        }
    }
    while( s[top] != '#')
        prfx[k++]=pop();
    prfx[k]='\0';
    strrev(prfx);
    strrev(infx);
    printf("\n\nGiven Infix Expression: %s\nPrefix Expression: %s\n",infx,prfx);
}
