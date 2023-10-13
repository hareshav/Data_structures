#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int val;
    struct node *next;
}*first;
void create(int *a,int n){
    struct node *t,* last;
    first=(struct node *)malloc(sizeof(struct node));
    first->val=a[0];
    first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->val=a[i];
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=NULL;
}
void insertfirst(int a){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->val=a;
    temp->next=first;
    temp->prev=NULL;
    first->prev=temp;
    first=temp;
}
void insertpos(int a,int b){
    struct node *temp=first;
    while(a--)temp=temp->next;
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->prev=temp;
    t->next=temp->next;
    t->val=b;
    temp->next->prev=t;
    temp->next=t;
}
void insertlast(int a){
    struct node *temp=first;
    while(temp->next){
        temp=temp->next;
    }
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->val=a;
    t->prev=temp;
    t->next=NULL;
    temp->next=t;
}
void display(struct node *p){
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
}
void rdisplay(struct node *p){
    while(p->next){
        p=p->next;
    }
    while(p){
        printf("%d ",p->val);
        p=p->prev;
    }
}
int main()
{
	int a[]={1,2,3,4,5};
    create(a,5);
    insertfirst(6);
    insertlast(7);
    insertpos(3,5);
    display(first);
    printf("\n");
    rdisplay(first);
}
