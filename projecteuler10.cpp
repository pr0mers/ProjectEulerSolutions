#include <bits/stdc++.h>

using namespace std;
bool asalmi(int x){
	if(x==2){
		return true;
	}
	int say=sqrt(x);
	for(int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	long long int cvp=0;
	for(int i=2;i<2000000;i++){
		if(asalmi(i)==true){
			cvp=cvp+i;
		}
	}
	cout<<cvp;
}
