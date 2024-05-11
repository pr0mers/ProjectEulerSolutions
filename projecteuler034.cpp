#include <bits/stdc++.h>

using namespace std;

int f[10]={1,1,2,6,24,120,720,5040,40320,362880};

int dene(int n){
	int tp=0;
	while(n!=0){
		tp=tp+f[n%10];
		n=n/10;
	}
	return tp;
}

int main(){
	int top=0;
	for(int i=10;i<10000000;i++){ // 9!*n must be >= 10^(n-1) so n cant be greater than 7;
		if(dene(i)==i){
			top=top+i;
		}
	}
	cout<<top;
}
