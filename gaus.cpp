#include <stdio.h>
#include <math.h>
#define N 3
#define EPSILON 1.0E-5

/*
	â€ëË1
	5S-J  No.07  éÅñºãvï€ìcóIÍ§
*/


void swap(double *wk1, double *wk2);
int sweep(double a[][N], double b[], double x[]);

int main (void){

	int sc;
	int i;
	double a[N][N] ={ {2,3,1},
		 {4,1,-3},
		 {-1,2,1} };
		  		 
	double b[N] = {2,3,4};
	double x[N];
	
	sc = sweep(a,b,x);

	if(sc){
		for(i = 0;i<N; i++) 
		{
			printf("x[%d] = %10.4f \n",i+1,x[i]);
		}
	}
	 else
	{
	 printf("not solved");
	}
	

return 0;
}


void swap(double *wk1, double *wk2){
    double w;
    w = *wk1;
    *wk1 =*wk2;
	*wk2 = w;
}

int sweep(double a[][N], double b[], double x[])
{
	int i=0,j=0,k=0,ik=0;
	double ak,aik;
	
	for(k=0;k<N;k++)
	{
		ak=a[k][k];
		if(fabs(ak) <= EPSILON)
		{
			ik=k+1;
			while( (ik<N) && (fabs(a[ik][k])<EPSILON))ik++;
			if(ik<N){
				for(j=k;j<N;j++){swap(&a[k][j],&a[ik][j]);}
				swap(&b[k],&b[ik]);
				ak=a[k][k];
			}
			else
			{
				printf("pibot is zero\n");
				return 1;
			}
		}

		for(j=k; j<N;j++) a[k][j]=a[k][j] / ak;
		b[k]=b[k]/ak;
		for(i=0;i<N;i++)
		{
			if(i != k)
			{
				aik=a[i][k];
				for(j=k; j<N;j++) a[i][j]= a[i][j] -aik*a[k][j];
				b[i]=b[i] - b[k] * aik;
			}
		}
	}
	for(k=0; k<N; k++) x[k]=b[k];
	return 1;
}
