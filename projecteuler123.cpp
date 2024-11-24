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

int main(){
    prime.push_back(2);
    for(int i=3;i<1000000;i++){
        if(is_prime(i)){
            prime.push_back(i);
            if(prime.size()%2){
                if(2*prime.size()*i>10000000000){
                    cout<<prime.size();
                    return 0;
                }
            }
        }
    }
}