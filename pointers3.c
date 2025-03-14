#include<stdio.h>
#include<stdlib.h>
#define size 10
void read(int*,int,int);
void display(int *,int,int);

void main(){
    int *p,m,n,a[size][size];
    printf("enter the order of 2-D array: ");
    scanf("%d%d",&m,&n);
    p = &a[0][0];
    read(p,m,n);
    display(p,m,n);
}

void read(int *p,int m,int n){
    printf("enter the elements for 2-D array: ");
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    scanf("%d",(p+i*n)+j);

}

void display(int *p,int m,int n){
    printf("the array elements are : \n");
     printf("\t");
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    printf("\t%d ",*(p+i*n)+j);
    }
     printf("\n");
      printf("\t");
    }
}
