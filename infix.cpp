#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50

char stack[SIZE];
int top=-1;
 
push(char elem)
{
    stack[++top]=elem;
}
 
char pop()
{
    return(stack[top--]);
}
 
int pr(char symbol)
{
    
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int main()
{                 
    for(;;)
    {       
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Infix : ");
    scanf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop();
                }
                else
                {
                    while( pr(stack[top]) >= pr(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("Postfix : %s\n",postfix);

    char *a;
    int num,n1,n2,n3;
    a = postfix;
    while(*a != '\0')
    {
        if(isdigit(*a))
        {
            num = *a - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*a)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            case '^':
            {
                n3 = pow(n2,n1);
                break;
            }
            }
            push(n3);
        }
        a++;
    }
    printf("Answer : %d\n\n",pop());
    }
}
