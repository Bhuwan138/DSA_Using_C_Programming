#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int arr[6];
    int tos;
};

void push(struct Stack *, int);
int pop(struct Stack *);
int peek(struct Stack *);
int sort(struct Stack *);

int main(){
    struct Stack s;
    s.tos = -1;
    int num;
    for (int i = 0; i < 5; i++) {   
        printf("Enter a number");
        scanf("%d",&num);
        push(&s,num);
    }
   
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",sort(&s));
    }
    return 0;
}

int sort(struct Stack *p){
    struct Stack temp_stack;
    int temp;
    temp = pop(*p);
    if(p->tos == -1){
        push(temp_stack,temp);
    }
    if(temp > temp_stack.arr[temp_stack.tos]){
        push(temp_stack,temp);
    }
    else{
        push(p,pop(temp_stack));
    }
}

//Push Operation
void push(struct Stack *p, int x)
{
    if (p->tos == 6)
    {
        printf("\nStack OverFlow\n");
        return;
    }
    // p->tos++;
    // p->arr[p->tos] = x;
    p->arr[++p->tos] = x; //shorthand for above 2 lineSS
    printf("\nPushed %d Sucessfully!!\n", x);
}

//Pop Operation
int pop(struct Stack *p)
{
    // int del;
    if (p->tos == -1)
    {
        printf("\nStack Underflow\n");
        return 0;
    }
    // del = p->arr[p->tos];
    // p->tos--;
    // return del;
    return p->arr[p->tos--]; //shorthand for above 3 line
}

