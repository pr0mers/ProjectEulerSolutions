#include <bits/stdc++.h>

using namespace std;

long long int mod=10000000000;

long long int uzeri(int a, int b){
	long long int say=1;
	for(int i = 1;i<=b;i++){
		say=say*a % mod;
	}
	return say;
}



int main(){
	long long int toplam=0;
	for(int i =1;i<=1000;i++){
		toplam=(toplam+uzeri(i,i))%mod;
	}
	cout<<toplam;
}
