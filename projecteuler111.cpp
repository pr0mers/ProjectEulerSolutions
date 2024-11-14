#include <bits/stdc++.h>

using namespace std;

string str(10, '!');

long long int ans=0;

bool is_prime(long long int x){
	if(x==0 ||x==1){
		return false;
	}
	long long int say=sqrt(x);
	for(long long int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

void bul(long long int ind,long long int n,long long int d,long long int say){
    if(ind==n){
        if(is_prime(say)){
            ans+=say;
        }
        return;
    }
    if(str[ind]==d+'0'){
        bul(ind+1,n,d,say+pow(10,ind)*d);
    }
    else{
        for(long long int i=0;i<10;i++){
            if(i==d || (i==0 && ind==n-1)){
                continue;
            }
            bul(ind+1,n,d,say+pow(10,ind)*i);
        }
    }
    return;
}

void oluyormu(long long int ind,long long int mx,long long int n,long long int d){
    if(mx==0){
        if(str[n-1]=='0'){
            return;
        }
        bul(0,n,d,0);
        return;
    }
    if(mx<0 || ind>=n){
        return;
    }
    str[ind]='0'+d;
    oluyormu(ind+1,mx-1,n,d);
    str[ind]='!';
    oluyormu(ind+1,mx,n,d);
}

long long int M(long long int n,long long int d){
    ans=0;
    for(long long int i=n;i>0;i--){
        long long int tmpans=ans; 
        oluyormu(0,i,n,d);
        if(ans!=tmpans){
            return ans;
        }
    }
    return 0;
}

int main(){
    long long int sum=0;
    for(long long int i=0;i<10;i++){
        long long int x=M(10,i);
        sum+=x;
    }
    cout<<sum;
}