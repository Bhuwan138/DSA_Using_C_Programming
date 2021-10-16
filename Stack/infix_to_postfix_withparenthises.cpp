#include<stdio.h>

void convert(char[] , char[]);

int main(){
    char infix[50],postfix[50];
    printf("Please enter infix expression : ");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("Postfix expression : %s", postfix);
    return 0;
}

void convert(char infix[], char postfix[]){
    int i,j=0;
    for(i=0; infix[i] != '\0'; i++){
        postfix[j] = infix[i];
        ++j;
    }

    postfix[j] == '\0';
}


