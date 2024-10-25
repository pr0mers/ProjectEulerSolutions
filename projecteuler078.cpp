#include <bits/stdc++.h>
/*


https://oeis.org/search?q=1+2+3+5+7+11+15+22+30&language=english&go=Search#:~:text=a(n)%20%2D%20a(n%2D1)%20%2D%20a(n%2D2)%20%2B%20a(n%2D5)%20%2B%20a(n%2D7)%20%2D%20a(n%2D12)%20%2D%20a(n%2D15)%20%2B%20...%20%3D%200%2C%20where%20the%20sum%20is%20over%20n%2Dk%20and%20k%20is%20a
https://en.wikipedia.org/wiki/Integer_partition#Recurrence_formula:~:text=by%20Euler%27s%20pentagonal%20number%20theorem



*/
using namespace std;
long long int dizi[1000005]={1,1,2,3,5,7,11,15,22};

int main(){
    long long int n=8;
    while(dizi[n]%1000000!=0){
        n++;
        long long int top=0;
        long long int i;
        for(i=1;(3*i*i+i)/2<=n;i++){
            long long int carp = (i%2)?1:-1;
            top = top + (dizi[n-(3*i*i-i)/2] + dizi[n-(3*i*i+i)/2])*carp ;
        }
        if(n-(3*i*i-i)/2 >=0){
            long long int carp = (i%2)?1:-1;
            top = top + dizi[n-(3*i*i-i)/2]*carp;
        }
        dizi[n]= top % 1000000;
        if(dizi[n]<0){
            dizi[n]+=1000000;
        }
    }
    cout<<n;
}   