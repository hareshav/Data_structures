#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node{
    int data;
    struct Node *Next;
}*first,*last,*first1,*first2;
int max(struct Node*n){
    int m=INT_MIN;
    while(n){
        if(m<n->data){
            m=n->data;
        }
        n=n->Next;
    }return m;
}
int del(struct Node *p,int index){//starts form 1
    int x;
    if(index==1){
        p=first;
        x=first->data;
        first=first->Next;
        free(p);
    }
    else{
        struct Node *p=first;
        struct Node *q=NULL;
        for(int i=0;i<index-1&&p;i++){
            q=p;
            p=p->Next;
        }
        if(p){
            q->Next=p->Next;
            x=p->data;
            free((void*)p);
        }
    }
    return x;
    
}
struct Node* search(struct Node*n,int k){
    while(n){
        if(n->data==k){
            return n;
        }
        n=n->Next;
    }
    return NULL;
} 
int min(struct Node*n){
    int m=INT_MAX;
    while(n){
        if(m>n->data){
            m=n->data;
        }
        n=n->Next;
    }return m;
}
int sum(struct Node*n){
    int s=0;
    while(n){
        s=s+n->data;
        n=n->Next;
    }
    return s;
}
void display(struct Node*n){
    struct Node *p=n;
    while(p){
        printf("%d ",p->data);
         
        p=p->Next;
    }
    
}
void rdisplay(struct Node *n){
    if(n){
        printf("%d ",n->data);
        rdisplay(n->Next);
    }
}
struct Node* impSearch(struct Node *first,int key){
    struct Node *p=first;
    struct Node *q=NULL;
    while(p){
        if(p->data==key){
            q->Next=p->Next;
            p->Next=first;
            first=p;
            return p;
        }
        
        q=p;
        p=p->Next;
    }
    return NULL;
}
void create(int arr[],int n){
    struct Node *last=NULL;
    first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *t=NULL;
    first->data=arr[0];
    first->Next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->Next=NULL; 
        last->Next=t;
        last=t;
    }    
}
int  count(struct Node *N){
    struct Node *p=N;
    int count=0;
    while(p){
        count++;
        p=p->Next;
    }return count;
}
void insert(struct Node *fir,int index,int value){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    p->data=value;
    if(index==0){
        p->Next=fir->Next;
        first=p;
    }
    else{
        while(index---1)
            fir=fir->Next;
        p->Next=fir->Next;
        fir->Next=p;
    }
}
void InsertLast(int x,struct Node**fir){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(!*fir){
        *fir=t;
    }
    else{
        while((*fir)->Next)*fir=(*fir)->Next;
        (*fir)->Next=t;
    }
    t->Next=NULL;
//    first=fir;
}
void insOrted(int x){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    struct Node *q=NULL;
    struct Node *i=first;
    t->data=x;
    while(i){
        if(i->data>x){
            t->Next=i;
            q->Next=t;
            break;
        }
        q=i;
        i=i->Next;
    }
    
}
int isSorted(struct Node *fir){
    int x=INT_MIN;
    struct Node *p=fir;
    while(p){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->Next;
    }
    p=fir;
    return 1;
}
void removeSortedD(struct Node *fir){
    struct Node *p=first->Next;
    struct Node *q=first;
    
    while(p){
        if(p->data==q->data){
            q->Next=p->Next;
            free(p);
            p=q->Next;
        }
        else{
            q=p;
            p=p->Next;
        }
    }
}
void reverseList(struct Node *fir){
    struct Node *p=fir;
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }
    first=q;
}
int isLoop(struct Node *fir){
    struct Node *p,*q;
    p=q=fir;
    do{
        p=p?p->Next:NULL;
        q=q?q->Next:NULL;
        q=q?q->Next:NULL;
        
    }while(q&&p&&p!=q);
    return p==q;
}
int main()
{
    
    int a[]={1,2,3,4,5};
//    t1=first->Next->Next;
//    t2=first->Next->Next->Next->Next;



//    t2->Next=t1;
    
//    InsertLast(3,&first);
////    printf("%d",isLoop(first));
//    InsertLast(7,&first);
//    InsertLast(8,&first);
    create(a,5);
    insert(first,3,2);
//    display(first);
s    
    
}
