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

int dene(int i){
	vector<int>v;
	while(i!=0){
		v.push_back(i%10);
		if(asalmi(i)==0){
			return 0;
		}
		i=i/10;
	}
	int say=0;
	for(int i=0;i<v.size();i++){
		say=say+v[i]*pow(10,i);
		if(asalmi(say)==0){
			return 0;
		}
	}	
	return 1;
}

int main(){
	int n=0;
	int i=10;
	int toplam=0;
	while(n!=11){
		if(dene(i)==1){
			toplam=toplam+i;
			n++;
		}
		i++;
	}
	cout<<toplam;
}
