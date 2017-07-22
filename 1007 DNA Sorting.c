#include <stdio.h>
#include <stdlib.h>


typedef struct astr{
	char str[51];
	int inverNum;	 
}DNAstr;

int getInvNum(char*, int);

int comp(const void *dstr1, const void * dstr2){

	return *(int*)dstr1 / 1000 - *(int*)dstr2 / 1000;
}


int main(){
	int n, m, iter, siter, iiter;
	scanf("%d %d", &n, &m);
	char dnastr[m][n+1];
	int invnum[m];
	
	
	for(iter = 0; iter < m; iter++){
		dnastr[iter][n] = '\0';
		scanf("%s", dnastr[iter]);
		invnum[iter] = getInvNum(dnastr[iter], n) * 1000 + iter;
//		printf("%d\n", invnum[iter]);
	}
	
	
	qsort(invnum, m, sizeof(invnum[0]), comp);
	
	for(iter = 0; iter < m; iter++){
		printf("%s\n", dnastr[invnum[iter] % 1000] );
	}
	
	return 0;
}

int getInvNum(char* str, int length){

	int invernum = 0, iter, iiter;
	for(iter = 0; iter < length - 1; iter++){
			for(iiter = iter + 1; iiter < length; iiter++){
				if(str[iter] > str[iiter]) {
					invernum++;	
				}
			}
		}
	return invernum;
}
