#include<stdio.h>
#include<stdlib.h>
void read(int *,int);
void display(int *,int);
void reverse(int *,int);
void main(){
    int size=5,arr[size];
    read(arr,size);
    printf("array elements before reversing: ");
    display(arr,size);
    reverse(arr,size);
    printf("\narray elements after reversing: ");
    display(arr,size);
}
void read(int *p,int size){
    printf("enter %d elements: ",size);
    for(int i=0;i<size;i++)
    scanf("%d",(p+i));

}
void display(int *p,int size){
    for(int i=0;i<size;i++)
    printf("%d ",*(p+i));
}

void reverse(int *p,int size){
    int *start = p;
    int *end = p+size-1;
    int temp;
    while(start<end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}