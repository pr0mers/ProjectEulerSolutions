#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int olda=2,oldb=5,oldc=2;
    long long int a=7,b=12,c=4;
    long long int sum=23;
    for(int i=2;i<15;i++){//odd sequence
        /*long long int sq=sqrt(1ll*5*i*i+14*i+1);
        if(sq*sq==1ll*5*i*i+14*i+1){
            if(t%2==0){
                continue;
            }
            t++;
            long long int a=-i-1+sq;
            long long int b=2*i+6;
            long long int c=gcd(a,b);
            a=a/c;
            b=b/c;
            //when i printed a and b i saw that evens and odds are fibonacci sequence itself and for both evens and odds c= oldc * 3 - oldoldc;
            cout<<i<<" "<<a<<"/"<<b<<" "<<c<<endl;
        }*/
        olda=a;
        oldb=b;
        long long int tmpoldc=c;
        a=olda+oldb;
        b=oldb+a;
        c=c*3-oldc;                  
        oldc=tmpoldc;
        sum+=(b*c-6)/2;
    }    
    olda=1,oldb=2,oldc=8;
    a=3,b=5,c=18;
    sum+=47;
    for(int i=2;i<15;i++){//even sequence
        /*long long int sq=sqrt(1ll*5*i*i+14*i+1);
        if(sq*sq==1ll*5*i*i+14*i+1){
            if(t%2==1){
                continue;
            }
            t++;
            long long int a=-i-1+sq;
            long long int b=2*i+6;
            long long int c=gcd(a,b);
            a=a/c;
            b=b/c;
            //when i printed a and b i saw that evens and odds are fibonacci sequence itself and for both evens and odds c= oldc * 3 - oldoldc;
            cout<<i<<" "<<a<<"/"<<b<<" "<<c<<endl;
        }*/
        olda=a;
        oldb=b;
        long long int tmpoldc=c;
        a=olda+oldb;
        b=oldb+a;
        c=c*3-oldc;                  
        oldc=tmpoldc;
        sum+=(b*c-6)/2;
    }    
    cout<<sum;
}