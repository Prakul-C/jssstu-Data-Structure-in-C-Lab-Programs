#include <stdio.h> 
#include <stdlib.h> 
//Structure for a single Node 
struct NODE 
{ 
    int item; 
    struct NODE *link; //Pointer to next Node 
}; 
typedef struct NODE * NODE; 
//Function to create a Node 
NODE getnode(int val) 
{ 
    NODE temp; //Pointer to newly created node 
    temp = (NODE)malloc(sizeof(struct NODE)); 
    temp -> item = val; 
    temp-> link = temp; 
    return temp; 
} 
//Function to insert Node at front 
NODE insertfront(NODE last, int val) 
{ 
    NODE temp; 
    temp = getnode(val); //Pointer to newly created node 
    if(last == NULL) 
    { 
        return temp; 
    } 
    else 
    { 
        temp->link=last->link; 
        last->link=temp; 
        return last; 
    } 
} 
//Function to insert Node at Rear End 
NODE insertrear(NODE last, int val) 
{ 
    NODE temp; 
    temp = getnode(val); //Pointer to newly created node 
    if(last == NULL) 
    { 
        return temp; 
    } 
 
 
    else 
    { 
        temp->link=last->link; 
        last->link=temp; 
        return temp; 
    } 
} 
//Function to delete Node at front 
NODE deletefront(NODE last) 
{ 
    NODE cur = last->link; 
    if(last==NULL) 
    { 
        printf("List is empty\n"); 
        return last; 
    } 
    else 
    { 
        last->link=cur->link; 
        free(cur); 
        return last; 
    } 
} 
//Function to delete Node at Rear End 
NODE deleterear(NODE last) 
{ 
    NODE cur=last->link; 
    if(last==NULL) 
    { 
        printf("List is empty\n"); 
        return last; 
    } 
    else 
    { 
         
        while(cur->link!=last) 
        { 
            cur = cur->link; 
        } 
        cur->link = last->link; 
        free(last); 
        return cur; 
    } 
} 
//Function to insert Node at Specified Position 
NODE insertpos(NODE last, int val, int pos) 
{ 
    NODE temp = getnode(val); 
    NODE cur = last->link; //Pointer pointing to current node 
    NODE prev=NULL;//Pointer pointing to previous node 

 
    if(pos==1&&last==NULL) 
    { 
        last = insertfront(last,val); 
        return last; 
    } 
    else if(pos!=1&&last==NULL) 
    { 
        printf("Invalid Position\n"); 
        return last; 
    } 
    else 
    { 
        while(pos!=1) 
        { 
            prev=cur; 
            cur = cur->link; 
            pos--; 
        } 
        temp->link = cur; 
        prev->link = temp; 
        printf("Insertion Succesfull\n"); 
        return last; 
    } 
} 
//Function to delete a Node at Specified Position 
NODE deletepos(NODE last,int pos) 
{ 
    NODE cur,prev; 
    cur = last->link; //Pointer pointing to current node 
    prev = NULL; //Pointer pointing to previous node 
    if(last==NULL) 
    { 
        printf("List Empty\n"); 
        return last; 
    } 
    while(pos != 1) 
    { 
        prev = cur; 
        cur = cur->link; 
        pos--; 
    } 
    prev->link = cur->link; 
    free(cur); //Deleting the Current Node by Deallocating Memory 
    cur = NULL; 
    return last; 
} 
//Function to search a Key element in a list 
int search(NODE last, int key) 
{ 
    int i=1,flag=0,pos=0; 

 
    NODE cur; 
    cur = last->link; 
    while(cur->link!=last->link) 
    { 
        if(cur->item==key) 
        { 
            flag = 1; 
            pos = i; 
            break; 
        } 
        cur = cur->link; 
        i++; 
    } 
    if(flag==1) 
    return pos; 
    else 
    return 0; 
} 
//Function to delete a Key element in a list 
NODE deletebykey(NODE last,int key) 
{ 
    int pos = search(last,key); 
    NODE prev,cur; 
    prev=NULL;cur=last->link; 
    while(pos != 1) 
    { 
        prev = cur; 
        cur = cur->link; 
        pos--; 
    } 
    prev->link = cur->link; 
    free(cur); 
    cur = NULL; 
    return last; 
} 
//Function to display all elements in a list 
void display(NODE last) 
{ 
    NODE cur=last->link; 
    if(last==NULL) 
    { 
        printf("List is Empty\n"); 
    } 
    else 
    { 
        do 
        { 
            printf("%d ",cur->item); 
            cur = cur->link; 
        }while (cur!=last->link); 
 
 
    } 
} 
//Function to create Ordered List 
NODE orderlist(NODE last, int val) 
{ 
    NODE temp = getnode(val); 
    NODE cur = last->link,prev = NULL; 
    while(cur->item<temp->item) 
    { 
        prev = cur; 
        cur = cur->link; 
    } 
    temp->link = cur; 
    prev->link = temp; 
    return last; 
} 
//Function to reverse a linked list 
NODE reverse(NODE last) 
{ 
    NODE cur=last,prev; 
    if(last==NULL) 
    return NULL; 
    if(last==last->link) 
    return last; 
    NODE temp=last->link; 
    NODE first=temp; 
    while(temp!=last) 
    { 
        prev=temp->link; 
        temp->link=cur; 
        cur=temp; 
        temp=prev; 
    } 
    temp->link=cur; 
    return first; 
} 
//Function to create a Copy List 
NODE createcopy(NODE last,NODE copy) 
{ 
    NODE cur=last->link; 
    do 
    { 
        copy=insertrear(copy,cur->item); 
        cur=cur->link; 
    }while(cur!=last->link); 
    return copy; 
} 
void main() 
{ 
    NODE last = NULL; // Pointer to last node of list 
 
 
    NODE copy = NULL; // Poiner to first node of copied list  
    int choice; 
    int key,val,pos; 
    printf("\nMain Menu\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert By Pos\n6.Delete by Pos\n7.Search\n8.Delete By Key\n9.Display\n10.Insert By Order\n11.Reverse\n12.Create Copy\n13.Exit\n"); 


    for(;;) 
    { 
        printf("\nEnter your Choice :"); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     last = insertfront(last,val); 
                     break; 
            case 2 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     last = insertrear(last,val); 
                     break; 
            case 3 : last = deletefront(last); 
                     printf("Deletion Successfull\n"); 
                     break; 
            case 4 : last = deleterear(last); 
                     printf("Deletion Successfull\n"); 
                     break; 
            case 5 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     printf("Enter the position : "); 
                     scanf("%d",&pos); 
                     last = insertpos(last,val,pos); 
                     printf("Insertion Succesfull\n"); 
                     break; 
            case 6 : printf("Enter the position : "); 
                     scanf("%d",&pos); 
                     last = deletepos(last,pos); 
                     printf("Deletion Succesfull\n"); 
                     break; 
            case 7 : printf("Enter the Key : "); 
                     scanf("%d",&key); 
                     pos = search(last,key); 
                     if(pos!=0) 
                     printf("The Key found at %d pos\n",pos); 
                     else 
                     printf("Element not found\n"); 
                     break; 
            case 8 : printf("Enter the Key : "); 
                     scanf("%d",&key); 
                     last = deletebykey(last,key); 
                     printf("Deletion Successfull\n"); 
 
                     break; 
            case 9 : printf("The List is : "); 
                     display(last); 
                     break; 
            case 10 : printf("Enter the Key : "); 
                      scanf("%d",&key); 
                      last = orderlist(last,key); 
                      break; 
            case 11 : last = reverse(last); 
                      display(last); 
                      break; 
            case 12 : printf("Copied List : "); 
                      copy = createcopy(last,copy); 
                      display(copy); 
                      break; 
            case 13 : printf("!!THANK YOU!!\n"); 
                     exit(0); 
            default : printf("Invalid Choice\n Enter again\n"); 
        } 
    } 
} 
