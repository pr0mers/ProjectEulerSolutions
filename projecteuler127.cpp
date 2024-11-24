#include <bits/stdc++.h>

using namespace std;

long long int dizi[120005];

long long int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

long long int solve(long long int n){
    int top=0;
    for(long long int i=1;2*i<n;i++){
        if(dizi[i]*dizi[n-i]*dizi[n]<n && gcd(i,n-i)==1 ){
            top++;
        }
    }
    return top;
}
int main(){
    for(int i=0;i<120000;i++){
        dizi[i]=1;
    }
    for(int i=2;i<120000;i++){
        if(dizi[i]!=1){
            continue;
        }
        for(int j=1;i*j<120000;j++){
            dizi[i*j]=dizi[i*j]*i;
        }
    }
    long long int top=0;
    for(long long int i=3;i<120000;i++){
        long long int x=solve(i);
        top=top+x*i;
    }
    cout<<top;
}