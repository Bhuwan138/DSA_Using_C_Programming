#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void append(struct node **, int);
void display(struct node *);
int searchNode(struct node *,int);

int main(){
    struct node *start = NULL;
    int x;
    append(&start,45);
    append(&start,96);
    append(&start,63);
    display(start);
    x = searchNode(start,63);
    printf("%d is found on %d location",63,x);
    return 0;
}

int searchNode(struct node *p, int num){
    int count = 0;
    if(p == NULL){
        return 0;
    }
    while (p != NULL)
    {
       count++;
       if (p->data == num)
       {
           return count;
       }
       p = p->next;
       
    }
    
    return -1;
    
       

}

void append(struct node **ps,int num){
    struct node *p,*temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = num;
    // printf("%d is added sucessfully \n",p->data); //for displaying the data of node
    p->next = NULL;

    if (*ps == NULL)
    {
        *ps = p;
        return;
    }

    temp = *ps;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = p;
}

void display(struct node *p){
    if (p == NULL)
    {
        printf("Node is not created\n");
        return;
    }
    while(p != NULL){
    printf("%d is added sucessfully\n",p->data);
    p = p->next;
    }
    
}