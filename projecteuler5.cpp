#include <bits/stdc++.h>

using namespace std;
long long int ebob(int a,int b){
	if(b==0){
		return a;
	}
	return ebob(b,a%b);
}

int main(){
	long long int say=1;
	for(int i=1;i<=20;i++){
		say=say*i/ebob(say,i);
	}
	cout<<say;
}
