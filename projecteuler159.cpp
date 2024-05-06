#include <bits/stdc++.h>

using namespace std;

int dizi[1000005];

int drs(int n){
	// ABCD (4 digit number) is same as A+B+C+D modulo 9 which is (lets say) EF it is same as E+F so E+F = A+B+C+D too so drs is basically mod 9
	if(n%9 == 0){
		return 9;
	}
	else{
		return (n%9);
	}
	
}

int mdrs(int n){
	if(n==0 || n==1){
		return 0;
	}
	int mx=0;
	
	if(dizi[n]!=0){
		
		return dizi[n];
	}
	
	for(int i =2;i*i<=n;i++){
		if(n%i == 0){
			mx=max(mx,drs(i)+mdrs(n/i));
		}
	}
	mx=max(mx,drs(n));
	dizi[n]=mx;
	return dizi[n];
}


int main(){
	int toplam=0;
	for(int i =2;i<1000000;i++){
		toplam=toplam+mdrs(i);
		
	}
	cout<<toplam;
}
