
#include <stdio.h>
#include <pthread.h> 
#include <math.h>
#include <stdlib.h> 
#include <unistd.h> 


int sp1[2];
int sp2[2];
int sp3[2];
double ssum=0;
pthread_mutex_t sumlock;

//function for each thread to call and sum their respective n values
void * sumSqrt(void* i){
	double psum=0;
	int *start=i;
	
	//Calculate the square root then sum it  
	for(int j=start[0];j<start[1]; j++){
			double result=sqrt((double)j);
			//printf("Square Root of %i is %f\n", j, result);
			psum+=result;
		
	}

	//Entering Critical Region lock shared variable ssum (sum of all sqr roots)
	pthread_mutex_lock(&sumlock);
	ssum=ssum+psum;
	//Exiting Critical Region unlock shared variabl ssum (sum of all sqr roots)
	pthread_mutex_unlock(&sumlock);

}

int main(int argc, char *argv[]){
	
	//error check remind user to enter a number in command line
	if (argc!=2){
	printf("No number entered");
	return EXIT_FAILURE;
	}
	//convert char string in arg at index 1 from chars to integer
	int n = atoi(argv[1]);
	
	//Allocation of address space for threads t1 and t2
	pthread_t t1, t2;

	//1st 1/3 start and end point
	sp1[0]=1;
	sp1[1]=n/3+1;
	
	//2nd 1/3 start and end point
	sp2[0]=n/3+1;
	sp2[1]=2*n/3+1;
	
	//3rd 1/3 start and end point
	sp3[0]=2*n/3+1;
	sp3[1]=n+1;



	//create thread 2 the 2nd 1/3 of n square roots to be summed
	pthread_create(&t1, NULL, sumSqrt, sp2);
	//create thread 3 the 3rd 1/3 of n square roots to be summed
	pthread_create(&t2, NULL, sumSqrt, sp3);
	//run the 1st 1/3 of n square roots to be summed in the main thread
	sumSqrt(sp1);
	
	//Wait till threads 1 and 2 are terminated to print the result
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("\nThe sum of the sqrts from 1 to %i is %f\n", n, ssum);


	
	return 0;
}
