#include <stdio.h>
#include <mpi.h>
#define M 100000
int main(int argc,char* argv[])
{
int i = 2;
//int j = 0;
int k = 2;
int n = 0;
FILE *fp;	
int prime[M];

int proc_num;
int proc_id;
const int j = 0;
//for ( i = 0;i < 3;i++)
//{
//    prime[i] = 0;
//}
//#pragma acc kernels
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&proc_id);
MPI_Comm_size(MPI_COMM_WORLD,&proc_num);
prime[0]=prime[1]=0;
for ( i = 2;i<=M;i++)
	{
    if (i%proc_num!=proc_id)
        //n = 0;
        {
        prime[i] = 0;
        continue;
        }
        //#pragma acc kernels
    int n = 0;    
	int j = 0;
    for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                n += 1;
			}
		if (n == 0)
			{
			prime[i] = i;
			//j++;
			}
	}
if (proc_id!=0)
    {
    MPI_Send(prime,M,MPI_INT,0,99,MPI_COMM_WORLD);
    }
int numbers = 0;
if(proc_id == 0)
{

    fp = fopen("data3-mpi.txt","w");
    int rec_prime[M];
    //int rec_j=0;    
    for (int p = 0; p < proc_num ; p++)
    {
        if (p!=0)
        {
            MPI_Recv(rec_prime,M,MPI_INT,p,99,MPI_COMM_WORLD,&status);
            for(int i = 0;i<M;i++)
            {
                if(rec_prime[i] != 0)
                {
                    numbers++;
                    fprintf(fp,"%d\n",rec_prime[i]);
                 }  
            }
        }
        else
        {
            for(int i = 0;i<M;i++)
                if(prime[i]!=0)
                     numbers++,
                     fprintf(fp,"%d\n",prime[i]);
        }  
}
fclose(fp);
printf("the number of prime number is : %d\n",numbers);
}
MPI_Finalize();
return 0;
}
