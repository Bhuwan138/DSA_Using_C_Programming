#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
};

void push(struct Stack **,int );
int pop(struct Stack **);

int main(){
    struct Stack *tos=NULL;
    push(&tos,45);
    push(&tos,92);
    push(&tos,26);
    push(&tos,67);
    printf("%d is popped\n",pop(&tos));
    printf("%d is popped\n",pop(&tos));
    printf("%d is popped\n",pop(&tos));
    printf("%d is popped\n",pop(&tos));
    printf("%d is popped\n",pop(&tos));

    return 0;
}

void push(struct Stack **ptos,int num){
    struct Stack *p;

    p = (struct Stack *)malloc(sizeof(struct Stack));

    if(p == NULL){
        printf("Stack Overflow\n");
        return;
    }

    p->data = num;
    printf("%d is pushed Sucessfully\n",num);
    p->next = *ptos;
    *ptos = p;
}

int pop(struct Stack **ptos){
    struct Stack *temp;
    if( *ptos == NULL){
        printf("Stack Underflow\n");
        return (*ptos)->data;
    }

    temp = *ptos;
    int x = (*ptos)->data;
    *ptos = (*ptos)->next;
    free(temp);
    return x;


}
