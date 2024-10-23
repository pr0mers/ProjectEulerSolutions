#include <bits/stdc++.h>
/*

https://en.wikipedia.org/wiki/Farey_sequence#:~:text=.-,Farey%20neighbours,-%5Bedit%5D

We used the same thing with problem 071 just more generalized.

*/
using namespace std;
int n=12000;
int bulyan(int a,int b){
    int top=0;
    while(!(a==1 && b==3)){
        int c,d; // ad-bc =1
        for(int i=1;i<= a;i++){
            if((1+b*i) % a ==0){
                c=i; // c = a*k +i
                d= (1+b*i)/a;  // d= b*k + (1+b*i)/a;
                break;
            }
        }
        int k = (n-(1+b*c)/a)/b;
        d=d+b*k;
        c=c+a*k;
        a=c;
        b=d;
        top++;
    }
    return top-1;
}

int main(){

    //From wikipedia we learn that neighbor numbers a/b,c/d has property that bc-ad=1
    //so lets assume a/b is the biggest fraction smaller than 3/7 so 3b-7a=1
    //so a=3k+2,b=7k+5 --> gcd(3k+2,7k+5)=1 so we need to find the max
    cout<<bulyan(1,2);
}   