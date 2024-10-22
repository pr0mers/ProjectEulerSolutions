#include <bits/stdc++.h>
/*

https://en.wikipedia.org/wiki/Farey_sequence#:~:text=.-,Farey%20neighbours,-%5Bedit%5D

*/
using namespace std;


int main(){
    int n=1091091;
    //From wikipedia we learn that neighbor numbers a/b,c/d has property that bc-ad=1
    //so lets assume a/b is the biggest fraction smaller than 3/7 so 3b-7a=1
    //so a=3k+2,b=7k+5 --> gcd(3k+2,7k+5)=1 so we need to find the max
    int k = (n-5)/7;
    cout<<3*k+2;
}   