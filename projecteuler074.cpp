#include <bits/stdc++.h>

using namespace std;

int dizi[2200000];
int factorial[11]={1,1,2,6,24,120,720,5040,40320,362880};
vector<int>v;
int fact(int n){
    if(dizi[n]!=0){
        for(int i=0;i<v.size();i++){
            dizi[v[i]]=0;
        }
        v.clear();
        return 0;

    }
    v.push_back(n);
    dizi[n]=1;
    int top=0;
    while(n!=0){
        top=top+factorial[n%10];
        n=n/10;
    }
    return fact(top)+1;
}

int main(){
    int t =0;
    for(int i=1;i<=1000000;i++){
        t += (fact(i)==60)?1:0;
    }
    cout<<t;
}   