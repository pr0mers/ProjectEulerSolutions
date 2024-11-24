#include <bits/stdc++.h>

using namespace std;

bool isbouncy(int x){
    int digit=x%10;
    x=x/10;
    int mn=digit;
    int mx=digit;
    int both=0;
    while(x!=0){
        int tmpmn=mn;
        int tmpmx=mx;
        digit=x%10;
        x=x/10;
        mn=min(digit,mn);
        mx=max(digit,mx);
        if(mn==tmpmn && digit!=mn && mn!=-1){
            mn=-1;
            both++;
        }
        if(mx==tmpmx && digit!=mx && mx!=10){
            mx=10;
            both++;
        }
        if(both==2){
            return true;
        }
    }
    return false;
}

int main(){
    int bounce=0;
    for(int i=1;;i++){
        if(isbouncy(i)){
            bounce++;
        }
        if(bounce*100==i*99){
            cout<<i<<endl;
            return 0;
        }
    }
}