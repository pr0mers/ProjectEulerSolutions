#include <bits/stdc++.h>

using namespace std;

int asalmi(int x){
	if(x==1 || x==0){
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
long long int uzeri(long long int a, long long int b,int mod){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	long long int say=uzeri(a,b/2,mod);
	if(b%2==1){
		return say*say*a %mod;
	}
	else{
		return say*say %mod;
	}
}

int kalan(int n){ // fermat's little theorem used on 1111....11 = (10^(10^9)-1) / 9
	int say=1000000000;
	int a= say%(n-1);
	return uzeri(10,a,n);
}


int main(){
	int oldu=0;
	int toplam=0;
	for(int i=6;oldu!=40;i++) // 2,3 and 5 isn't divisor of the number
	{	
		if(asalmi(i)==1){
			if(kalan(i)==1){
				oldu++;
				toplam=toplam+i;
			}
		}

	}
	cout<<toplam;
}
