#include<stdio.h>

typedef struct Stack{
    int arr[15];
    int tos;
} stack;

typedef struct Queue{
    int arr[15];
    int rear;
    int front;
} queue;

void dfs(int [][5],int );
void bfs(int [][5],int );
void push(stack *,int);
int pop(stack *);
void enqueue(queue *,int);
int dequeue(queue *);

int main(){
    int adj[5][5];
    int i,j,n=5,v;

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Is there a path from V[%d] to v[%d] (Yes-1/No-0) ? ",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter the source vertex : ");
    scanf("%d",&v);
    bfs(adj,v); 
    return 0;
}

void dfs(int adj[][5],int source_vertex){
    stack s;
    int n = 5;
    int flag[5] = {0};
    s.tos = -1;
    push(&s,source_vertex);
    while(s.tos != -1){
        source_vertex = pop(&s);
        if(flag[source_vertex] == 0){
            printf("\nv[%d]",source_vertex);
            flag[source_vertex] = 1;
        }

        for (int i = n-1; i >= 0; i--)
        {
            if(adj[source_vertex][i] == 1 && flag[i] == 0)
                push(&s,i);
        }
    }

}

void bfs(int adj[][5],int source_vertex){
    queue q;
    int n = 5;
    int flag[5] = {0};
    q.rear = -1;
    q.front = 0;
    enqueue(&q,source_vertex);
    printf("BHuwan");
    while(q.front <= q.rear){
        printf("Sarita");
        source_vertex = dequeue(&q);
        if(flag[source_vertex] == 0){
            printf("\nv[%d]",source_vertex);
            flag[source_vertex] = 1;
        }

        for (int i = n-1; i >= 0; i--)
        {
            if(adj[source_vertex][i] == 1 && flag[i] == 0)
                enqueue(&q,i);
        }
    }

}

void enqueue(queue *q,int num){
    if(q->rear == 15){
        printf("Queue Overflow'n");
        return;
    }
    q->arr[++q->rear] = num;
}

int dequeue(queue *q){
    if(q->front > q->rear){
        printf("Queue Underflow\n");
        return 0;
    }
    return q->arr[q->front++];
}

void push(stack *s, int num){
    if(s->tos == 14){
        printf("Stack overflow\n");
        return;
    }
    
    s->arr[++s->tos] = num;
}

int pop(stack *s){
    if(s->tos == -1){
        printf("Stack Underflow\n");
        return 0;
    }
    return s->arr[s->tos--];
}