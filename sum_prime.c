#include <stdio.h>

int main(void) {
    int a,i,b,j;
	scanf("%d",&a);
    for(i=2;i<=a/2;i++)
    {
        if(a%i == 0)
        {
            printf("THe given i/p is not prime");
            return;
        }
    }
    b=a-2;
    for(i=2;i<=b/2;i++)
    {
        if(b%i == 0)
        {
            printf("THe given i/p cannot be represented as sum of prime nos");
            return;
        }
    }
    printf("2, %d are the prime nos",b);
	return 0;
}

