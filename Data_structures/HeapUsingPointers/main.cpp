#include<stdio.h>
#include<stdlib.h>
int main(){
    int *a=(int *)malloc(5*sizeof(int));//heap declaration
    a[0]=5;a[1]=52;a[2]=25;a[3]=48;a[4]=16;
    for(int i=0;i<5;i++){
        printf("%d\n",a[i]);
    }
    free(a);//freeing the memory
}