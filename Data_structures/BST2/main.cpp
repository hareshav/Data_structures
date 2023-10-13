#include <iostream>
using namespace std;
class Node{
public:
    Node* left;
    int val;
    Node* right;
}*root;
Node*  Cinsert(Node *p,int x){
    if(!p){
        Node *t;
        t=new Node;
        t->val=x;
        t->left=t->right=NULL;
        return t;
    }
    else{
        if(p->val>x){
            p->left=Cinsert(p->left,x);
        }
        else{
            p->right=Cinsert(p->right,x);
        }
    }
    return p;
}
void in(Node *p){
    if(p){
        in(p->left);
        cout<<p->val<<",";
        in(p->right);
    }
}
int height(Node *p){
    if(p){
        int x=height(p->left);
        int y=height(p->right);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    return 0;
}
Node * inpre(Node *p){
    Node *q=p;
    while(q&&q->right){
        q=q->right;
    }
    return q;
}
Node * insucc(Node *p){
    Node *q=p;
    while(q&&q->left){
        q=q->left;
    }
    return q;
}
Node * deletE(Node *p,int x){
    Node *q=NULL;
    if(!p)return NULL;
    if(!p->left&&!p->right){
        if(p==root){
            root=NULL;
        }
        delete p;
        return NULL;
    }
    if(p->val>x){
        p->left=deletE(p->left,x);
    }
    else if(p->val<x){
        p->right=deletE(p->right,x);
    }
    else{
        if(height(p->left)<height(p->right)){
            q=insucc(p->right);
            if(q)p->val=q->val;            
            p->right=deletE(p->right,q->val);
        }
        if(height(p->left)>=height(p->right)){
            q=inpre(p->left);
            if(q)p->val=q->val;            
            p->left=deletE(p->left,q->val);
        }
    }
    return p;
}
int main()
{
    root=Cinsert(root,5);
    Cinsert(root,7);
    Cinsert(root,3);
    Cinsert(root,4);
//    Cinsert(root,2);
    in(root);
    deletE(root,3);
    in(root);
}
