/*

    - A + B * C $ D - E / F * G       --------> Infix Expression
    - 10 + 2 * 2 $ 3 - 12 / 6 * 3
    - A+ B * CD$ -E / F * G
    - A + BCD$* - E / F * G
    - A + BCD$* - EF/  * G
    - A + BCD$* - EF/G*
    - ABCD$*+ - EF/G*
    - ABCD$*+EF/G*-       ---------> Postfix Expression

*/

#include <stdio.h>
#include <math.h>



struct Stack
{
    int tos;
    float arr[50];
};

void push(struct Stack *, float);
float pop(struct Stack *);
float calculate(float, float, char);
int isoperand(char);
float solve(char[]);

int main()
{
    // struct Stack s;
    char postfix[50];
    float answer;
    printf("Enter a valid postfix character array : ");
    scanf("%s", &postfix);

    answer = solve(postfix);
    printf("Answer of postfix expression is : %f", answer);

    return 0;
}

float solve(char postfix[])
{
    int i;
    struct Stack s;
    s.tos = -1;
    float operand1, operand2, result;
    char ch;
    // Comparing every character
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        // Checking weather a character is operand or operator
        if (isoperand(ch) == 1)
        {
            push(&s, ch - 48);
        }
        else
        {
            operand2 = pop(&s);
            operand1 = pop(&s);
            result = calculate(operand1, operand2, postfix[i]);
            push(&s, result);
        }
    }
    return result;
}

int isoperand(char ch)
{
    //checking weather a character is a number or not
    // if it is a number return 1 otherwise return 0
    return (ch >= '0' && ch <= '9');
}

float calculate(float operand1, float operand2, char ch)
{
    switch (ch)
    {
    case '+':
        return operand1 + operand2;

    case '-':
        return operand1 - operand2;

    case '*':
        return operand1 * operand2;

    case '/':
        return operand1 / operand2;

    case '%':
        return fmod(operand1, operand2);

    case '$':
        return pow(operand1, operand2);

    default:
        return 0.0;
    }
}

void push(struct Stack *p, float n)
{
    if (p->tos == 49)
    {
        printf("Stack Overflow\n");
        return;
    }
    p->arr[++p->tos] = n;
    // printf("%d is pushed sucessfully !!\n", n);
}

float pop(struct Stack *p)
{
    if (p->tos == -1)
    {
        printf("Stack UnderFlow\n");
        return 0.0;
    }
    return p->arr[p->tos--];
}