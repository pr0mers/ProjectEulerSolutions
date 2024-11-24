#include <bits/stdc++.h>

using namespace std;
vector<int>prime;

bool is_prime(int x){
	int say=sqrt(x);
	for(int i=0;prime[i]<=say;i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}

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
        say=say*10;
        say++;
        say=say%n;
        t++;
    }
    return t;
}
int main(){
    prime.push_back(2);
    prime.push_back(3);
    int top=0;
    int numo=25;
    for(long long int i=4;;i++){
        if(is_prime(i)){
            prime.push_back(i);
            continue;
        }
        if(i%2==0 || i%5==0){
            continue;
        }
        if((i-1)%A(i)==0){
            //cout<<i<<endl;
            top=top+i;
            numo--;
            if(numo==0){
                cout<<top;
                return 0;
            }
            //return 0;
        }
    }
}