#include <stdio.h>
int a(int n){
    if(n>100){
        return n-10;
    }
    else return a(a(n+11));
}

int main(){
    printf("%d",a(95));
}