#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    int *s;
}st;
void create(struct stack *st){
    st->size=10;
    st->top=-1;
    st->s=(int *)malloc(sizeof(int)*st->size);
}
int isEmpty(struct stack st){
    if(st.top==-1) return 1;
    return 0;
}
void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
}
void push(struct stack *st,int x){
    if(st->size-st->top==1){
        printf("overflow\n");
        return;
    }
    st->top++;
    st->s[st->top]=x;
}
int pop(struct stack *st){
    if(st->top==-1){
        printf("Stack Underflow\n");
    }
    int x=st->s[st->top];
    st->top--;
    return x;
}
int peek(struct stack st,int pos){
    int x=-1;
    if(pos+1>st.top){
        return x;
    }
    x=st.top-pos+1;
    return x;
        
}
int main()
{
	create(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,2);
    display(st);
    printf("\n%d\n%d\n\n",pop(&st),peek(st,2));
    display(st);
}
