#include <stdio.h>
int fac(int n){
    if(n==0) return 0;
    if(n==1)  return 1;
    else return n*fac(n-1);
}
int faci(int n){
    int k=1;
    for(int i=1;i<=n;i++){
        k*=i;
    }
    return k;
}
int main(){
    printf("%d",faci(5));
}
