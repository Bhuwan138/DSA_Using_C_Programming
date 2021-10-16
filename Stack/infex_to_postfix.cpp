//WAP to convert infix expression to postfix expression (Without Parenthisis)
#include<stdio.h>
#include<ctype.h>

struct stack{
    char arr[50];
    int tos;
};

/*
    a + b - c * d / e $ f % g
    a + b - c * d / ef$ % g
    a + b - cd* / ef$ % g
    a + b - cd*ef$/ % g
    a + b - cd*ef$/g%
    ab+ - cd*ef$/g%
    ab+cd*ef$/g%-

*/

void push(struct stack * , char);
char pop(struct stack *);
int isOperand(char);
int isEmpty(struct stack);
int isPrecidence(char , char);
void convert(char[] , char[]);


int main(){
    char infix[50],postfix[50];
    printf("Enter the infix character array : ");
    scanf("%s",&infix);
    convert(infix,postfix);
    printf("Your postfix array is : %s ", postfix );
    return 0;

}


//Push Defination
void push(struct stack *p, char ch){
    if(p->tos == 49){
        printf("Stack Overflow\n");
        return;
    }
    p->tos += 1;
    p->arr[p->tos] = ch;
    
}


//Pop Defination
char pop(struct stack *p){
    char ch;
    if(p->tos == -1){
        printf("Underflow\n");
        return 0;
    }
    ch = p->arr[p->tos];
    p->tos -= 1;
    return ch;
    // return p->arr[p->tos--];
}


//Checking weather a operand is operator or not
int isOperand(char ch){
    if(isalpha(ch) == 0 && isdigit(ch) == 0)
        return 0;
    return 1;
}

int isEmpty(struct stack p){
    return (p.tos == -1);
}


//Main logic of converting infix to postfix
void convert(char infix[] , char postfix[] ){
    struct stack s;
    int i,j = 0;
    char ch;
    int ans;
    s.tos = -1;

    for ( i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if(isOperand(ch) == 1){
            postfix[j] = ch;
            j++;
        }
        else{
            while(isEmpty(s) == 0)
            {
                ans = isPrecidence(ch,s.arr[s.tos]);
                if(ans == 1)
                {
                    break;
                }
                postfix[j] = pop(&s);
                j++;

            }
            push(&s,ch);
        }
    }
    while(isEmpty(s) == 0){
        postfix[j] = pop(&s);
        j++;
    }
    postfix[j] = '\0';
}

//Check precidence
int isPrecidence(char op1, char op2)
{
    if (op2 == '$')
    {
        return 0;
    }
    else if(op1 == '$')
    {
        return 1;
    }
    else if(op2 == '*' || op2 == '/' || op2 == '%'){
        return 0;
    }
    else if(op1 == '*' || op1 == '/' || op1 == '%'){
        return 1;
    }
    else if(op2 == '+' || op2 == '-'){
        return 0;
    }
    else 
        return 1;
   
}
