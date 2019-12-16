#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
 
using namespace std;
 
#define N 10005   
int main(){
	int i,j,len;
	int n;
	while(scanf("%d",&n) != EOF){  
		if(n == 0 || n == 1){
			printf("%5d -> 1\n", n);
			continue;
		}
		long s[N] = {1, 1};
		len = 1;
		for(i= 2; i <= n; i ++) {
			for(j = 0; j < len; j ++)
				s[j] = s[j] * i;
			for(j = 0;j < len - 1; j ++) {
				s[j+ 1] += s[j] / 10000;
				s[j] = s[j] % 10000;
			}
			if(s[j] > 10000 ) {
				s[j + 1] = s[j]/ 10000;
				s[j] = s[j] % 10000;
				len ++;       
			}
		}
		int tt;
		int flag = 0;
		for (int j = 0; j < len; j ++) {
			flag = 0;
			while (s[j] > 0) {
				tt = s[j] % 10;
				s[j] /= 10;
				if(tt > 0) {
					flag = 1;
					break;	
				}
			}
			if(flag == 1) {
				printf("%5d -> %d\n",n, tt);
				break;
			}
		}
	}   
	return 0;
}

