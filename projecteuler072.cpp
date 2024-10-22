#include <bits/stdc++.h>
/*

https://en.wikipedia.org/wiki/Farey_sequence#:~:text=%5Bedit%5D-,Sequence%20length%20and%20index%20of%20a%20fraction,-%5Bedit%5D

*/
using namespace std;

int totient(int n){
    long long int top=n;
    int t=2;
    while(t*t<=n){
        int c=0;
        while(n%t==0){
            c++;
            n=n/t;
        }
        top=(c)?top*(t-1)/t:top;
        t++;
    }
    if(n!=1){
        top=top*(n-1)/n;
    }
    return top;
}

int main(){
    long long int top=0;
    for(int i =1;i<=1000000;i++){
        top=top+totient(i);
    }
    cout<<top-1;
}   