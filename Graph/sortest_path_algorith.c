#include<stdio.h>
int min(int , int ); 
void sortest_path_algo(int [][4], int [][4]);
int main(){
    int adj[4][4], sortest_path[4][4],n=4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("s Ithere a path from V[%d] to v[%d] (Yes-weight/No-0) ? ",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }
    sortest_path_algo(adj,sortest_path);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",sortest_path[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void sortest_path_algo(int adj[][4], int sortest_path[][4]){
    int INFINITY = 32000,n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (adj[i][j] == 0)? (sortest_path[i][j] = INFINITY) : (sortest_path[i][j] = adj[i][j]) ;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sortest_path[i][j] = min(sortest_path[i][j],sortest_path[i][k]+sortest_path[k][j]);
                // Or  (with min function)
                // if(sortest_path[i][j] > sortest_path[i][k] + sortest_path[k][j])
                //     sortest_path[i][j] = sortest_path[i][k] + sortest_path[k][j];
            }  
        }
    }    
}

int min(int a, int b){
    return (a<b)?a:b;
}