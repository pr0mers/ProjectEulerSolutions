#include <bits/stdc++.h>

using namespace std;
vector<int>prime;

bool is_prime(int x){
	if(x==0 ||x==1){
		return false;
	}
    if(x==2 || x== 3 || x==5){
        return true;
    }
	int say=sqrt(x);
	for(int i=0;i<prime.size() && prime[i]<=say;i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}

int totient(int n){
    long long int top=n;
    int t=0;
    while(t<prime.size() && prime[t]*prime[t]<=n){
        int c=0;
        while(n % prime[t]==0){
            n=n/prime[t];
            c++;
        }
        top=(c)?top*(prime[t]-1)/prime[t]:top;
        t++;
    }
    if(n!=1){
        top=top*(n-1)/n;
    }
    return top;
}


int main(){
    double mx=0;
    int n=0;
    
    for(double i=2;i<=1000000;i++){
        if(is_prime(i)){
            prime.push_back(i);
            continue;
        }
        double nmx=mx;
        mx=max(mx,i/totient(i));
        n = (nmx!=mx)?i:n;
    }
    cout<<n;

}