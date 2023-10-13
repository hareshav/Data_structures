#include<stdio.h>
struct sec{
    int arr[5];
    int t;
};
void fun(struct sec r){//forced to call by value
    r.arr[3]=16;
    for(int i=0;i<5;i++){
        printf("%d ",r.arr[i]);
    }
    printf("\n");
}


int main(){
    struct sec c={{1,2,3,4,5},6};
    fun(c);
    for(int i=0;i<5;i++){
        printf("%d ",c.arr[i]);
    }
    
}