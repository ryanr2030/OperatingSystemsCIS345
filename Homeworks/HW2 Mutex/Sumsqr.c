Assignment 2
#include <studio.h>
#include <math.h>
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
 
Int start_points[4];
double ssum;
Pthread_mutex_t sumlock;
void *sumSqrt( int start, int end){
double psum=0;
for(int i = start;i<end; i ++){
          psum+=sqrt(i);
}
Pthread_mutex_t_lock(&sumlock);
ssum+=psum;
Pthread_mutex_t_unlock(&sumlock);

}

void main(int argc, char *argv[]){

int n = atoi(argv[2]);
pthread_t t1, t2;

start_points[0]=1;
start_points[1]=n/3+1;
start_points[2]=2n/3+1;
start_points[3]=n+1;
pthread_create(&t1, NULL, sumSqrt(start_points[1], start_points[2]), NULL);
pthread_create(&t2, NULL, sumSqrt(start_points[2], start_points[3]), NULL);
sumSqrt(start_points[0], start_points[1]);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf(“ \nThe sum of the sqrts of %i is %d” n, psum);
}
