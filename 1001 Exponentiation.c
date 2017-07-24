#include <stdio.h>
#include <string.h>
#define N 7


typedef struct arn{
	int decplaces;
	int len;
	int nums[150];
} realNum;

void printarn(realNum rn);

realNum strtorn(char* rnstr){
	realNum rn;
	int decpos, iter, rpos = N - 2, lpos = 0, resiter = 0, nonzero = 0;
	
	if(!strchr(rnstr, '.')) {
		rn.decplaces = 0;
		while(rnstr[lpos] == '0'){
			lpos++;
		}
		rn.len = N - 1 - lpos;
		for(iter = lpos; iter < N - 2; iter++){
			rn.nums[iter - lpos] = rnstr[iter] - '0';
		}		
	}
	else {
		decpos = strchr(rnstr, '.') - rnstr;
		
		while(rnstr[rpos] == '0'){
			rpos--;
		}
//		printf("rpos is %d\n", rpos);
		rn.decplaces = rpos - decpos;
//		printf("decplace number is %d\n", rn.decplaces);
		for(iter = 0; iter < rpos + 1; iter++){
			if(rnstr[iter] != '0'){
				if(!nonzero) nonzero = 1;
			}
	//		printf("iter = %d_", iter);
			if(!nonzero && iter < rpos) continue;
			if(iter == decpos) {
	//			printf("\n");
				continue;
			}
			rn.nums[resiter] = rnstr[iter] - '0';
			resiter++;
	//		printf("resiter = %d ** rn.nums[%d] = %d\n", resiter, resiter - 1, rn.nums[resiter - 1]);
		}
		rn.len = resiter;
//	printarn(rn);
	}
//	printf("decpos is %d\n", decpos);
	//if(decpos > = 0)

	
	return rn;
}

void printarn(realNum rn){
	int pos;
//	if(rn.decplaces >= rn.len){
//		printf("0");
//	}
	if(rn.decplaces > rn.len){
		printf(".");
		for(pos = 0; pos < rn.decplaces - rn.len; pos++){
			printf("0");
		}
	}
	for(pos = 0; pos < rn.len; pos++){
		if(pos == rn.len - rn.decplaces) printf(".");
		printf("%c", rn.nums[pos] + '0');
	}
	printf("\n");
	
}

realNum mul(realNum rna, realNum rnb){
	realNum resrn;
	realNum * p = &resrn;
	memset(p, 0, sizeof(realNum));
//	printf("I am in %s, %d %d\n", __func__, resrn.nums[9], resrn.nums[10]);
	resrn.decplaces = rna.decplaces + rnb.decplaces;
	int itera, iterb, resiter, /*radius = 1,*/ carry = 0, temp, pos;
	for(itera = rna.len - 1; itera >= 0; itera--){
		for(iterb = rnb.len - 1; iterb >= 0; iterb--){
			pos = rna.len - 1 + rnb.len - 1 - itera - iterb;
			temp = resrn.nums[pos] + rna.nums[itera] * rnb.nums[iterb] + carry;
//			printf("resrn.nums[%d] = %d, rna = %d, rnb = %d, temp = %d, carry = %d\n", pos, resrn.nums[pos], rna.nums[itera], rnb.nums[iterb], temp, carry);						
			resrn.nums[pos] = temp % 10;
			//resrn.nums[resiter] = rna.nums
			carry = temp / 10;
//			printf("resrn.nums[%d] = %d, carry = %d\n", pos, resrn.nums[pos], carry);			
		}
		while(carry != 0){
			pos++;
			temp = resrn.nums[pos] + carry;			
			resrn.nums[pos] = temp % 10;
//			printf("resrn.nums[%d] = %d\n", pos, resrn.nums[pos]);
			carry = temp / 10;
		} 
	}
	resrn.len = pos + 1;
//	printf("len = %d\n", resrn.len);

	for(resiter = 0; resiter < resrn.len / 2; resiter++){
		temp = resrn.nums[resiter];
		resrn.nums[resiter] = resrn.nums[resrn.len - 1 - resiter];
		resrn.nums[resrn.len - 1 - resiter] = temp;
	}

	
	
	return resrn;
}

int main(){
	
	char r[N];
	realNum rn, product;
	double db;
	int res[N - 2] = {0}, n, iter; 
	
	while(scanf("%s%d", r, &n) == 2){
//		printf("%c %d\n", r[rpos], sizeof(char));
		sscanf(r, "%lf", &db);
		if(!db) printf("0\n");
		else{
			rn = strtorn(r);
			product = rn;
			for(iter = 0; iter < n - 1; iter++){
				product = mul(product, rn);				
			}
			printarn(product);
		}	
	}
	
	
	return 0;
}
