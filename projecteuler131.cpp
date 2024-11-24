#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long int x){
	if(x==0 ||x==1){
		return false;
	}
	long long int say=sqrt(x);
	for(long long int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main(){
    long long int n=1;
    long long int i=0;
    long long int t=0;
    while((n=3*i*i+3*i+1)<=100000){
        t=t+is_prime(n);
        i++;
    }   
    cout<<t;
}