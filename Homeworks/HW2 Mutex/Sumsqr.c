
#include <stdio.h>
#include <pthread.h> 
#include "math.h"
#include <stdlib.h> 
#include <unistd.h> 


int sp1[2];
int sp2[2];
int sp3[2];
double ssum=0;
pthread_mutex_t sumlock;


void * sumSqrt(void* i){
	double psum=0;
	int *start=i;
	printf("%i ",start[1]);
	for(int i=start[0];i<start[1]; i++){
			double sq=pow(i, 0.5);
			psum+=sq;
		
	}
	pthread_mutex_lock(&sumlock);
	ssum=ssum+psum;
	pthread_mutex_unlock(&sumlock);

}

int main(int argc, char *argv[]){
	if (argc<2){
	printf("No number entered");
	return EXIT_FAILURE;
	}

	int n = atoi(argv[1]);
	printf("\n%i\n",n);
	pthread_t t1, t2;

	sp1[0]=1;
	sp1[1]=n/3+1;
	
	sp2[0]=n/3+1;
	sp2[1]=2*n/3+1;
	
	sp3[0]=2*n/3+1;
	sp3[1]=n+1;




	pthread_create(&t1, NULL, sumSqrt, sp2);
	pthread_create(&t2, NULL, sumSqrt, sp3);
	sumSqrt(sp1);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("\nThe sum of the sqrts of %i is %d", n, ssum);


	
	return 0;
}
