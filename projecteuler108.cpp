#include <bits/stdc++.h>

using namespace std;

int divnum(__int128_t n){
    //nx+ny=xy
    //xy-nx-ny=0
    //(x-n)(y-n)=n^2
    //so if its not n,n one divisor is always lower than n while other is higher than n
    //which means if (x-n) or (y-n) is negative WLOG x>=y, x-n>-n && y-n<-n that means we cannot take any negative divisors of n^2
    __int128_t num=2;
    __int128_t div=1;
    while(num*num<=n){
        __int128_t pownum=0;
        while(n%num==0){
            pownum++;
            n=n/num;
        }
        div=div*(2*pownum+1);
        num++;
    }
    if(n!=1){
        div=div*3;
    }
    return (div+1)/2;
}

int main(){
    for(int n=1260;;n++){
        if(divnum(n)>1000){
            cout<<n<<endl;
            return 0;
        }
    }
}