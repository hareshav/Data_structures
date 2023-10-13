#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int top;
    int size;
    int *s;
}st;
void create(struct stack *st){
    st->size=10;
    st->top=-1;
    st->s=(int *)malloc(sizeof(int )*st->size);
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
    else{
    int x=st->s[st->top];
    st->top--;
    return x;}
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/') return 0;
    return 1;
}
int eval(char *x,struct stack *st){
    int i=0,fi=0;
    while(x[i]!='\0'){
        if(!isOperand(x[i])){
            push(st,x[i]-48);
        }
        else{
            int c1=pop(st);
            int c2=pop(st);
            if(x[i]=='+'){
                
            }
        }
    }
}
int main(){
    char a[80]="123+++";
    
}