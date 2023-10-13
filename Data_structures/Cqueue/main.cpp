#include <stdio.h>
#define max 5
int q[max],front=-1,rear=-1;
void enqueue(int x){
    if((front-1)%max==(rear)%max) printf("Queue FUll");
    if(front==-1&&rear==-1){
        front=0;
    }
    rear=(rear+1)%max;
    q[rear]=x;
}
void display(){
    int front=front;
    while((rear+1)%max!=front%max){
        printf("%d ",q[front]);
        front=(front+1)%max;
    }
}
int dequeue(){
    if(front==-1&&rear==-1){
        printf("EMPTY");
    }
    int x=q[(front)%max];
    front=(front+1)%max;
    return x;
}
int main()
{
	enqueue(1);
    enqueue(3);
    enqueue(6);
    
//    enqueue(5);
//    enqueue(9);
//    enqueue(7);
    
    display();

}
