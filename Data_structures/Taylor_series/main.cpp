#include<stdio.h>
float taylor(float x,float n){
    static float p=1,f=1;
    if(n==0) return 1;
    else {
        float t=taylor(x,n-1);
        p=p*x;
        f=f*n;
        return t+p/f;
    }
}
int main(){
printf("%f",taylor(2,10));}