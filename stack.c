#include<stdio.h>
#include<stdlib.h>
int size;
struct stack{
    int *stk;
    int top;
}s;

void push(int x){
    if(s.top==size-1){
        printf("stack overflow\n");
        printf("reallocating memory\n");
        size++;
        s.stk = (int *)realloc(s.stk,size*sizeof(int));
    }
    else {
        s.top++;
        *(s.stk+s.top)= x;
    }
}

void pop(){
    if(s.top==-1){
        printf("stack overflow\n");
    }
    else {
        printf("element deleted is: %d\n",*(s.stk+s.top));
        s.top--;
    }
}

void peek(){
    if(s.top==-1){
        printf("stack underflow\n");
    }
    else {
        printf("peek element is: %d\n",*(s.stk+s.top));
    }
}

void display(){
    if(s.top==-1){
        printf("stack underflow\n");
    }
    else{
            printf("stack elements are: \n");
            for(int i=s.top;i>=0;i--){
                printf("\t%d\n",*(s.stk+i));
        }
    }
}

void main(){
    int x,choice;
    s.top=-1;
    printf("enter the size: ");
    scanf("%d",&size);
    s.stk = (int *)calloc(size,sizeof(int));
    printf("\nmain menu\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    for(;;){
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the element to be pushed: ");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Execution successfull...Thank you...\n");
                    exit(0);
            default: printf("invalid choice...try again...\n");

        }
    }
}
