#include<stdio.h>
int sumf(int n){
    static int x;
    if(n>0){
        x++;
        return x+sumf(n-1);
    }
    else return 0;
}
int main(){
    printf("%d",sumf(4));
}
