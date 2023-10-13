+#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    char *s;
}st;
void create(struct stack *st){
    st->size=10;
    st->top=-1;
    st->s=(char*)malloc(sizeof(char)*st->size);
}
void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%c ",st.s[i]);
    }printf("\n");
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
    char x=st->s[st->top];
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
int isBal(struct stack *st,char *n){
    for(int i=0;n[i]!='\0';i++){
        if(n[i]=='('||n[i]=='{'||n[i]=='['){
            push(st,n[i]);
        }
        else if(n[i]==')'){
            if(st->top==-1)return 0;
            char x=pop(st);
            if(x!='(') return 0;
        }
        else if(n[i]=='}'){
            if(st->top==-1)return 0;
            char x=pop(st);
            if(x!='{') return 0;
        }
        else if(n[i]==']'){
            if(st->top==-1)return 0;
            char x=pop(st);
            if(x!='[') return 0;
        }
    }
    if(st->top==-1) return 1;
    else return 0;
}

int main()
{
	create(&st);
    char *s="{()}}";
    printf("%d",isBal(&st,s));
    display(st);
    
}
