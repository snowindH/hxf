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

printf("start!");
for ( i = 0;i<3;i++)
{
    prime[i] = 0;
}

fp = fopen("data.txt","w");
//#pragma acc parallel
for ( i = 3;i<=M;i++)
	{
        n = 0;
        prime[i] = 0;
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                n += 1;
			}
		if (n == 0)
			{
			prime[i] = i;
            j++;
			}
	}
printf(" prime[1] is : %d\n",prime[0]);


for (i = 0 ;i < j;i++)
{
    fprintf(fp,"%d\n",prime[i]);
//    printf("j is : %d\n",j);
}
fclose(fp);
printf("the number of prime number is : %d\n",j);
}
