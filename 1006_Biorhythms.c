#include <stdio.h>
#define N 21252

int main(){
	int p, e, i, day, triple, iter, count = 0;
	
	do{	
		scanf("%d %d %d %d", &p, &e, &i, &day);
		if(p == -1 && e == -1 && i == -1 && day == -1) break;
//		printf("%d %d %d %d\n", p, e, i, day);
		
		count++;
		for(iter = 1; iter <= N; iter++){
			if(  !((iter + p) % 23) && !((iter + e) % 28) && !((i + iter) % 33)) triple = (N - iter - day) % N;
			
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", count, triple <= 0? N + triple : triple);
	
	}while(1); 

	
	return 0;
}
