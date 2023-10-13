#include <iostream>
using namespace std;

class Node{
public:
    class Node* left;
    int val;
    class Node* right;
};
void insert(Node *root,int key){
    Node *p=root,*q;
    while(p){
        q=p;
        if(p->val==key)
            return;
        else if(p->val>key){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    p=new Node;
    p->val=key;
    p->left=p->right=NULL;
    if(q->val>key)
        q->left=p;
    else
        q->right=p;
}
void Delete(Node *root,int key){
    
}
void inorder(Node*p){
    if(p){
        
        inorder(p->left);
        cout<<p->val<<",";
        inorder(p->right);
    }
}
int main()
{
    Node *root=new Node;
    root->val=5;
    root->left=root->right=NULL;
	insert(root,7);
    insert(root,3);
    insert(root,2);
    insert(root,9);
    insert(root,4);
    
    inorder(root);
	return 0;
}
