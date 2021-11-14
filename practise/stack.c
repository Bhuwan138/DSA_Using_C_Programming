#include<stdio.h>
struct Stack {
    int arr[5];
    int top;
};
typedef struct Stack stack;

void push(stack *, int);
int pop(stack *);

int main(){
    stack s;
    s.top = -1;
    push(&s, 45);
    push(&s, 35);
    push(&s, 78);
    push(&s, 36);
    push(&s, 95);
    push(&s, 62);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    return 0;
}


void push(stack *p, int num){
    //check if stack is overflow or not
    if(p->top == 4){
        printf("Stack Overflow \n");
        return;
    }

    //if stack is not over flow
    
    //increament the tos
    p->top = p->top + 1;

    //push the element in the stack 
    p->arr[p->top] = num;
    printf("%d is added sucessfully \n",num);
    // return sucess
    // return num;

}

int pop(stack *p){
    //check if the stack is empty or not 
    int x; //for storing the variable
    if(p->top == -1){
        printf("Underflow \n");
        return 0;
    }

    //if the stack is not empty

    // store the data from a stack
    x = p->arr[p->top];
    
    printf("%d is popped sucessfully \n",x);

    // decreament the tos

    p->top = p->top - 1;


    //return secuss
    return x;

}
