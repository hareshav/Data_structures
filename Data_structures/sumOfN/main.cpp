#include <stdio.h>
int sum(int n){
    if(n>0){
        return sum(n-1)+n;
    }
    else return 0;
}
int main()
{
	printf("%d",sum(5));
}
