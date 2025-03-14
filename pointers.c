#include<stdio.h>
#include<stdlib.h>
void main(){
    int x[5],*p,i;
    p=x;
    printf("enter the elements to the array: ");
    for(i=0;i<5;i++)
    scanf("%d",p+i);
    printf("array elements: ");
    for(i=0;i<5;i++);
    printf("%d ",*(p+i));
    p= &x[4];
    printf("\narray elements after reverse: ");
    for(i=0;i<5;i++)
    printf("%d ",*(p-i));
    printf("\n");
}