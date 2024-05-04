#include <bits/stdc++.h>

using namespace std;

long long int mod=10000000000;

__int128 uzeri(int a, int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	__int128 say=uzeri(a,b/2);
	if(b%2==1){
		return say*say*a %mod;
	}
	else{
		return say*say %mod;
	}
}



int main(){
	long long int toplam=0;
	for(int i =1;i<=1000;i++){
		toplam=(toplam+uzeri(i,i))%mod;
	}
	cout<<toplam;
}
