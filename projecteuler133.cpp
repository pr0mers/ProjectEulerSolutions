#include <bits/stdc++.h>

using namespace std;
vector<long long int>prime;
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

long long int phi(long long int n){
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
bool is_prime(long long int x){
	long long int say=sqrt(x);
	for(long long int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
bool solve(long long int x){
    long long int p=x;
    x=phi(x);
    long long int two=0;
    long long int five=0;
    while(x%2==0){
        two++;
        x=x/2;
    }
    while(x%5==0){
        five++;
        x=x/5;
    }
    long long int tt=1;
    long long int ff=1;
    for(long long int i=0;i<=two;i++){
        if(i!=0){
            tt=tt*2;
        }
        ff=1;
        for(long long int j=0;j<=five;j++){
            if(j!=0){
                ff=ff*5;
            }
            long long int num=tt*ff;
            if(power(10,num,p)==1){
                cout<<num<<" "<<p;
                return true;
            }
        }
    }   
    return false;
}
int main(){
    long long int ans=10;
    /*for(long long int i=6 ;i<100000;i++){
        if(is_prime(i)){
            prime.push_back(i);
            if(!solve(i)){
                ans=ans+i;
            }
        }
    }
    cout<<ans;*/
    prime.push_back(2);
    prime.push_back(3);
    cout<<solve(3);
}