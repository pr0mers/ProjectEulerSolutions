/// it takes aprox. 100secs will try to reduce it to 1 min


#include <bits/stdc++.h>

using namespace std;
long long int dizi[40000005];
vector<long long int>asallar;
long long int totient(long long int n){
	if(n==1 || n==0){
		return 0;
	}
	long long int say=n;
	for(long long int i=0;asallar[i]*asallar[i]<=n;i++){
		long long int a=0;
		while(n%asallar[i] ==0){
			a=1;
			n=n/asallar[i];
		}
		if(a==1){
			say=say*(asallar[i]-1)/(asallar[i]);
		}
	}
	if(n!=1){
		say=say*(n-1)/n;
	}
	return say;
}

long long int asalmi(long long int x){
	if(x==1 || x==0){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(long long int i =2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

long long int chain(long long int n){
	if(n==1){
		return 1;
	}
	
	if(dizi[n]!=0){
		return dizi[n];
	}	
	long long int deger=1+chain(totient(n));
	dizi[n]=deger;
	return dizi[n];
}
int main(){
	long long int toplam=0;
	for(long long int i =2;i<40000000;i++){
		if(asalmi(i)==1){
			asallar.push_back(i);
			if(chain(i)==25){
				toplam=toplam+i;
			}
		}
	}
	cout<<toplam;	
}
