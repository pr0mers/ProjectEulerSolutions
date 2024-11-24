#include <bits/stdc++.h>
/*

https://projecteuler.net/problem=75
https://en.wikipedia.org/wiki/Pythagorean_triple#:~:text=68%2C%20285%2C%20293)-,Generating%20a%20triple,-%5Bedit%5D

*/
using namespace std;

int main(){
    long long int top=0;
    long long int N=100000000;
    //long long int N =100;
    for(long long int m=1;m*2*m<N;m++){
        for(long long int n=1;n<m;n++){
            if(m%2 == n%2 || gcd(m,n)!=1){
                continue;
            }
            long long int a=m*m-n*n;
            long long int b=2*m*n;
            long long int c=m*m+n*n;
            long long int fark=abs(a-b);
            if(c%fark == 0){
                cout<<a<<" "<<b<<" "<<c<<endl;
                top+=(N)/(a+b+c);
            }
        }
    }
    cout<<top;
}   