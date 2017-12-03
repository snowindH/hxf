#include <stdio.h>
#include <omp.h>
main()
{
int i,j ,k,n;
FILE *fp;	
i =2;
k = 2;
j = 0;
n = 0;
double t_start,t_end,t_sp0,t_sp1,t_sp2,t_sp3,t_sp4,t_sp5,t_sp6,t_sp7,t_sp8;
double speedup1,speedup2,speedup3,speedup4,speedup5,speedup6,speedup7,speedup8;




fp = fopen("data0.txt","w");
t_start = omp_get_wtime();
for ( i = 2;i<=100000;i++)
	{
		for ( k = 1;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
                        j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp0 = t_end - t_start;



j = 0;
n = 0;
t_start = omp_get_wtime();
fp = fopen("data1.txt","w");
#pragma omp parallel num_threads(1)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 1;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp1 = t_end - t_start;
speedup1 = t_sp0/t_sp1;



n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data2.txt","w");
#pragma omp parallel num_threads(2)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 1;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp2 = t_end - t_start;
speedup2 = t_sp0/t_sp2;

n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data3.txt","w");
#pragma omp parallel num_threads(3)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 1;k<i;k++)
			{
			if(i%k == 0)
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp3 = t_end - t_start;
speedup3 = t_sp0/t_sp3;

n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data4.txt","w");
#pragma omp parallel num_threads(4)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 1;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp4 = t_end - t_start;
speedup4 = t_sp0/t_sp4;


n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data5.txt","w");
#pragma omp parallel num_threads(5)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp5 = t_end - t_start;
speedup5 = t_sp0/t_sp5;


n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data6.txt","w");
#pragma omp parallel num_threads(6)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp6 = t_end - t_start;
speedup6 = t_sp0/t_sp6;



n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data7.txt","w");
#pragma omp parallel num_threads(7)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp7 = t_end - t_start;
speedup7 = t_sp0/t_sp7;




n = 0;
j = 0;
t_start = omp_get_wtime();
fp = fopen("data8.txt","w");
#pragma omp parallel num_threads(8)
#pragma omp parallel private(n)
for ( i = 2;i<=100000;i++)
	{
                #pragma omp parallel for reduction(+:n)
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                        n += 1;
			}
		if (n <= 2)
			{
			fprintf(fp,"%d ",i);
			j++;
			}
	}
fclose(fp);
printf("the number of prime number is : %d\n",j);
t_end = omp_get_wtime();
t_sp8 = t_end - t_start;
speedup8 = t_sp0/t_sp8;



printf("sigle threads time is :%f\n",t_sp0);
printf("one threads time is :%f,speedup is :%f\n ",t_sp1,speedup1);
printf("two threads time is :%f,speedup is :%f\n ",t_sp2,speedup2);
printf("three threads time is :%f,speedup is :%f\n ",t_sp3,speedup3);
printf("four threads time is :%f,speedup is :%f\n ",t_sp4,speedup4);
printf("five threads time is :%f,speedup is :%f\n ",t_sp5,speedup5);
printf("six threads time is :%f,speedup is :%f\n ",t_sp6,speedup6);
printf("seven threads time is :%f,speedup is :%f\n ",t_sp7,speedup7);
printf("eight threads time is :%f,speedup is :%f\n ",t_sp8,speedup8);











}
