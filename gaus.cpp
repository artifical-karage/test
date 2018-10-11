#include <stdio.h>
#include <math.h>
#define N 3
#define N1 3
#define EPSILON 1.0E-5


float a[N][N] ={ {1,2,-2},
		 {2,-2,5},
		 {-1,1,3} };
		  		 
float b[N] = {-3,6,8};
float x[N];

void swap(float *wk1, float *wk2);
int sweep();

int main (void){

	int sc;
	
	sc = sweep();

	if(sc){
	 for(int i = 0;i<N; i++) printf("x[%d] = %10.4f \n",i+1,x[i]);
	}
	 else
	{
	 printf("not solved");
	}
	

return 0;
}










void swap(float *wk1, float *wk2){
    float w;
    w = *wk1;
    *wk1 =*wk2;
	*wk2 = w;
}

int sweep()
{
	int i=0,j=0,k=0,ik=0;
	float ak,aik,p;
	
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
				return -1;
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
































