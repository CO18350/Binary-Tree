#include<stdlib.h>
#include<stdio.h>
struct node{
struct node *left;
int info;
struct node *right;
};
typedef struct node btree;
void insert(btree ** tree, int val){
    btree *temp = NULL;
    if(*tree==NULL)
    {
        temp = (btree *)malloc(sizeof(btree));
        temp->left = temp->right = NULL;
        temp->info = val;
        *tree = temp;
        return;
    }
    if(val<(*tree)->info)
    {
        insert(&(*tree)->left, val);
    }
    else if(val>(*tree)->info)
    {
        insert(&(*tree)->right,val);
    }
}
void display(btree *tree,int n){
    int i,space,k=0;
    if (tree)
    {
        display(tree->left,n-1);
        for(i=1;i<=n+1;++i,k=0){
        for(space=1; space<=n+1-i; ++space)
        {
            printf("  ");
        }
        while(k != 2*i-1)
        {
            printf("%d ",tree->info);
            ++k;
        }
        for(space=1; space<=n+1-i; ++space)
        {
            printf("  ");
        }
        printf("\n");
    }
display(tree->right,n-1);
    }
}
void main(){
    btree *root;
    btree *tmp;
    root = NULL;
    int i,n,key;
    printf("Enter no. of to insert values\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("Enter value %d\n",i);
    scanf("%d",&key);
    insert(&root, key);
    }
    printf("\nDisplay tree\n");
    display(root,n);
}
