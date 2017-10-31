#include <stdio.h>
main()
{
int i,j ,k;
FILE *fp;	
i =2;
k = 2;
j = 0;
fp = fopen("data.txt","w");
for ( i = 2;i<=100000;i++)
	{
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) break;
			}
		if (k == i)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
}
