#include <iostream>
using namespace std;
class Node{
public:
    Node * left;
    int val;
    Node * right;
};
Node *root;
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
class Stack{
private:
    int size;
    int top;
    Node** S;
public:
    Stack(int size);
    ~Stack();
    void push(Node* x);
    Node* pop();
    int isFull();
    int isEmpty();
    void display();
    Node* stackTop();
};
 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    S = new Node*[size];
}
 
Stack::~Stack() {
    delete[] S;
}
 
void Stack::push(Node* x) {
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}
 
Node* Stack::pop() {
    Node* x;
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
Node* Stack::stackTop() {
    if (isEmpty()){
        return NULL;
    }
    return S[top];
}
 
 
void create(){
    Queue q(100);
    int t[14]={1,2,3,4,5,6,7};
    int x=0;
    
    if(t[x]!=-1){
        root=new Node;
        root->val=t[x++];
        q.enqueue(root);
    }
    while(!q.isEmpty()&&x<7){
        Node *c=q.dequeue();
       
        if(t[x]!= -1){
            Node *r=new Node;
            r->val=t[x++];
            r->left=r->right=NULL;
            c->left=r;
            q.enqueue(r);
        }
        if(t[x]!=-1){
            Node *r=new Node;
            r->val=t[x++];
            r->left=r->right=NULL;
            c->right=r;
            q.enqueue(r);
        }
    }
    
    
}
void i(Node *p){
  if(p) { i(p->left);
    cout<<p->val<<",";
    i(p->right);
}}
void iPreorder(Node *root){
    Stack s(100);
    Node *t=root;
    while(t||!s.isEmpty()){
        if(t){
            cout<<t->val<<",";
            s.push(t);
            t=t->left;
            
        }
        else{
            t=s.pop();
            t=t->right;
        }
    }
}
void iInorder(Node *root){
    Stack s(100);
    Node *t=root;
    while(t||!s.isEmpty()){
        if(t){
            s.push(t);
            t=t->left;
        }
        else{
            t=s.pop();
            cout<<t->val<<",";
            t=t->right;
        }
    }
}
void levelorder(Node *root){
    Queue q(100);
    q.enqueue(root);
    while(!q.isEmpty()){
        Node *t=q.dequeue();
        cout<<t->val<<",";
        if(t->left){
            q.enqueue(t->left);
        }
        if(t->right){
            q.enqueue(t->right);
        }
    }
}
int height(Node *root){
    if(root){
        int x=height(root->left);
        int y=height(root->right);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    return 0;
}
int count(Node *root){
    if(root){
        int x=count(root->left);
        int y=count(root->right);
        return x+y+1;
    }
    return 0;
}
int main()
{   
        
	create();
    levelorder(root);
	cout<<endl<<count(root);
    return 0;
}
