#include <stdio.h>

int cal(double real){
	int n = 2;
	double sum;
	sum = 1 * 1.0 / n;
	while(sum < real){
		n++;
		sum += 1 * 1.0 / n;
	}
	return n - 1;
}


int main(){
	double real;
	scanf("%lf", &real);
	
	while(real != 0){
		printf("%d card(s)\n", cal(real));
		scanf("%lf", &real);	
	}
	
	
	return 0;
}
