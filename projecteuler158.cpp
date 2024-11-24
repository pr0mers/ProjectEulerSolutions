#include <bits/stdc++.h>
using namespace std;
int N=26     +1;
unsigned long long combination(long long int n, long long int k) {
    if (k > n || k < 0){
        return 0;
    }
    k=(n-k>k)?k:n-k;
    unsigned long long ans = 1;
    for (long long int i = 0; i < k; ++i) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

long long int solve(long long int n){
    //return combination(N-1,n)*(pow(2,n)-n-1);
    /*--------------- Faster Solution (but i've made the second one before this)-----------------
    long long int ans=0;
    for(long long int i=n;i<N;i++){   ===========> this for is also equal to combination(N-1,n) so we can directly return combination(N-1,n)*(pow(2,n)-n-1)
        ans=ans+combination(i-1,n-1);
    }
    return ans*(pow(2,n)-n-1);*/
    long long int ans=0;
    for(long long int i=2;i<=n;i++){
        for(int j=n-i+1;j<N;j++){
            ans=ans+combination(j-1,n-i)*(combination(N-n+i-2,i-1)-combination(N-1-j,i-1));
        }
    }
    return ans;
}
int main(){
    long long int mx=0; 
    for(long long int i=2;i<N;i++){
        mx=max(mx,solve(i));    
    }
    cout<<mx;
}