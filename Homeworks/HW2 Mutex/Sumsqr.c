
#include <stdio.h>
#include <pthread.h> 
#include "math.h"
#include <stdlib.h> 
#include <unistd.h> 


int start_points[4];
double ssum;
pthread_mutex_t sumlock;


double sumSqrt( int start, int end){
double psum=0;
for(;start<end; start++){
	psum=psum+sqrt(start);
}
//pthread_mutex_lock(&sumlock);
ssum+=psum;
//pthread_mutex_unlock(&sumlock);

}

int main(int argc, char *argv[]){
if (argc<2){
	printf("No number entered");
	return EXIT_FAILURE;
}

int n = atoi(argv[1]);
printf("\n%i\n",n);
pthread_t t1, t2;
/*
start_points[0]=1;
start_points[1]=n/3+1;
*/
start_points[2]=2*n/3+1;
start_points[3]=n+1;
printf("\n%i\n",start_points[2]);
printf("\n%i\n",start_points[3]);
/*pthread_create(&t1, NULL, sumSqrt(start_points[1], start_points[2]), NULL);*/
double res=sumSqrt(start_points[2], start_points[3]);
//pthread_create(&t2, NULL, sumSqrt(start_points[2], start_points[3]), NULL);
/*sumSqrt(start_points[0], start_points[1]);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
//printf("\nThe sum of the sqrts of %i is %d", n, ssum);
*/

printf("%d\n", ssum);
return 0;
}
