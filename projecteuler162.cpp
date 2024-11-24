#include <bits/stdc++.h>

using namespace std;
vector<string>hexa={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
long long int N=4;

long long int solve(long long int ind,long long int zero,long long int one, long long int A){
    if(zero>0 && one==1 && A==1){
        return pow(16,N-ind);
    }
    if(ind == N || (zero==ind&&ind!=0)){
        return 0;
    }
    long long int ans=solve(ind+1,zero,one,A);
    ans=ans*13;
    ans=ans+solve(ind+1,zero+1,one,A);
    ans=ans+solve(ind+1,zero,1,A);
    ans=ans+solve(ind+1,zero,one,1);
    return ans;
}
void printhex(long long int n){
    stack<string>s;
    while(n!=0){
        s.push(hexa[n%16]);
        n/=16;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return;
}
int main(){
    long long int ans=0;
    for(long long int i=3;i<=16;i++){
        N=i;
        ans+=solve(0,0,0,0);
    }
    printhex(ans);
}