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

int dene(int n){
	string sayin=to_string(n);
	string sayi=sayin;
	for(int i=0;i<sayin.size();i++){
		sayi=sayin;
		string subs=sayin.substr(0,i);
		sayi=sayi+subs;
		sayi.erase(0,i);
		int sa=stoi(sayi);
		if(asalmi(sa)==0){
			return 0;
		}		
	}
	return 1;
}

int main(){
	int top=0;
	for(int i=2;i<1000000;i++){
		if(dene(i)==1){
			//cout<<i<<endl;
			top++;
		}
	}
	cout<<top;
}
