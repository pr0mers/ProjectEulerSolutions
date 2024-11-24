#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int olda=1,oldb=2,oldc=2;
    long long int a=3,b=5,c=6;
    for(int i=2;i<15;i++){
        /*long long int sq=sqrt(1ll*5*i*i+2*i+1);
        if(sq*sq==1ll*5*i*i+2*i+1){
            long long int a=-i-1+sq;
            long long int b=2*i;
            long long int c=gcd(a,b);
            a=a/c;
            b=b/c;
            //when i printed a and b i saw that a,b,..., is fibonacci sequence itself and c= oldc * 3 - oldoldc;
            cout<<i<<" "<<a<<"/"<<b<<" "<<c<<endl;
        }*/
        olda=a;
        oldb=b;
        long long int tmpoldc=c;
        a=olda+oldb;
        b=oldb+a;
        c=c*3-oldc;                  
        oldc=tmpoldc;
    }    
    cout<<b*c/2;
}