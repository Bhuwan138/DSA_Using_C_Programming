#include <stdio.h>

struct Stack
{
    int arr[5];
    int tos;
};

void push(struct Stack *, int);
int pop(struct Stack *);
int peek(struct Stack);
int main()
{
    struct Stack s;

    s.tos = -1;
    push(&s, 20);
    push(&s, 5);
    peek(s);
    push(&s, 56);

    printf("Poped element is %d\n", pop(&s));
    printf("Poped element is %d\n", pop(&s));
    peek(s);
    printf("Poped element is %d\n", pop(&s));
    printf("Poped element is %d\n", pop(&s));

    return 0;
}

void push(struct Stack *p, int num)
{
    if (p->arr[p->tos] == 4)
    {
        printf("Stack overflow\n");
        return 0;
    }
    p->tos += 1;
    p->arr[p->tos] = num;
    printf("Element %d is pushed Sucessfully\n", num);
}

int pop(struct Stack *p)
{
    int del;
    if (p->arr[p->tos] == -1)
    {
        printf("Underflow\n");
    }
    del = p->arr[p->tos];
    p->tos -= 1;
    return del;
}
int peek(struct Stack p)
{
    printf("peeked element is %d\n", p.arr[p.tos]);
}