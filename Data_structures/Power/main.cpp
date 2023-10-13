#include <stdio.h>
int pow(int a,int b){
    if(b==1) return a;
    else return pow(a,b-1)*a;
}
int spow(int m,int n){
    if(n==0) return 1;
    else if(n%2==0) return spow(m*m,n/2);
    else return m*spow(m*m,(n-1)/2);
}
int main()
{
	printf("%d",spow(5,6));
}

