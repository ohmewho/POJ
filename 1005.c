#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int cal(double x, double y){
	int year = 0;
	double e_area= 0, rsqr, dist;
	dist = x * x + y * y;
	do{
		year++;
		e_area += 50;
		rsqr = e_area * 2 / PI;
//		printf("year %d: %f %f\n", year, rsqr, dist);
	}while(rsqr < dist);
	
	return year;
}
int main(){
	int pnum, iter = 0, year;
	
	scanf("%d", &pnum);
	
	double pcoords[pnum][2];
	for(;iter < pnum; iter++){
		scanf("%lf %lf", &pcoords[iter][0], &pcoords[iter][1]);
		year = cal(pcoords[iter][0], pcoords[iter][1]);
		
		printf("Property %d: This property will begin eroding in year %d.\n", iter + 1, year);
	}
	printf("END OF OUTPUT.\n");
	
	
	return 0;
}
