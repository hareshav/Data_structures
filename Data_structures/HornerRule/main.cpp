#include<stdio.h>
double e(int x,int n){
    
    static double s;
    if(n==0) return s;
    else {
        s=1+x*s/n;
        return e(x,n-1);
    }
}
double i(int x,int n){
    double p=1,f=1,s=0;
    for(int i=1;i<=n;i++){
        s=s+p/f;
        p=p*x;
        f=f*i;
        
    }
    return s;
}
int main(){
    printf("%lf",i(2,10));
}