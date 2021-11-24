#include<stdio.h>
#include<stdlib.h>
struct edge{
    char data;
    struct edge *next;
};


struct node{
    char data;
    struct edge *enext;
    struct node *next;
};

struct STACK{
    struct edge *arr[100];
    int tos;
};

void push(struct STACK *stack,struct edge *p)
{
    if(stack->tos == 100){
        printf("Stack Overflow \n");
        return;
    }

    stack->arr[++stack->tos] = p;
}

struct edge * pop(struct STACK *stack){
    if(stack->tos == -1){
        printf("Stack Underflow\n");
        return 0;
    }
    
    return stack->arr[stack->tos--];
}

void add_vertex(struct node **,char);
void insert_edge(struct node *,char, char);
struct node * find_vertex(struct node *,char);
void display(struct node *);
void remove_vertex(struct node **, char);
void remove_edge(struct node *,char,char);

int main(){
    char ch1,ch2;
    int choice,stop=0;
    struct node *start=NULL;

    do{
        printf("\n1. Add Vertex\n");
        printf("2. Insert Edge\n");
        printf("3. Display\n");
        printf("4. Remove Vertex\n");
        printf("5. Remove Edge\n");
        printf("6. EXIT\n");
        printf("\nEnter a choise ? ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a character : ");
            fflush(stdin);
            scanf("%c",&ch1);
            add_vertex(&start,ch1);
            break;
        case 2:
            printf("Enter source and destination nodes : ");
            fflush(stdin);
            scanf("%c %c",&ch1,&ch2);
            insert_edge(start,ch1,ch2);
            break;
        
        case 3:
            display(start);
            break;

        case 4:
            printf("Enter a name of vertex which you want to remove ? ");
            fflush(stdin);
            scanf("%c",&ch1);
            remove_vertex(&start,ch1);
            break;

        case 5:
            printf("Enter the source and destination nodes : ");
            fflush(stdin);
            scanf("%c %c",&ch1,&ch2);
            remove_edge(start,ch1,ch2);
            break;

        case 6:
            stop = 1;
            break;

        default:
            printf("Wrong Choice :( \n\n");
            break;
        }
    }while(stop == 0);
    return 0;
}

void add_vertex(struct node **pr,char ch1){
    struct node *p,*temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    p->data = ch1;
    p->enext = NULL;

    if(*pr == NULL){
        *pr = p;
        return;
    }

    temp = *pr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
}


struct node * find_vertex(struct node *p, char ch){
    while(p != NULL){
        if(p->data == ch)
            return p;
        p = p->next;
    }
    return NULL;
}

struct edge * find_edge(struct edge *p, char ch){
    while(p != NULL){
        if(p->data == ch)
            return p;
        p = p->next;
    }
    return NULL;
}


void insert_edge(struct node *p,char source, char destination){
    struct node *source_index;
    struct edge *edge_pointer,*temp_edge;
    if(p == NULL){
        printf("Graph is Empty\n");
        return;
    }

    source_index = find_vertex(p,source);
    if(source_index == NULL){
        printf("Source Node dosen't exist\n");
        return;
    }

    if(find_vertex(p,destination) == NULL){
        printf("Destination Node dosen't exist.\n");
        return;
    }

    edge_pointer = (struct edge *)malloc(sizeof(struct edge));
    edge_pointer->data = destination;
    edge_pointer->next = NULL;

    if(source_index->enext == NULL){
        source_index->enext = edge_pointer;
        return;
    }

    temp_edge = source_index->enext;
    while(temp_edge->next != NULL){
        temp_edge = temp_edge->next;
    }
    temp_edge->next = edge_pointer;
    printf("Edge added Sucessfully\n");

}

void display(struct node *p){
    struct edge *temp;
    if(p == NULL){
        printf("Graph is empty\n");
        return;
    }

    while(p != NULL){
        printf("%c\t: ",p->data);
        temp = p->enext;
        while(temp != NULL){
            printf("%c ,",temp->data);
            temp = temp->next;
        }
        printf("\b \n");
        p = p->next;
    }
}


void remove_edge(struct node *p,char source, char destination){
    struct node *source_vertex;
    struct edge *destination_edge,*temp;
    

    if(p==NULL){
        printf("Node dosen't exist\n");
        return;
    }

    source_vertex = find_vertex(p,source);
    if(source_vertex == NULL){
        printf("Source Node dosen't exist\n");
        return;
    }

    destination_edge = find_edge(source_vertex->enext,destination);
    if(destination_edge == NULL){
        printf("Destination Node dosen't exist.\n");
        return;
    }

    if(source_vertex->enext == destination_edge){
        if(destination_edge->next == NULL){
            source_vertex->enext = NULL;
            free(destination_edge);
            return;
        }
        source_vertex->enext  = destination_edge->next;
    }

    temp = source_vertex->enext;
    while(temp->next != NULL){
        if(temp->next == destination_edge){
            temp->next = destination_edge->next;
            free(destination_edge);
            return;
        }
        temp = temp->next;
    }
}

void remove_vertex(struct node **pr,char ch){
    struct node *searched,*temp,*prev;
    struct edge *etemp = NULL,*popped;
    struct STACK *stack;
    stack->tos = -1;
    if(*pr == NULL){
        printf("Vertex is not created yet.");
        return;
    }

    searched = find_vertex(*pr,ch);
    etemp = searched->enext;
    while(etemp != NULL){
        etemp = etemp->next;
        push(stack,etemp);
    }
    while(etemp != NULL){
       popped =  pop(etemp);
       free(etemp);
    }


    temp = *pr;
    if(temp == searched){
        temp->next = searched->next;
        free(searched);
        return;
    }

    while(temp != searched){
        prev = temp;
        temp = temp->next;
        if(temp->next == NULL){
            printf("Node not found\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);


}