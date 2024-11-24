/*

https://oeis.org/A007805

*/
#include <bits/stdc++.h>

using namespace std;

int main(){     
    long long int a=17,b=305;
    long long int sum=a+b;
    for(int i=2;i<12;i++){
        /* This works too :)
            b=18*b-a;
            a=(b+a)/18;
        */
        long long int c=18*b-a;
        a=b;
        b=c;
        sum+=b;
    }    
    cout<<sum;
}