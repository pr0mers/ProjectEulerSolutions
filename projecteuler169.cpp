/*

https://oeis.org/A002487

*/

#include <bits/stdc++.h>

using namespace std;

__int128_t dizi[100000000]={1,1,2,1,3,2,3,1,4,3};
__int128_t coz(__int128_t sayi){
    if(sayi<10 || (sayi<100000000 && dizi[sayi]!=0)){
        return dizi[sayi];
    }
    while(sayi%2!=0){
        sayi=sayi/2;
    }
    __int128_t cvp=coz(sayi/2)+coz(sayi/2 -1);
    if(sayi<100000000){
        dizi[sayi]=cvp;
    }
    return cvp;
}
void print128int(__int128_t saysay){
    stack<int>s;
    while(saysay!=0){
        s.push(saysay%10);
        saysay=saysay/10;
    }
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return;
}
int main(){
    __int128_t sayim=1;
    for(int i=0;i<25;i++){
        sayim=sayim*10;
    }
    print128int(coz(sayim));
}