#include <bits/stdc++.h>

using namespace std;
int asalmi(int x){
	if(x==1 || x==0 ||x<0){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(int i =2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int test(int a,int b){
	int n=0;
	while(asalmi(n*n+a*n+b)==1){
		n++;
	}
	return n;
}

int main(){
	int mx=0;
	int say=0;	
	for(int a=-999;a<=999;a++){
		for(int b=-1000;b<=1000;b++){
			if(test(a,b)>mx){
				mx=test(a,b);
				say=a*b;
			}
		}
	}
	cout<<say;
}
