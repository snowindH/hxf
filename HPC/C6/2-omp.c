#include <stdio.h>
#include <omp.h>
#define M 1000

int main()
{
int a[M],b[M];
int i = 0,j = 0,s= 0;
for (i = 0;i < M ; i++)
    {
    a[i] = i;
    b[i] = i+1;
    }
#pragma omp parallel
#pragma omp parallel for reduction(+:s)
for (j = 0;j < M ;j++)
    {
    s = s + a[j] * b[j];
    }
//printf("s is :%d\n",s);
printf("task done!\n");
}
