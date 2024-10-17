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
    long long int prime=0;
    long long int artis=2;
    long long int son=1;
    do{
        for(int i=0;i<4;i++){
            son=son+artis;
            prime+=(is_prime(son)) ? 1 : 0;
        }
        artis=artis+2;
    }while(prime*10>=sqrt(son)*2-1);
    cout<<sqrt(son);
}
