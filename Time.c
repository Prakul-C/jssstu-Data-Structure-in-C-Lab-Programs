#include<stdio.h>
#include<stdlib.h>

struct TIME {
    int hr,min,sec;
};

typedef struct TIME Time;

void read(Time *);
void display(Time *);
void update(Time *);
void add(Time *,Time *,Time *);

void main(){
    int choice;
    Time T1,T2,T3,T4;
    for(;;){
        printf("\nenter the choice: ");
        printf("main menu\n1.read\n2.update\n3.add times\n4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Reading T1....\n");
                    read(&T1);
                    printf("Reading T2....\n");
                    read(&T2);  
                    printf("The time your entered are: \n");
                    printf("Time T1=");
                    display(&T1);
                    printf("\nTime T2=");
                    display(&T2);
                    printf("\n");
                    break;
            case 2: printf("enter the time to be updated: \n");
                    read(&T3);
                    printf("time before updation is ");
                    display(&T3);
                    update(&T3);
                    printf("\ntime after updation is ");
                    display(&T3);
                    break;
            case 3: printf("Time T1=");
                    display(&T1);
                    printf("\nTime T2=");
                    display(&T2);
                    add(&T1,&T2,&T4);
                    printf("\nthe added time is ");
                    display(&T4);
                    break;
            case 4: printf("Thank you...\n");
                    exit(0);
            default : printf("\ninvalid choice...Try again...\n");

        }
    }
}

void read(Time *T){
    printf("enter the time in hour:minute:second : ");
    scanf("%d %d %d",&T->hr,&T->min,&T->sec);

}

void display(Time *T){
    printf("%d:%d:%d",T->hr,T->min,T->sec);

}

void update(Time *T){
    T->sec++;
    if(T->sec>=60){
        T->min++;
        T->sec = T->sec%60;
        if(T->min>=60){
            T->hr++;
            T->min = T->min%60;
            if(T->hr>=24)
            T->hr = T->min = T->sec = 0;
        }
    }
}

void add(Time *T1,Time *T2,Time *T3){
    T3->hr = T3->min = T3->sec = 0;
    T3->hr = T1->hr + T2->hr;
    T3->min = T1->min + T2->min;
    T3->sec = T1->sec + T2->sec;
    if(T3->sec>=60){
        T3->min++;
        T3->sec = T3->sec%60;
        if(T3->min>=60){
            T3->hr++;
            T3->min = T3->min%60;
            if(T3->hr>=24)
            T3->hr = T3->min = T3->sec = 0;
        }
    }
}
