#include <bits/stdc++.h>

using namespace std;

vector<int>asallar;

bool dene(int n){

	int a=0;
	for(int i=0;i<asallar.size();i++){
		int a =sqrt((n-asallar[i])/2);
		if(a*a == (n-asallar[i])/2){
				a=1;
				return true;
		}
	}
	if(a==0){
		return false;
	}
}

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

int main(){
	asallar.push_back(2);
	for(int i=3;i<=100000;i=i+2)
	{	
		if(asalmi(i)==1){
			asallar.push_back(i);
		}
		if(dene(i)==false && asalmi(i)==0){
			cout<<i;
			break;
		}
	}
}
