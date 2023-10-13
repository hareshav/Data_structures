#include <stdio.h>
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1
    )+fib(n-2);
}
int fibi(int n){
    int a=0,b=1,in;
    if(n<=1)return n;
    for(int i=0;i<n-1;i++){
        in=a+b;
        a=b;
        b=in;
    }
    return in;
}
int fiba(int n){//memorisazion
    static int f[10];
    if(n<=1){ 
        f[n]=n;
        return f[n];
    }
    if(!f[n-1]) 
        f[n-1]=fiba(n-1);
    if(!f[n-2]) 
        f[n-2]=fiba(n-2);
    return f[n-1]+f[n-2];
}
int main(){
    printf("%d",fiba(6));
}
