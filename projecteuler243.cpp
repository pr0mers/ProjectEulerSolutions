#include <bits/stdc++.h>

using namespace std;

vector<int>prime;

bool is_prime(int x){
	for(int i=0;prime[i]*prime[i]<=x;i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}

long long int totient(long long int n){
    long long int top=n;
    long long int t=2;
    while(t*t<=n){
        long long int c=0;
        while(n%t==0){
            c++;
            n=n/t;
        }
        top=(c)?top*(t-1)/t:top;
        t++;
    }
    if(n!=1){
        top=top*(n-1)/n;
    }
    return top;
}

int main(){
    prime.push_back(2);
    for(int i=3;i<30;i++){
        if(is_prime(i)){
            prime.push_back(i);
        }
    }
    long long int say=6;
    long long int tmp=say;
    long long int asal=2;
    long long int pay=15499;
    long long int payda=94744;
    double mn=99;  
    while(totient(say)*payda >= (say-1)*pay){
        for(int i=1;i<prime[asal] && totient(say)*payda >= (say-1)*pay;i++){
            say=say+tmp;
        }
        asal++;
        tmp=say;
    }
    cout<<say;
}