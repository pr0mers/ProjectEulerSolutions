#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int toplam=0;
    long long int mx=1000000002/3;
    for(long long int i=2;i<=mx;i++){;
        long long int say=(3*i-1)*(i+1);
        long long int saytam=sqrt(say);
        if((saytam*(i-1))%4==0 && saytam*saytam==say){
            toplam=toplam+i*2+i-1;
        }
        say=(3*i+1)*(i-1);
        saytam=sqrt(say);
        if((saytam*(i+1))%4==0 && saytam*saytam==say){

            toplam=toplam+i*2+i+1;
        }
    }
    cout<<toplam;
}
