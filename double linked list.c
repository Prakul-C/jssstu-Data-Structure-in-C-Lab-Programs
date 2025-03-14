
#include <stdio.h> 
#include<stdlib.h> 
//Structure for a single Node 
struct node  
{ 
    int item; 
    struct node * next; //Pointer to next Node 
    struct node * prev; //Pointer to Previous Node 
}; 
//struct node * type defined as NODE 
typedef struct node * NODE; 
//Function to create a Node 
NODE getnode(int val) 
{ 
    NODE temp; //Pointer to newly created node 
    temp = (NODE)malloc(sizeof(struct node)); 
    temp->item=val; 
    temp->next=NULL; 
    temp->prev=NULL; 
    return temp; 
} 
//Function to insert Node at front 
NODE insertfront(NODE first,int val) 
{ 
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
        temp -> next = first; 
        first -> prev = temp; 
        return temp; 
    } 
} 
} 
//Function to insert Node at Rear End 
NODE insertrear(NODE first, int val) 
{ 
    NODE temp,cur; 
 
    temp = getnode(val); //Pointer to newly created node 
    cur = first; //Pointer to Current Node 
    if(first == NULL) 
    { 
        first = temp; 
        return first; 
    } 
    else 
    { 
        while(cur->next!=NULL) 
        { 
            cur = cur->next; 
        } 
        cur->next = temp; 
        temp->prev = cur; 
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
        first = first->next; 
        first->prev = NULL; 
        return first; 
    } 
} 
//Function to delete Node at Rear End 
NODE deleterear(NODE first) 
{ 
    NODE cur = first; //Pointer to Current Node 
    NODE temp=NULL; //Pointer to Previous Node 
    if(first==NULL) 
    { 
        printf("List is empty\n"); 
        return first; 
    } 
    else 
    { 
         
        while(cur->next!=NULL) 
        { 
            temp = cur; 
            cur = cur->next; 

 
        } 
        temp->next = NULL; 
        cur->prev=NULL; 
        free(cur); 
        return first; 
    } 
} 
//Function to insert Node at Specified Position 
NODE insertpos(NODE first, int val, int pos) 
{ 
    NODE temp = getnode(val); 
    NODE cur = first; //Pointer to Current Node 
    NODE previous = NULL; //Pointer to Previous Node 
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
        while(pos!=1&&cur!=NULL) 
        { 
            previous=cur; 
            cur = cur->next; 
            pos--; 
        } 
        temp->next = cur; 
        temp->prev = previous; 
        previous->next = temp; 
        cur->prev=temp; 
        return first; 
    }  
} 
//Function to delete a Node at Specified Position 
NODE deletepos(NODE first,int pos) 
{ 
    NODE after = first; //Pointer to Next Node 
    NODE cur = NULL; //Pointer to Current Node 
    NODE previous = NULL; // Pointer to Previous Node 
    if(first==NULL) 
    { 
        printf("List is empty\n"); 
        return first; 
    } 
    while(pos != 0) 
 
    { 
        previous=cur; 
        cur = after; 
        after = after->next; 
        pos--; 
    } 
    previous->next = after; 
    after->prev=previous; 
    free(cur); //Deleting the Current Node by Deallocating Memory 
    cur = NULL; 
    return first; 
} 
//Function to search a Key element in a list 
int search(NODE first, int key) 
{ 
    int i=1,flag=0,pos=0; 
    NODE cur; 
    cur = first; 
    while(cur->next!=NULL) 
    { 
        if(cur->item==key) 
        { 
            flag = 1; 
            pos = i; 
            break; 
        } 
        cur = cur->next; 
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
    int pos = search(first,key); //Position of the found Key 
    NODE prev,cur; 
    if(pos!=0) 
    { 
        first = deletepos(first,pos); 
        return first; 
    } 
    else 
    { 
        printf("Element not found\n"); 
        return first; 
    } 
} 

 
//Function to display all elements in a list 
NODE display(NODE first) 
{ 
    NODE cur=first; 
    if(first==NULL) 
    { 
    printf("List is Empty\n"); 
    return first; 
    } 
    else 
    { 
        while (cur!=NULL) 
        { 
            printf("%d ",cur->item); 
            cur = cur->next; 
        } 
        return first; 
    } 
} 
//Function to reverse a linked list 
NODE reverse(NODE first) 
{ 
    NODE temp,cur; 
    cur = first; 
    temp=NULL; 
    while(cur!= NULL) 
    { 
        temp = cur->prev; 
        cur->prev = cur->next; 
        cur->next = temp; 
        cur = cur->prev; 
    } 
    if(temp!=NULL) 
    first = temp->prev; 
    display(first); 
    return first; 
} 
NODE orderlist(NODE first, int val) 
{ 
    NODE temp = getnode(val); 
    NODE previous = NULL; 
    NODE cur = first; 
    while(cur->next!=NULL) 
    { 
        if(cur->item>temp->item) 
        { 
            break; 
        } 
        previous=cur; 
        cur = cur->next; 

 
    } 
    temp->next = cur; 
    temp->prev = previous; 
    previous->next = temp; 
    cur->prev=temp; 
    return first; 
} 
//Function to create a Copy List 
NODE createcopy(NODE first, NODE copy) 
{ 
    NODE cur=first; 
    while(cur!=NULL) 
    { 
        copy=insertrear(copy,cur->item); 
        cur=cur->next; 
    } 
    return copy; 
} 
//Main Function 
void main() 
{ 
    NODE first = NULL; //Pointer to first node of list 
    NODE copy = NULL; //Poiner to first node of copied list  
    int choice; 
    int key,val,pos; 
    printf("\nMain Menu\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert By Pos\n6.Delete by Pos\n7.Search\n8.Delete By Key\n9.Display\n10.Reverse\n11.Ordered List\n12.Create Copy\n13.Exit\n"); 

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
                     printf("Insertion Succesfull\n"); 
                     break; 
            case 6 : printf("Enter the position : "); 
                     scanf("%d",&pos); 
                     first = deletepos(first,pos); 
                     printf("Deletion Succesfull\n"); 
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
                     printf("Deletion Successfull\n"); 
                     break; 
            case 9 : display(first); 
                     break; 
            case 10 : first = reverse(first); 
                      break; 
            case 11 : printf("Enter the value : "); 
                     scanf("%d",&val); 
                      first = orderlist(first,val); 
                      break; 
            case 12 : printf("Copied List : "); 
                      copy = createcopy(first,copy); 
                      display(copy); 
                      break; 
            case 13 : printf("!!THANK YOU!!\n"); 
                     exit(0); 
            default : printf("Invalid Choice\n Enter again\n"); 
        } 
    } 
}
