#include <bits/stdc++.h>

using namespace std;

long long int power(long long int a, long long int b,long long int mod){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	long long int say=power(a,b/2,mod);
	if(b%2==1){
		return ((say*say)%mod*a)%mod;
	}
	else{
		return (say*say)%mod;
	}
}

long long int A(long long int n){
    long long int say=11;
    int t=2;
    while(say%n!=0){
        say=(say*10);
        say++;
        say=say%n;
        t++;
    }
    return t;
}
int main(){
    // order of N is smaller than N because ord(N) divides phi(N)
    for(long long int i=1000000;;i++){
        if(i%2==0 || i%5==0){
            continue;
        }
        long long int num=A(i);
        if(num>1000000){
            cout<<i<<endl;
            return 0;
        }
    }
}