#include <stdio.h>
#include <string.h>

void parse(char * str, int strlen, char * res, int reslen){
	int iter, res_iter = 0;
	for(iter = 0; iter < strlen && str[iter]; iter++){
		if(str[iter] != '-' && !(str[iter] >= '0' && str[iter] <= '9')){
			switch(str[iter]){
				case 'A':
				case 'B':
				case 'C': res[res_iter++] = '2';
				break;
				case 'D':
				case 'E':
				case 'F': res[res_iter++] = '3';
				break;
				case 'G':
				case 'H':
				case 'I': res[res_iter++] = '4';
				break;
				case 'J':
				case 'K':
				case 'L': res[res_iter++] = '5';
				break;
				case 'M':
				case 'N':
				case 'O': res[res_iter++] = '6';
				break;
				case 'P':
				case 'R':
				case 'S': res[res_iter++] = '7';
				break;
				case 'T':
				case 'U':
				case 'V': res[res_iter++] = '8';
				break;
				case 'W':
				case 'X':
				case 'Y': res[res_iter++] = '9';
				break;
			}
		}
		else if(str[iter] >= '0' && str[iter] <= '9') res[res_iter++] = str[iter];
//		printf("\nres_iter is %d\n", res_iter);
		
	}
	res[res_iter] = '\0';
}
int telenums[10000000] = {0};

int main(){
	int num, min = 10000000, max = 0, dup = 0;
	
	int tnum, iter = 0;
	char tele[300], res[8];   
	scanf("%d", &num);	
	while(num > 0){
		scanf("%s", tele);
		parse(tele, strlen(tele), res, 8);
		num--;
//		puts(tele);
//		puts(res);
		sscanf(res, "%d", &tnum);
//		printf("%d\n", tnum);
		if(min > tnum) min = tnum;
		if(max < tnum) max = tnum;
		telenums[tnum]++;
	}
//	printf("min is %d, max is %d\n", min, max);
	for(iter = min; iter <= max; iter++){
		if(telenums[iter] > 1) {
			if(!dup) dup = 1;
			printf("%03d-%04d %d\n", iter/10000, iter%10000, telenums[iter]);
		}
	}
	
	if(!dup) printf("No duplicates.\n");
		
	return 0;
}
