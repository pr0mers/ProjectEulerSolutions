#include <bits/stdc++.h>

using namespace std;

int main(){
    int sum=0;
    for(int i=1;i<=499;i++){
        sum+=(4*i+3)*2*i;
    }
    cout<<sum;
}