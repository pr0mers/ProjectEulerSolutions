#include <bits/stdc++.h>

using namespace std;
vector<__int128_t>prime;

__int128_t MX=999999999999999999;
bool is_prime(__int128_t x){
	__int128_t say=sqrt(x);
	for(__int128_t i=0;prime[i]<=say;i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}

__int128_t divnum(__int128_t n){
    vector<__int128_t>numsdiv;
    __int128_t num=2;
    while(num*num<=n){
        while(n%num==0){
            n=n/num;
            numsdiv.push_back(num);
        }
        num++;
    }
    if(n!=1){
        numsdiv.push_back(n);
    }
    sort(numsdiv.begin(), numsdiv.end(), greater<__int128_t>());
    __int128_t carpim=1;
    for(__int128_t i=0;i<numsdiv.size();i++){
        if(numsdiv[i]>=40 || numsdiv[i]%2==0){
            return MX;
        }
        carpim=carpim*pow(prime[i],(numsdiv[i]-1)/2);
        carpim=min(carpim,MX);
    }
    return carpim;
}
void print128(__int128_t x){
    stack<int>s;
    while(x!=0){
        int l=x%10;
        s.push(l);
        x=x/10;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return;
}
int main(){
    prime.push_back(2);
    prime.push_back(3); 
    for(__int128_t i=4;i<10000;i++){
        if(is_prime(i)){
            prime.push_back(i);
        }
    }
    __int128_t mn =MX;
    for(long long int n=8000000;n<10000000;n++){
        int tmpmn=mn;
        __int128_t x=divnum(n);
        if(x<mn){
            mn=x;
            if(mn<0){
                mn=tmpmn;
                continue;
            }
        }
    }
    print128(mn);

}