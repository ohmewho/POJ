#include <stdio.h>
#define N 12

int main(){
	double endblnc, sum = 0, avg;
	
	int n = 0;   

	while(n < N){
		scanf("%lf", &endblnc);
		sum += endblnc;
		n++;
	}
	
	avg = sum / N;
	printf("$%.2f\n", avg);
		
	return 0;
}

