#include <stdio.h>

int main()
{
	char a[]="weLcoME";
    for(int i=0;a[i];i++){
        if(a[i]>='A'&&a[i]<='Z')
            a[i]=a[i]+32;
        else if(a[i]>='a'&&a[i]<='z')
            a[i]=a[i]-32;
    }
    printf("%s",a);
}
