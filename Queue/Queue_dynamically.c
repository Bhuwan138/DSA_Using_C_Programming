#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};

void insert(struct Queue **, struct Queue **, int);
int delete(struct Queue **,struct Queue **);

int main(){
    struct Queue *front,*rear;
    front = rear = NULL;

    insert(&front,&rear,10);
    // insert(&front,&rear,75);
    // insert(&front,&rear,16);
    // insert(&front,&rear,78);
    // printf("%d is deleted sucessfully\n",delete(&front,&rear));
    // printf("%d is deleted sucessfully\n",delete(&front,&rear));
    // printf("%d is deleted sucessfully\n",delete(&front,&rear));
    // printf("%d is deleted sucessfully\n",delete(&front,&rear));
    printf("%d is deleted sucessfully\n",delete(&front,&rear));
    printf("%d is deleted sucessfully\n",delete(&front,&rear));
    return 0;
}

void insert(struct Queue **pfront, struct Queue **prear, int num){

    struct Queue *p;
    // struct Queue *temp;

    p = (struct Queue *)malloc(sizeof(struct Queue));
    p->data = num;
    p->next = NULL;

    if(p == NULL){
        printf("Queue Overflow\n");
        return;
    }

    //Old technique
    // //For first node
    // if( (*prear) == NULL){
    //      *pfront = *prear = p;
    //      printf("%d is inserted sucessfully\n",(*prear)->data);

    //      return;
    // }

    
    // while( (*prear)->next != NULL ){
    //     (*prear) = (*prear)->next;
    // }

    // (*prear) = p;
    // printf("%d is inserted sucessfully\n",(*prear)->data);

    //New Technique
    if(*pfront == NULL)
        *pfront = p;
    else
        (*prear)->next = p;
    
    *prear = p;
    printf("%d is inserted sucessfully\n",(*prear)->data);
}


int delete(struct Queue **pfront,struct Queue **prear){
    struct Queue *temp;
    if((*pfront)  == NULL){
        printf("Underflow Queue\n");
        return (*pfront)->data;
    }

    //My technique
    temp = *pfront;
    int x = temp->data;
    *pfront = (*pfront)->next;
    free(temp);
    return x;


    //Sir Technique
    // temp = *pfront;
    // int x = temp->data;
    // if(*pfront == *prear)
    //     *pfront = *prear = NULL;
    // else
    //     *pfront = (*pfront)->next;

    // free(temp);
    // return x;
    
}
