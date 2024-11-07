#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a=15;
    long long int b=6;
    while(a+b<=1000000000000){
        long long int t=b;
        b=2*a+b-1;
        a=5*a+2*t-2;
    }
    cout<<a;
}

