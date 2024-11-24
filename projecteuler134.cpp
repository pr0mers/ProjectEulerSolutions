/*


https://en.wikipedia.org/wiki/Chinese_remainder_theorem#:~:text=number%20of%20moduli.-,Case%20of%20two%20moduli,-%5Bedit%5D
Chinese Remainder Theorem : Two Moduli.


*/
#include <bits/stdc++.h>

using namespace std;

vector<long long int>prime;
pair<long long int,long long int> ExtendedGCD(long long int n1,long long int n2){
    //n1m1+n2m2=1;
    long long int oldr = n1, olds = 1, oldt = 0, r = n2, s = 0, t = 1;
    while(r){
        long long int q=oldr/r;
        long long int temp=oldr-q*r;
        oldr=r;
        r=temp;
        temp=olds-q*s;
        olds=s;
        s=temp;
        temp=oldt-q*t;
        oldt=t;
        t=temp;
    }
    return {olds,oldt};
}
bool is_prime(long long int x){
	long long int say=sqrt(x);
	for(long long int i=0;prime[i]<=say;i++){
		if(x%prime[i]==0){
			return false;
		}
	}
	return true;
}
long long int solve(long long int n1){
    //NUMBER % n1 = 0
    //NUMBER % n2 = smallprime
    long long int smallprime=prime[prime.size()-2];
    long long int n2=1;
    while(smallprime!=0){
        n2*=10;
        smallprime/=10;
    }
    pair<int,int> m1m2 = ExtendedGCD(n1,n2);
    long long int m1=m1m2.first;
    long long int ans=(prime[prime.size()-2]*n1*m1)%(n1*n2);    
    while(ans<0){
        ans=ans+n1*n2;
    }   
    return ans;
}
int main(){
    prime.push_back(2);
    prime.push_back(3); 
    prime.push_back(5);
    long long int sum=0;
    for(long long int i=7;prime[prime.size()-1]<=1000000;i++){
        if(is_prime(i)){
            prime.push_back(i);
            sum+=solve(i);
        }
    }
    cout<<sum;
}