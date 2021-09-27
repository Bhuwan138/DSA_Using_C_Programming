#include <stdio.h>
#include <string.h>
#include <math.h>
struct stack
{
    int arr[50];
    int tos;
};

/*
8/4 * 4-2 *7 + 8
/8_4 * 4 - 2 * 7 + 8
* /8_4_4 - 2 * 7 + 8
* /8_4_4 - *2_7 + 8
+-* /8_4_4_*2_7_8
ans = 2
*/
void push(struct stack *, float);
float pop(struct stack *);
float calculate(float, float, char);
int isOperand(char);
float solve(char[]);

int main()
{
    // struct stack s;
    char prefix[50];
    float answer;

    printf("Enter a valid prefix character : ");
    scanf("%s", &prefix);
    
    // printf("Hello \n");
    answer = solve(prefix);
    printf("The output of following prefix character is : %f ", answer);

    return 0;
}

void push(struct stack *p, float n)
{
    if (p->tos == 49)
    {
        printf("Stack overflow \n");
        return;
    }
    // p->tos += 1;
    p->arr[++p->tos] = n;
}

float pop(struct stack *p)
{
    if (p->arr[p->tos] == -1)
    {
        printf("Underflow \n");
        return 0.0;
    }
    return p->arr[p->tos--];
}

int isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

float calculate(float op1, float op2, char ch)
{
    switch (ch)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return fmod(op1, op2);
    case '$':
        return pow(op1, op2);

    default:
        return 0.0;
    }
}

float solve(char prefix[])
{
    struct stack s;
    s.tos == -1;
    int i;
    char ch;
    float op1 , op2 , result;

    for(i = strlen(prefix) - 1 ; i>= 0 ; i-- ){
        ch = prefix[i];
        if( isOperand(ch) == 1 ){
            push(&s , ch - 48);
        }
        else{
            op1 = pop(&s);
            op2 = pop(&s);
            result = calculate(op1,op2, prefix[i]);
            push(&s,result);
        }
    }
    return result;
}   