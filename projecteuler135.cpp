#include <bits/stdc++.h>

using namespace std;
int solve(int n){
    //z=a
    //y=a+k
    //x=a+2k
    //x^2-y^2-z^2=3k^2+2ak-a^2=(3k-a)(a+k)=n
    set<pair<int,int>>s;
    int num=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if((i+n/i)%4){
                continue;
            }
            int k= (i+ n/i)/4;
            int a=i-k;
            if(a>0){
                s.insert({a,k});
            }
            a=3*k-i;
            if(a>0){
                s.insert({a,k});
            }
        }
    }
    return s.size();
}

int main(){
    int ans=0;
    for(int i=3;i<1000000;i++){
        if(i%4==1 || i%4==2){
            continue;
        }
        if(solve(i) == 10){
            ans++;
        }
    }
    cout<<ans;
}