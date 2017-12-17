#include <stdio.h>
#include <omp.h>
#include <iostream>
#define n 100000


double f(double a)
{
    return (4.0/(1.0 + a*a));
}
int main(int argc,char *argv[])
{
    double h=0;
    double sum,pi;
    double x = 0.0;
    int i;
    h = 1.0/(double)n;
    sum = 0.0;
    for (i = 1;i <= n;i++)
    {
        x = h *((double)i - 0.5);
        sum += f(x);
    }
    pi = h*sum;
    printf("pi is %f:",pi);
}




