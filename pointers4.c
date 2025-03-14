#include<stdio.h>
#include<stdlib.h>
void concat(char *,char *);
void main(){
    char str1[100],str2[200];
    char *ps1 = str1;
    char *ps2 = str2;
    printf("enter the first string: ");
    scanf("%s",ps1);
    printf("enter the second string: ");
    scanf("%s",ps2);
    printf("string before concatenation: \n");
    printf("first string: %s",ps1);
    printf("\nsecond string: %s",ps2); 
    concat(ps1,ps2);
    printf("\nfirst string after concatenation: %s",ps1);
}

void concat(char *ps1,char *ps2){
    while(*ps1!='\0'){
        ps1++;
    }
    while(*ps2!='\0'){
        *ps1=*ps2;
        ps1++;
        ps2++;
    }
    *ps1='\0';
}