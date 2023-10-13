#include <iostream>
#include <stdio.h>
using namespace std;
class Node{
public:
    Node* lchild;
    int val;
    Node* rchild;
}; 
class Queue{
private:
    int size;
    int front;
    int rear;
    Node ** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        return;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        return nullptr;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 

#include <stdlib.h>
struct stack{
    int top;
    int size;
    Node **s;
};
void creates(struct stack *st){
    st->size=10;
    st->top=-1;
    st->s=(Node **)malloc(sizeof(Node*)*st->size);
}

void push(struct stack *st,Node * x){
    if(st->size-st->top==1){
        printf("overflow\n");
        return;
    }
    st->top++;
    st->s[st->top]=x;
}
Node* pop(struct stack *st){
    if(st->top==-1){
        return nullptr;
    }
    Node* x=st->s[st->top];
    st->top--;
    return x;
}
int isEmpty(struct stack st){
    if(st.top==-1) return 1;
    return 0;
}
Node *root=new Node;
void createtree(){
    Node *p,*t;
    int x=0;
    int tr[14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    Queue q(10);
    
    root->val=tr[x++];
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p=q.dequeue();
        if(tr[x]!=-1  && x<14){
            t=new Node;
            t->val=tr[x];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        x++;
        if(tr[x]!=-1 && x<14){
            t=new Node;
            t->val=tr[x++];
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void preorder(Node * p){
    if(p){
        cout<<p->val<<",";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(Node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->val<<",";
        inorder(p->rchild);
    }
}
void itrepreorder(Node *p){
    
    struct stack st;
    creates(&st);
    while(p!=NULL||!isEmpty(st)){
        if(p){
            cout<<p->val<<",";
            push(&st,p);
            p=p->lchild;
        }
        else{
            p=st.s[st.top];
            pop(&st);
            p=p->rchild;
//            cout<<";";
        }
//        cout<<"isEmp:"<<isEmpty;
    }
}
void itreinorder(Node *p){
    struct stack st;
    creates(&st);
    while(p!=NULL||!isEmpty(st)){
        if(p){
            push(&st,p);
            p=p->lchild;
        }
        else{
            p=st.s[st.top];
            cout<<p->val<<",";
            pop(&st);
            p=p->rchild;
//            cout<<";";
        }
//        cout<<"isEmp:"<<isEmpty;
    }
}
void levelorder(Node *p){
    Node *r;
    Queue q(20);
    q.enqueue(p);
    cout<<p->val<<",";
    while(!q.isEmpty()){
        r=q.dequeue();
        if(r->lchild){
            cout<<r->lchild->val<<",";
            q.enqueue(r->lchild);
        }
        if(r->rchild){
            cout<<r->rchild->val<<",";
            q.enqueue(r->rchild);
        }
    }
}
int height(Node *p){
    int x=0;
    int y=0;
    if(!p) return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y) return x+1;
    return y+1;
}
int count(Node *p){
    if (!p) return 0;
    return count(p->lchild)+count(p->rchild)+1;
}
int main(){
    createtree();
    
    inorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl<<count(root);
    return 0;
}