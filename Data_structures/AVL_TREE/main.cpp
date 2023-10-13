#include <iostream>
class Node{
public:
    Node *left;
    int val;
    int height;
    Node *right;
}*root;
int Height(Node *p){
    if(p){
        int x=Height(p->left);
        int y=Height(p->right);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    return 0;
}
int balanced(Node *p){
    if(!p)return 0;
    return (Height(p->left)-Height(p->right)); 
}
Node *LLrotation(Node **p){
    Node *teL=(*p)->left;
    Node *telR=(*p)->left->right;
    teL->right=(*p);
    (*p)->left=telR;
    (*p)->height=Height(*p);
    teL->height=Height(*p);
    return teL;
}
Node *LRrotation(Node **p){
    Node *pl=(*p)->left;
    Node *plr=pl->right;
    (*p)->left=plr->right;
    pl->right=plr->left;
    plr->left=pl;
    plr->right=(*p);
    (*p)->height=Height(*p);
    plr->height=Height(plr);
    pl->height=Height(pl);
    return plr;
}
Node *RRrotation(Node **p){
    Node *pr=(*p)->right;
    Node *prl=pr->left;
    (*p)->right=prl;
    pr->left=*p;
    pr->height=Height(pr);
    (*p)->height=Height(*p);
    return pr;
}
Node *RLrotation(Node **p){
    Node *pl=(*p)->right;
    Node *plr=pl->left;
    (*p)->right=plr->left;
    pl->left=plr->right;
    plr->right=pl;
    plr->left=(*p);
    (*p)->height=Height(*p);
    plr->height=Height(plr);
    pl->height=Height(pl);
    return plr;
}
Node*  Cinsert(Node *p,int x){
    if(!p){
        Node *t;
        t=new Node;
        t->val=x;
        t->height=1;
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
    p->height=Height(p);
    if(balanced(p)==2&&balanced(p->left)==1)
        return LLrotation(&p);
    if(balanced(p)==2&&balanced(p->left)==-1)
        return LRrotation(&p);
    if(balanced(p)==-2&&balanced(p->left)==-1)
        return RRrotation(&p);
    if(balanced(p)==-2&&balanced(p->left)==1)
        return RLrotation(&p);
        
    return p;
}
void inorder(Node *p){
    if(p){
        inorder(p->left);
        std::cout<<p->val<<",";
        inorder(p->right);
    }
}
void iorder(Node *p){
    if(p){
        
        std::cout<<p->val<<",";
        iorder(p->left);
        iorder(p->right);
    }
}
int main()
{
	root=Cinsert(root,50);
    root=Cinsert(root,10);
    root=Cinsert(root,30);
    
    inorder(root);
    std::cout<<std::endl;
    iorder(root);
}
