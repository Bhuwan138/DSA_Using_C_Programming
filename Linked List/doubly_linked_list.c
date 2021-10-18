#include<stdio.h>
#include<stdlib.h>

struct doubly{
    struct doubly *prev;
    int data;
    struct doubly *next;
};


void append(struct doubly **, int );
void display(struct doubly *);

int main(){
    struct doubly *start = NULL;

    append(&start,25);
    append(&start,39);
    append(&start,48);
    append(&start,92);
    append(&start,73);
    display(start);

    
    return 0;
}

void append(struct doubly **ps, int num ){
    struct doubly *temp,*p;

    p = (struct doubly *)malloc(sizeof(struct doubly));
    p->data = num;
    p->next = NULL;

    if (*ps == NULL)
    {
        p->prev = NULL;
        *ps = p;
        return;
    }

    temp = *ps;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    
}

void display(struct doubly *p){
    if(p == NULL){
        printf("List is Emply\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d is added sucessfully\n", p->data);
        p = p->next;
    }
}
