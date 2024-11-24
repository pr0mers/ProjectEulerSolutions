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
        if(s.size()>=2){
            return 2;
        }
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
    for(int i=1;i<50000000;i++){
        if(i%4==1 || i%4==2){//only suitable divisors in order k to be integer is ; i = 4n.4a, (4n+1)(4a+3), (4n+2)(4a+2)
            continue;
        }
        if(i%16 == 8){ // However, if 4 | i -> from 4n.4a 16|i or from (4n+2)(4a+2) i%8 == 4 so it either  has to be i%16==0 or i%8==4
            continue;
        }
        if(solve(i) == 1){
            ans++;
        }
    }
    cout<<ans;
}