#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int top;
    int size;
    char *s;
}st;
void create(struct stack *st){
    st->size=10;
    st->top=-1;
    st->s=(char *)malloc(sizeof(char)*st->size);
}
void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
}
void push(struct stack *st,char x){
    if(st->size-st->top==1){
        printf("overflow\n");
        return;
    }
    st->top++;
    st->s[st->top]=x;
}
char pop(struct stack *st){
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
int pre(char x){
    if(x=='*'||x=='/'){
        return 2;
    }
    if(x=='+'||x=='-'){
        return 3;
    }
    return 1;
}
char stacktop(struct stack *st){
    if(st->top!=-1){
        return st->s[st->top];
    }
    
    
}
char* infixToPostfix(char *p,struct stack *st){
    char *q=(char *)malloc(strlen(p)+1);
    int i=0,j=0;
    while(p[i]!='\0'){
      int x=pre(stacktop(st));
      int y=pre(p[i]);
        if(x<y){
           q[j++]=pop(st);
        }
        
        push(st,p[i++]);
        
    }
    while(stacktop(st)!=-1){
      q[j++]=pop(st);
    }
    q[j]='\0';
    return q;
} 
int main(){
    create(&st);
    printf("%s ",infixToPostfix("a+b*c*r*p*d/b",&st));
}
