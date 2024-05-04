#include <bits/stdc++.h>

using namespace std;

long long int bul(long long int x,long long int say){
	//cout<<x<<" "<<say<<endl;
	if(x==1){
		return say;
	}
	if(x%2==0){
		bul(x/2,say+1);
	}
	else{
		bul(3*x+1,say+1);
	}
}

int main(){
	long long int mx=0;
	long long int x=0;
	for(long long int i=1;i<=1000000;i++){
		long long int sa=bul(i,1);
		if(sa>=mx){
			mx=sa;
			x=i;
		}
	}	
	cout<<x;
}
