#include <stdio.h>

int main(void) {
    int a,b,c;
    scanf("%d%d",&a,&b);
    int d,e;
    d=a;
    e=b;
    if(b<a)
    {
        c=a;
        a=b;
        b=c;
    }
    c=0;
    while(c!=0)
    {   
        c=b%a;
        b=a;
        a=c;
    }
    printf("LCM = %d, HCF = %d",(e*d)/c,c);
    
}

