#include <stdio.h>
#define M 100000
main()
{
int i = 2;
int j = 0;
int k = 2;
int n = 0;
FILE *fp;	
int prime[M];


for ( i = 0;i < 3;i++)
{
    prime[i] = 0;
}
fp = fopen("data3-acc.txt","w");
//#pragma acc kernels
for ( i = 3;i<=M;i++)
	{
        n = 0;
        prime[i] = 0;
        #pragma acc kernels
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                n += 1;
			}
		if (n == 0)
			{
			prime[i] = i,
			j++;
			}
	}
for (i = 0; i < j ; i++)
{
    fprintf(fp,"%d\n",prime[i]);
}
fclose(fp);
printf("the number of prime number is : %d\n",j);
}
