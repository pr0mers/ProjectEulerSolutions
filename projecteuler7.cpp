#include <bits/stdc++.h>

using namespace std;
bool asalmi(int x){
	int say=sqrt(x);
	for(int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int asal=0;
	for(int i=2;;i++){
		if(asalmi(i)==true){
			asal++;
		}
		if(asal==10001){
			cout<<i;
			break;
		}
	}
}
