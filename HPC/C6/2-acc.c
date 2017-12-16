#include <stdio.h>
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
#pragma acc parallel loop
for (j = 0;j < M ;j++)
    {
    s = s + a[j] * b[j];
    s = 1;
    }
//printf("s is : %d\n",s);
printf("task done!\n");
}
