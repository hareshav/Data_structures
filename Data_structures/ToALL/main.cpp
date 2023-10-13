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
    else{
    char x=st->s[st->top];
    st->top--;
    return x;}
}
int peek(struct stack st,int pos){
    int x=-1;
    if(pos+1>st.top){
        return x;
    }
    x=st.top-pos+1;
    return x;
}
int pre(char x,int isstack){
    if(isstack==1){
        if(x=='+'||x=='-')return 2;
        if(x=='*'||x=='/')return 4;
        if(x=='^')return 5;
        return 0;
    }
    if(x=='+'||x=='-')return 1;
        if(x=='*'||x=='/')return 3;
        if(x=='^')return 6;
        if(x=='(')return 7;
        return 0;
}
char stacktop(struct stack *st){
    if(st->top!=-1){
        return st->s[st->top];
    }
    
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='/'||x=='*'||x=='^'||x=='('||x==')')return 0;
    return 1;
}
char *convert(char *p,struct stack *st){
    char *q=(char *)malloc(strlen(p)+1);
    int i=0,j=0;
    while(p[i]!='\0'){
      if(isOperand(p[i])) {
          q[j++]=p[i++];
        continue;
      }
      int x=pre(stacktop(st),1);
      int y=pre(p[i],0);
        if(x>y){
            char x=pop(st);
            if(x!='('&&x!=')')
            q[j++]=x;
        }
        
        push(st,p[i++]);
        
    }
    while(stacktop(st)!=-1){
      char x=pop(st);
      if(x!='('&&x!=')')
        q[j++]=x;
    }
    q[j]='\0';
    return q;
}
int main()
{
	create(&st);
    char *i="((a+b)*c)-f^e^h";
    char *t=convert(i,&st);
    printf(" %s ",t);
    
}