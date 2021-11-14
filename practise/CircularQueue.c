#include<stdio.h>
#include<stdlib.h>

struct CQueue {
    int arr[5];
    int front;
    int rear;
};

void insert(struct CQueue *, int );
int delete(struct CQueue *);

int main(){
    struct CQueue c;
    c.front = -1;
    c.rear = -1;

    insert(&c,45);
    insert(&c,65);
    insert(&c,93);
    insert(&c,73);
    insert(&c,19);
    insert(&c,61);

    return 0;
}

void insert(struct CQueue *p, int num){

    if( (p->rear + 1 == p->front) || (p->rear ==4 && p->front ==0) ){
        printf("Queue Overflow \n");
        return;
    }

    if(p->rear == 4)
        p->rear = 0;

    p->rear = p->rear + 1;
    p->arr[p->rear] = num;
    printf("%d is added sucessfully\n ",num);

    if(p->front == -1)
        p->front = 0;



} 
