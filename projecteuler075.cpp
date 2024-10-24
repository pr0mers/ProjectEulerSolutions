#include <bits/stdc++.h>
/*

https://en.wikipedia.org/wiki/Pythagorean_triple#:~:text=68%2C%20285%2C%20293)-,Generating%20a%20triple,-%5Bedit%5D

*/
using namespace std;

int dizi[1500005];
vector<int>prime;
bool is_prime(int x){
	if(x==0 ||x==1){
		return false;
	}
	int say=sqrt(x);
	for(int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int bul(int x){
    int top=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            top = top + dizi[i]+dizi[x/i];
            if(top>1){
                return 0;
            }  
        }
    }
    return top;
}
int main(){
    int top=0;
    long long int N=1500000;
    for(long long int m=2;m<=N;m++){
        if(is_prime(m)){
            prime.push_back(m);
        }
        for(long long int n =((m%2==0)?1:2);n<m;n=n+2){
            if(2*m*(m+n)>N){
                break;
            }
            if(gcd(m*m-n*n,gcd(2*m*n,m*m+n*n))==1) {
                dizi[2*m*(m+n)]++;
            }
        }
    }
    for(int i=12;i<=N;i++){
        if(bul(i)==1){
            top++;
        }
    }
    cout<<top;
}   