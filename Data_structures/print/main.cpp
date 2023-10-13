#include <stdio.h>
void prin(int n){
    if(n>0){
        prin(n-1);
        printf("%d ",n);
        
    }
}

int main()
{
	prin(3);
}
