#include <stdio.h>
#include <math.h>
double sum=0;
int main(){

int i;
scanf("%i", &i);
	for(int j=0; j<i; j++){
		double result=sqrt((double)j);
		printf("Square root of %i is %f\n",j,result);
		sum+=result;

	}
}
