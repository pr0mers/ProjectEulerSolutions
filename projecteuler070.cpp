#include <bits/stdc++.h>

using namespace std;
vector<int>prime;

int dizi[10];

bool is_permutation(int a, int b){
    for(int i=0;i<10;i++){
        dizi[i]=0;
    }
    while(a!=0){
        dizi[a%10]++;
        a=a/10;
    }
    while(b!=0){
        dizi[b%10]--;
        b=b/10;
    }
    for(int i=0;i<10;i++){
        if(dizi[i]!=0){
            return false;
        }
    }
    return true;
}

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
    double mn=10000000;
    int n=0;
    for(double i=2;i<=10000000;i++){
        if(is_prime(i)){
            prime.push_back(i);
            continue;
        }
        int tot=totient(i);
        if(is_permutation(i,tot)){
            double nmn=mn;
            mn=min(mn,i/tot);
            n = (nmn!=mn)?i:n;
            if(n==0){
                cout<<i<<endl;
            }
        }

    }
    cout<<n;
}