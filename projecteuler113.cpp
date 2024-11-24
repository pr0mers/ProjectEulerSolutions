/*


https://oeis.org/A364342


*/
#include <bits/stdc++.h>

using namespace std;

unsigned long long combination(int n, int k) {
    if (k > n || k < 0){
        return 0;
    }
    k=(n-k>k)?k:n-k;
    unsigned long long ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

int main(){
    int N=100;
    cout<<combination(N+9,9)+(N+1)*combination(N+10,9)/10-10*100-2;
}