#include <bits/stdc++.h>

using namespace std;

int main(){
	int mx=0;
	for(int i=1;i<=999;i++){
		for(int j=i;j<=999 && i+j<=1000;j++){
			if(i*i+j*j==(1000-i-j)*(1000-i-j)){
				cout<<i*j*(1000-i-j);
				return 0;
			}
		}
	}
}
