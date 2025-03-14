#include <stdio.h> 
#include <stdlib.h> 
//Structure for a single Node 
struct node 
{ 
    int item; 
    struct node *link; //Pointer to next Node 
}; 
//struct node * type defined as NODE 
typedef struct node * NODE; 
//Function to create a Node 
NODE getnode(int val) 
{ 
    NODE temp; //Pointer to newly created node 
    temp = (NODE)malloc(sizeof(struct node)); 
    temp -> item = val; 
    temp-> link = NULL; 
    return temp; 
} 
//Function to insert Node at front 
NODE insertfront(NODE first, int val) 
{ 
    NODE temp; //Pointer to newly created node 
    temp = getnode(val); 
    if(first == NULL) 
    { 
        first = temp; 
        return first; 
    } 
    else 
    { 
        temp -> link = first; 
        return temp; 
    } 
} 
//Function to insert Node at Rear End 
NODE insertrear(NODE first, int val) 
{ 
    NODE temp = getnode(val); //Pointer to newly created node 
    NODE cur = first; //Pointer pointing to current node 
    if(first == NULL) 
    { 
        first = temp; 
 
 
        return first; 
    } 
    else 
    { 
        while(cur->link!=NULL) 
        { 
            cur = cur->link; 
        } 
        cur->link = temp; 
        return first; 
    } 
} 
//Function to delete Node at front 
NODE deletefront(NODE first) 
{ 
    if(first==NULL) 
    { 
        printf("List is empty\n"); 
        return first; 
    } 
    else 
    { 
        first = first->link; 
        return first; 
    } 
} 
//Function to delete Node at Rear End 
NODE deleterear(NODE first) 
{ 
    NODE cur = first; //Pointer pointing to current node 
    NODE prev=NULL; //Pointer pointing to previous node 
    if(first==NULL) 
    { 
        printf("List is empty\n"); 
        return first; 
    } 
    else 
    { 
        while(cur->link!=NULL) 
        { 
            prev = cur; 
            cur = cur->link; 
        } 
        prev->link = NULL; 
        return first; 
    } 
} 
//Function to insert Node at Specified Position 
NODE insertpos(NODE first, int val, int pos) 
{ 
 
 
    NODE temp,cur,prev=NULL; 
    temp = getnode(val); 
    cur = first; 
    if(pos==1&&first==NULL) 
    { 
        first = insertfront(first,val); 
        return first; 
    } 
    else if(pos!=1&&first==NULL) 
    { 
        printf("Invalid Position\n"); 
        return first; 
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
        return first; 
    } 
} 
//Function to delete a Node at Specified Position 
NODE deletepos(NODE first,int pos) 
{ 
    NODE cur,prev; 
    cur = first; 
    prev = NULL; 
    while(pos != 1) 
    { 
        prev = cur; 
        cur = cur->link; 
        pos--; 
    } 
    prev->link = cur->link; 
    free(cur); 
    cur = NULL; //Deleting the Current Node by Deallocating Memory 
    printf("Deletion Succesfull\n"); 
    return first; 
} 
//Function to search a Key element in a list 
int search(NODE first, int key) 
{ 
    int i=1,flag=0,pos=0; 
    NODE cur; 
 
 
    cur = first; 
    while(cur->link!=NULL) 
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
NODE deletebykey(NODE first,int key) 
{ 
    int pos = search(first,key); 
    NODE prev,cur; 
    prev=NULL;cur=first; 
    while(pos != 1) 
    { 
        prev = cur; 
        cur = cur->link; 
        pos--; 
    } 
    prev->link = cur->link; 
    free(cur); 
    cur = NULL; 
    printf("Deletion Successfull\n"); 
    return first; 
} 
//Function to display all elements in a list 
void display(NODE first) 
{ 
    NODE cur=first; 
    if(first==NULL) 
    { 
        printf("List is Empty\n"); 
    } 
    else 
    { 
        while (cur!=NULL) 
        { 
            printf("%d ",cur->item); 
            cur = cur->link; 
        } 

 
    } 
} 
//Function to reverse a linked list 
NODE reverse(NODE first) 
{ 
    NODE temp,cur,prev; 
    temp = first; 
    cur=prev=NULL; 
    while(temp != NULL) 
    { 
        cur = temp->link; 
        temp->link = prev; 
        prev = temp; 
        temp = cur; 
    } 
    first = prev; 
    display(first); 
    return first; 
} 
//Function to create Ordered List 
NODE orderlist(NODE first, int val) 
{ 
    NODE temp = getnode(val); 
    NODE cur = first,prev = NULL; 
    while(cur->item<temp->item) 
    { 
        prev = cur; 
        cur = cur->link; 
    } 
    temp->link = cur; 
    prev->link = temp; 
    return first; 
} 
//Function to create a Copy List 
NODE createcopy(NODE first, NODE copy) 
{ 
    NODE cur=first; 
    while(cur!=NULL) 
    { 
        copy=insertrear(copy,cur->item); 
        cur=cur->link; 
    } 
    return copy; 
} 
void main() 
{ 
    NODE first = NULL; // Pointer to first node of list 
    NODE copy = NULL; // Poiner to first node of copied list  
    int choice; 
    int key,val,pos; 

 
    printf("\nMain Menu\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert By Pos\n6.Delete by Pos\n7.Search\n8.Delete By Key\n9.Display\n10.Insert By Order\n11.Create Copy\n12.Reverse\n13.Exit\n"); 


    for(;;) 
    { 
        printf("\nEnter your Choice :"); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     first = insertfront(first,val); 
                     break; 
            case 2 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     first = insertrear(first,val); 
                     break; 
            case 3 : first = deletefront(first); 
                     printf("Deletion Successfull\n"); 
                     break; 
            case 4 : first = deleterear(first); 
                     printf("Deletion Successfull\n"); 
                     break; 
            case 5 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                     printf("Enter the position : "); 
                     scanf("%d",&pos); 
                     first = insertpos(first,val,pos); 
                     break; 
            case 6 : printf("Enter the position : "); 
                     scanf("%d",&pos); 
                     first = deletepos(first,pos); 
                     break; 
            case 7 : printf("Enter the Key : "); 
                     scanf("%d",&key); 
                     pos = search(first,key); 
                     if(pos!=0) 
                     printf("The Key found at %d pos\n",pos); 
                     else 
                     printf("Element not found\n"); 
                     break; 
            case 8 : printf("Enter the Key : "); 
                     scanf("%d",&key); 
                     first = deletebykey(first,key); 
                     break; 
            case 9 : display(first); 
                     break; 
            case 10 :printf("Enter the value : "); 
                     scanf("%d",&val);  
                     first = orderlist(first,val); 

 
                     break; 
            case 11 : copy = createcopy(first,copy); 
                     printf("Copied List : "); 
                     display(copy); 
                     break; 
            case 12 : first = reverse(first); 
                      break; 
            case 13 : printf("!!THANK YOU!!\n"); 
                     exit(0); 
            default : printf("Invalid Choice\n Enter again\n"); 
        } 
    } 
} 
