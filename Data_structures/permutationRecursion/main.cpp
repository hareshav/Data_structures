#include <stdio.h>
void perm(int s[],int k){
    static int res[100];
    static int flag[100]={0};
    int i;
    int size=6;
    if(k==size){
        for(int j=0;j<size;j++){
             printf("%d ",res[j]);
        }
        printf("\n");
       
    }
    else{
        for(i=0;i<size;i++){
            if(flag[i]==0){
                flag[i]=1;
                res[k]=s[i];
                perm(s,k+1);
                flag[i]=0;
            }
        }
    }
}
int main()
{
    int s[]={1,2,3,-3,-2,-1};
	perm(s,0);
}
