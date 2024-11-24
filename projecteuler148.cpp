#include <bits/stdc++.h>

using namespace std;

vector<int>v={0,0,0,0,0,0,0,0,0,0,0,0};
/*      SLOWER WAY (might be better for understanding)
long long int sumofbase7(int num){
    long long int ans=1;
    while(num!=0){
        ans=ans*(num%7 +1);
        num=num/7;
    }
    return ans;
}
*/
long long int vadd(long long int lastprod){ // product of number+1 where number = nth digit of i in base 7
    long long int i=0;
    while(v[i]==6){
        v[i]=0;
        lastprod/=7;
        i++;
    }
    v[i]++;
    lastprod=lastprod/v[i]*(v[i]+1);
    return lastprod;
}

int main(){
    long long int ans=0;
    long long int lastprod=1;
    for(int i=0;i<1000000000;i++){
        //ans+=sumofbase7(i);   SLOWER WAY
        ans+=lastprod;
        lastprod=vadd(lastprod);
    }   
    cout<<ans;
}