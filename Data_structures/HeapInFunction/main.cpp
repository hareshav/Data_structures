#include<stdio.h>
#include<stdlib.h>
int * fun(int size){
    int *p=(int *)malloc(size*sizeof(int));//heap declaration
    for(int i=0;i<size;i++){
        p[i]=i%3;
    }
    return p;
}


int main(){
    int *s;
    s=fun(5);//pointer to accesss heap
    for(int i=0;i<5;i++){
        printf("%d ",s[i]);
    }
    
}