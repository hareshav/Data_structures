#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node *root,int val){
    if(!root){
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->data=val;
        t->left=t->right=NULL;
        return t;
    }
    else if(root->data>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct node * deleteT(struct node *root,int val){
    if(root->data>val){
        root->left=deleteT(root->left,val);
    }
    else if(root->data<val){
        root->right=deleteT(root->right,val);
    }
    else{
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        struct node *t=root->right;
        while(t&&t->left){
            t=t->left;
        }
        root->data=t->data;
        root->right=deleteT(root->right,t->data);
    }
    return root;
}
void levelorder(struct node*root,int l){
    if(!root){
        return;
    }
    if(l==1){
        printf("%d ",root->data);
    }
    levelorder(root->left,l-1);
    levelorder(root->right,l-1);
    
    
}
int height(struct node*root){
    if(!root)return 0;
    int x=height(root->left);
    int y=height(root->right);
    if(x>y){
        return x+1;
    }
    return y+1;
}
void level(struct node*root){
    int h=height(root);
//    printf("%d ",root->data);
    for(int i=0;i<=h;i++){
        levelorder(root,i);
    }
}
int countleaf(struct node*root){
    if(root==NULL)return 0;
    if(root&&root->left==NULL &&root->right==NULL){
        return 1;
    }
    return countleaf(root->left)+countleaf(root->right);
}
int min(struct node *root){
    if(root==NULL){
        return 999;
    }
    int x=min(root->left);
    int y=min(root->right);
    if(x>y){
        if(root->data>y)
            return y;
        return root->data;
    }
    if(root->data>x){
        return x;
    }
    return root->data;
}
int max(struct node *root){
    if(root==NULL){
        return -999;
    }
    int x=max(root->left);
    int y=max(root->right);
    if(x<y){
        if(root->data<y)
            return y;
        return root->data;
    }
    if(root->data<x){
        return x;
    }
    return root->data;
}
int main()
{
	struct node *root=NULL;
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,8);
    root=insert(root,10);
//    printf("%d ",height(root));
    level(root);
    printf("%d ",min(root));
//    inorder(root);
}
