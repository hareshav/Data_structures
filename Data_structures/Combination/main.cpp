#include <stdio.h>
int c(int n,int r){
    if(n==r||r==0)return 1;
    else {
        return c(n-1,r)+c(n-1,r-1);
    }
}
int fac(int n){
    if(n<=0) return 1;
    else {
        return n*fac(n-1);
    }
}
int cf(int n,int r){
    return fac(n)/(fac(r)*fac(n-r));
}
int main(){
    printf("%d",c(3,2));
}
