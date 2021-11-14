#include<stdio.h>
#include<stdlib.h>


struct BST{
    struct BST *left;
    int data;
    struct BST *right;
    int flag;
};

struct Stack {
    struct BST *arr[20];
    int tos;
};

void push(struct Stack *,struct BST *);
struct BST * pop(struct Stack *);
void append(struct BST **,int );
void preorder(struct BST *);
void inorder(struct BST *);
void postorder(struct BST *);
int search_node(struct BST *, int , struct BST **, struct BST **);
void delete_node(struct BST **,int);

int main(){
    struct BST *root = NULL;
    append(&root,45);
    append(&root,32);
    append(&root,37);
    append(&root,31);
    append(&root,96);
    append(&root,213);
    append(&root,78);
    postorder(root);
    delete_node(&root,96);
    return 0;
}

int search_node(struct BST *root,int num,struct BST **child,struct BST **parent){
    struct BST *q=NULL;
    while()
}

void delete_node(struct BST **pr,int num){
    struct BST *child, *parent;



    int result = search_node(*pr,num,&child,&parent);
}

void append(struct BST ** pr,int num){
    struct BST *p,*temp,*prev;
    
    p = (struct BST *)malloc(sizeof(struct BST));

    //if memory is not allocated to the new node
    if(p == NULL){
        printf("Insufficient memory \n");
        return;
    }

    p->data = num;
    p->left = p->right = NULL;
    //for inserting first data in a node
    if(*pr == NULL){
        *pr = p;
        return;
    }

    temp = *pr;
    
   

    while(temp != NULL){
        prev  = temp;
        if(temp->data > num)
            temp = temp->left;
        else
            temp= temp->right;
    }

    if(prev->data>num)
        prev->left = p;
    else
        prev->right = p;
        
}

void preorder(struct BST *p){
    struct Stack s;
    if(p == NULL){
        printf("Empty Tree \n");
        return;
    }

    s.tos = -1;
    push(&s,p);
    //checking right node and push to stack if exist and go to left node
    while(s.tos !=  -1){
        p = pop(&s);
        while(p!= NULL){
            //printing current node
            printf("%d \t",p->data);
            //checking if right node is empty or not
            if(p->right != NULL){
                push(&s,p->right); //pushing to the stack
            }
            //moving toward left
            p= p->left;
        }
    }
}


void push(struct Stack *p,struct BST *num){
    
    if(p->tos == 19){
        printf("Stack overflow\n");
        return;
    }
    p->arr[++p->tos] = num;
}

struct BST * pop(struct Stack *p){
    struct BST * parr;
    if(p->tos == -1){
        printf("Underflow\n");
        return NULL;
    }
    parr = p->arr[p->tos--];
    return parr;
}

void inorder(struct BST *p){

    if(p == NULL){
        printf("EMPTY TREE\n");
        return;
    }

    struct Stack s;
    s.tos = -1;

   push_node:
        while(p!=NULL){
            push(&s,p);
            p=p->left;
        }

        p= pop(&s);

        while(p!=NULL){
            printf("%d \t",p->data);

            if(p->right !=NULL){
                p = p->right;
                goto push_node;
            }

            p = pop(&s);
        }
}

void postorder(struct BST *p){

    if(p == NULL){
        printf("Tree is empty\n");
        return;
    }

    struct Stack s;
    s.tos = -1;


    push_back:
    while(p!= NULL){
        p->flag = 1;
        push(&s,p);
        if(p->right != NULL){
            p->right->flag = -1;
            push(&s,p->right);
        }
        p= p->left;
    }

    p = pop(&s);

    while(p != NULL){
        if(p->flag == 1)
            printf("%d , ",p->data);
        else
            goto push_back;
        p = pop(&s);
    }
}


