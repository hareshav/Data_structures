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
    st->s=(int *)malloc(sizeof(int)*st->size);
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
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    return 1;
}
int pre(char x){ 
    if(x=='+'||x=='-'){
        return 1;
    }
    if(x=='*'||x=='/'){
        return 2;
    }
    return 0;
}
int stacktop(struct stack st){
    if(st.top==-1){
        return 0;
    }
    return st.s[st.top];
}
int isempty(struct stack st){
    if(st.top==-1) return 1;
    return 0;
}
char *convert(char *infix,struct stack *st){
    char *postfix=(char *)malloc(sizeof(strlen(infix))+1);
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(stacktop(*st))<pre(infix[i])){
                push(st,infix[i]);
                i++;
            }
            else{
                postfix[j++]=pop(st);
            }
        }
    }
    while(st->top!=-1){
        postfix[j++]=pop(st);
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
	create(&st);
    char *i="a+b*c-(d*e)-f";
    char *t=convert(i,&st);
    printf(" %s ",t);
    
}

