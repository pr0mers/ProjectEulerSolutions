#include <bits/stdc++.h>

using namespace std;
unordered_set<long long int>s;
vector<long long int>prime;
bool is_prime(long long int x){
	if(x==0 ||x==1){
		return false;
	}
	long long int say=sqrt(x);
	for(long long int i=0;i<prime.size();i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}

int main(){
    long long int top=0;
    prime.push_back(2);
    prime.push_back(3);
    for(long long int i=4;i<10000;i++){
        if(is_prime(i)==true){
            prime.push_back(i);
        }
    }
    for(long long int i=0;i<prime.size();i++){
        for(long long int j=0;j<prime.size();j++){
            for(long long int l=0;l<prime.size();l++){
                if(prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[l]*prime[l]*prime[l]*prime[l]>=50000000){
                    break;
                }
                s.insert(prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[l]*prime[l]*prime[l]*prime[l]);
            }
        }
    }
    cout<<s.size();
}