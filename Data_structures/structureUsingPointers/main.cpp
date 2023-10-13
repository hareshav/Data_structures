#include <stdio.h>
struct rec{
    int l;
    int b;
};
int main()
{
    struct rec r={10,5};
    struct rec *p;
    p=&r;
    p->b=2;
    printf("%d %d\n",r.l,r.b);
    printf("%d %d",p->l,p->b);
	return 0;
}
