#include <bits/stdc++.h>

using namespace std;

long long int comb(int n, int r){
	if(r==0){
		return 1;
	}
	float sayi=1;
	for(int i=1;i<=r;i++){
		sayi=sayi*(n+1-i)/i;
	}
	return sayi;
}


int main(){
	int t=0;
	long long int say=0;
	for(int a=23;a<=100;a++){
		for(int i=0;i<=a;i++){
			say=comb(a,i);
			if(say>1000000){
				t=t+(a+1)-2*i; 
				break;
			}
		}
	}
	cout<<t;
}
