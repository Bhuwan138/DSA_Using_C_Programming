#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int arr[5];
    int tos;
};

void push(struct Stack *, int);
int pop(struct Stack *);

int main()
{
    struct Stack s;
    int i, x, choise;
    s.tos = -1;

    do
    {
        printf("\n1. Push() Operation\n2. Pop() Operation\n3. Exit Program\n");
        printf("Enter a operation : ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            printf("enter the element : ");
            scanf("%d", &x);
            push(&s, x);
            break;
        }
        case 2:
        {
            x = pop(&s);
            if (x != 0)
            {
                printf("%d is poped Sucessfully!!\n", x);
            }
            break;
        }
        case 3:
            // break;
            goto b;
        default:
            printf("Invalid Operation\n");
            break;
        }
    } while (1);
b:
    return 0;
}

//Push Operation
void push(struct Stack *p, int x)
{
    if (p->tos == 4)
    {
        printf("Stack OverFlow\n");
        return;
    }
    // p->tos++;
    // p->arr[p->tos] = x;
    p->arr[++p->tos] = x;
    printf("Pushed %d Sucessfully!!\n", x);
}

//Pop Operation
int pop(struct Stack *p)
{
    // int del;
    if (p->tos == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    // del = p->arr[p->tos];
    // p->tos--;
    // return del;
    return p->arr[p->tos--];
}