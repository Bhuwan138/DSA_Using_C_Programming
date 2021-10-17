#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void append(struct node **, int);
void display(struct node *);
void delete_first_node(struct node **);

int main(){
    struct node *start = NULL;
    append(&start,45);
    // append(&start,63);
    display(start);
    delete_first_node(&start);
    append(&start,96);
    display(start);
    return 0;
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

void delete_first_node(struct node **ps){
    struct node *temp = NULL;
    if(*ps == NULL){
        printf("Empty Node\n");
        return;
    }

    // deleting if there is one node but there is no use of this 
    // if((*ps)->next == NULL){
    //     printf("%d is deleted now linked list is empty\n",(*ps)->data);
    //     free(*ps);
    //     *ps = NULL;
    //     return;
    // }
    printf("%d is deleted\n",(*ps)->data);
    temp = (*ps);
    (*ps) = (*ps)->next;
    free(temp);
    return;


}