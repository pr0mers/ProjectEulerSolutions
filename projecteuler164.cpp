#include <bits/stdc++.h>

using namespace std;
long long int dizi[25];
long long int dp[25][10][10][10];
long long int N=20;
long long int d;
long long int solve(long long int ind,long long int sum){
    if(sum>9){
        return 0;
    }
    if(ind==N){
        return 1;
    }
    if(ind>=3&&dp[ind][dizi[ind-3]][dizi[ind-2]][dizi[ind-1]]!=0){
        return dp[ind][dizi[ind-3]][dizi[ind-2]][dizi[ind-1]];
    }
    long long int ans=0;
    for(long long int i=0;i<=9-sum;i++){
        dizi[ind]=i;
        ans+=solve(ind+1,sum-dizi[ind-2]+i);
    }
    dp[ind][dizi[ind-3]][dizi[ind-2]][dizi[ind-1]]=ans;
    return ans;
}
int main(){
    long long int ans=0;
    for(long long int i=1;i<=9;i++){
        for(long long int j=0;j<=9;j++){  
            dizi[0]=i;
            dizi[1]=j;
            ans=ans+solve(2,i+j);
        }
    }
    cout<<ans;
}