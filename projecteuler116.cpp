#include <bits/stdc++.h>

using namespace std;

long long int N=50;
long long int allarr[55];
long long int greenarr[55];
long long int bluearr[55];

long long int all(long long int ind){
    if(ind<0){
        return 0;
    }
    if(ind==0){
        return 1;
    }
    if(allarr[ind]!=0){
        return allarr[ind];
    }
    allarr[ind]=all(ind-1)+all(ind-2)+all(ind-3)+all(ind-4);
    return allarr[ind];
}


int main(){
    cout<<all(N);
}