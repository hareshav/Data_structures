#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *prev;
}*top;
void create(struct ListNode *t,int n){
    t=(struct ListNode *)malloc(sizeof(struct ListNode));
    t->val=n;
    t->prev=NULL;
    top=t;
}
void push(struct ListNode *t,int n){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->val=n;
    p->prev=t;
    top=p;
    
}
void display(struct ListNode *st){
    struct ListNode *p=st;
    while(p){
        printf("%d ",p->val);
        p=p->prev;
    }
}
int pop(struct ListNode *st){
    if(st==NULL){
        printf("Underflow\n");
        return -1;
    }
    int x=st->val;
    struct ListNode *p=st;
    st=st->prev;
    free(p);
    top=st;
    return x;
}
int peek(struct ListNode *st,int pos){
    int x=-1;
    struct ListNode *t=st;
    while(pos---1){
        t=t->prev;
    }
    if(t){
        x=t->val;
    }
    return x;
}
int main()
{
    pop(top);
	create(top,2);
    push(top,3);
    push(top,4);
    push(top,7);
    
    display(top);
    printf("\n%d\n",peek(top,2));
    pop(top);
    display(top);
}
