#include<stdio.h>
#include<stdlib.h>
int size,N,i,j;

struct student {
    char name[30];
    int regno;
    int marks[3];
    float avg;
};
typedef struct student * S;


void read(S st){
    printf("enter the number of students: ");
    scanf("%d",&N);
    if(N>size){
        printf("insuffient space...\n");
        printf("creating space by reallocating memory\n");
        st = (S)realloc(st,(N-size)*sizeof(struct student));
    }
    for(i=0;i<N;i++){
        printf("enter the name and register number of the student %d: ",i+1);
        scanf("%s %d",(st+i)->name,&(st+i)->regno);
        printf("enter the marks scored in three tests: ");
        for(j=0;j<3;j++){
            scanf("%d",&(st+i)->marks[j]);
        }
    }
}

void display(S st){
    if(N==0){
        printf("list is empty\n");
        return;
    }
    printf("the details of %d students are: \n",N);
    printf("Reg_no\tname\t\ttest 1\ttest 2\ttest 3\n");
    for(i=0;i<N;i++){
        printf("%d\t%s\t\t",(st+i)->regno,(st+i)->name);
        for(j=0;j<3;j++){
            printf("%d\t",(st+i)->marks[j]);
        }
        printf("\n");
    }

}

void avg(S st){
    int k,sum[N],temp;
    for(i=0;i<N;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3-j-1;k++){
                if((st+i)->marks[k]>(st+i)->marks[k+1]){
                    temp = (st+i)->marks[k];
                    (st+i)->marks[k] = (st+i)->marks[k+1];
                    (st+i)->marks[k+1] = temp;
                }
            }
        }
    }
for(i=0;i<N;i++){
    sum[i] = (st+i)->marks[1]+(st+i)->marks[2];
    (st+i)->avg = (float)sum[i]/2;
}

printf("the details of %d students are: \n",N);
printf("Reg_no\tname\t\ttest 1\ttest 2\ttest 3\tAverage\n");
for(i=0;i<N;i++){
    printf("%d\t%s\t\t",(st+i)->regno,(st+i)->name);
    for(j=0;j<3;j++){
        printf("%d\t",(st+i)->marks[j]);
    }
    printf("%.2f",(st+i)->avg);
    printf("\n");
}
}

void main(){
    int choice;
    printf("enter the size: ");
    scanf("%d",&size);
    S st = (S)malloc(size*sizeof(struct student));
    printf("menu\n1.input\n2.display\n3.average\n4.exit\n");
    for(;;){
    printf("enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: read(st);
                break;
        case 2: display(st);
                break;
        case 3: avg(st);
                break;
        case 4: printf("Thank you...\n");
                exit(0);
        default: printf("invalid choice..enter again\n");
                    free(st);
                    st=NULL;

                }
    }

}
