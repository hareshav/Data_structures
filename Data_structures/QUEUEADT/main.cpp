#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int top;
    int bottom;
    int *q;
}qu;
void create(struct queue *qu){
    
    qu->size=10;
    qu->q=(int*)malloc(qu->size*sizeof(int));
    qu->bottom=0;
    qu->top=-1;
}
void push(struct queue *qu,int x){
    if(qu->top+1-qu->bottom==qu->size){
        printf("Queue overflow");
    }
      else{
        qu->top++;
        qu->q[qu->top]=x;
    }
}
void pop(struct queue *qu){
    if(qu->top!=qu->bottom){
        qu->bottom++;
    }
    else{
        printf("Queue Unterflow");
    }
}
void display(struct queue *qu){
    for(int i=qu->bottom;i<qu->top+1;i++){
        printf("%d ",qu->q[i]);
    }
}
int main()
{
    create(&qu);
    push(&qu,5);
    push(&qu,6);
    push(&qu,3);
    pop(&qu);
    push(&qu,5);
    display(&qu);

}
