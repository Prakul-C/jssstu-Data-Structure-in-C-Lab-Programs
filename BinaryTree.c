#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};

typedef struct node* NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE insert(NODE root) {
    NODE temp, cur, prev;
    int item;
    temp = getnode();
    printf("Enter the item to be inserted\n");
    scanf("%d", &item);
    temp->info = item;
    temp->lchild = temp->rchild = NULL;
    if (root == NULL) return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL) {
        prev = cur;
        cur = (item < cur->info) ? cur->lchild : cur->rchild;
    }
    if (item < prev->info)
        prev->lchild = temp;
    else
        prev->rchild = temp;
    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->info);
        inorder(root->rchild);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->info);
    }
}

NODE search(int item, NODE root, NODE *parent) {
    NODE temp = root;
    *parent = NULL;
    while (temp != NULL && item != temp->info) {
        *parent = temp;
        temp = (item < temp->info) ? temp->lchild : temp->rchild;
    }
    return temp;
}

NODE delete_item(int item, NODE root) {
    NODE cur, parent, suc, temp;
    cur = search(item, root, &parent);
    if (cur == NULL) {
        printf("Item not found\n");
        return root;
    }
    if (cur->lchild != NULL && cur->rchild != NULL) {
        parent = cur;
        suc = cur->rchild;
        while (suc->lchild != NULL) {
            parent = suc;
            suc = suc->lchild;
        }
        cur->info = suc->info;
        cur = suc;
    }
    temp = (cur->lchild != NULL) ? cur->lchild : cur->rchild;
    if (parent == NULL) root = temp;
    else if (parent->lchild == cur) parent->lchild = temp;
    else parent->rchild = temp;
    free(cur);
    return root;
}

int count_nodes(NODE root) {
    if (root == NULL) return 0;
    return 1 + count_nodes(root->lchild) + count_nodes(root->rchild);
}

int height(NODE root) {
    if (root == NULL) return 0;
    int left = height(root->lchild);
    int right = height(root->rchild);
    return 1 + (left > right ? left : right);
}

  void Max(NODE root)
{
 NODE temp,cur=NULL;
 if(root==NULL) 
 {
 printf("\nEmpty tree");
  return;
 }
  temp=root;
 while(temp->rchild!=NULL)
 {
    cur=temp;
   temp=temp->rchild;}
 printf("\n The largest element in the tree is %d",temp->info);
 if(cur==NULL){
    printf("no parent");
 }
 else{
    printf("parent node is %d",cur->info);
 }
}

void Min(NODE root)
{
 NODE temp,cur=NULL;
 if(root==NULL) 
 {
 printf("\nEmpty tree");
  return;
 }
  temp=root;
 while(temp->lchild!=NULL)
 {
   temp=temp->lchild;}
 printf("\n The smallest element in the tree is %d",temp->info);
}

int main() {
    NODE root = NULL, temp, parent;
    int choice, item;
    while (1) {
        printf("\n1: Insert  2: Preorder\n3: Postorder 4: Inorder\n5: Search 6: Delete\n7: Max Node\n8: Count Nodes\n9: Height\n10: BFS Traverasal\n11.Min node\n12.number of leaf nodes\n13.EXit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: root = insert(root); break;
            case 2: preorder(root); printf("\n"); break;
            case 3: postorder(root); printf("\n"); break;
            case 4: inorder(root); printf("\n"); break;
            case 5: 
                printf("Enter item to search: ");
                scanf("%d", &item);
                temp = search(item, root, &parent);
                if (temp)
                    printf("Found node: %d%s\n", temp->info, parent ? ", Parent exists" : ", No parent");
                else
                    printf("Not found\n");
                break;
            case 6: 
                printf("Enter item to delete: ");
                scanf("%d", &item);
                root = delete_item(item, root);
                break;
            case 7: max_node(root); break;
            case 8: printf("Total nodes: %d\n", count_nodes(root)); break;
            case 9: printf("Height: %d\n", height(root)); break;
            case 10: bfs(root);
                     break;
            case 11: Min(root);
	                 break;
            case 12: printf("\nNumber of leaf nodes are %d\n",leaf(root)); 
	                break;
            case 13: exit(0);
        }
    }
}
