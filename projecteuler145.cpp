#include <bits/stdc++.h>

using namespace std;


long long int dene(long long int a){
	if(a%10==0){
		return 0;
	}
	long long int x=a;
	long long int ters=x%10;
	while(x/10 != 0){
		x=x/10;
		long long int kalan=x%10;
		ters=ters*10+kalan;
		
	}
	long long int hepsi=a+ters;
	while(hepsi/10 != 0){
		if(hepsi%2 ==0){
			return 0;
		}
		hepsi=hepsi/10;
	}
	if(hepsi%2==0){
		return 0;
	}
	return 1;
}


int main(){
	long long int t=0;
	for(long long int i=1;i<1000000000;i++)//çift basamak olamaz aslýnda
	{	
		if(dene(i)==true){
			t++;
		}
	}
	cout<<t;
}
