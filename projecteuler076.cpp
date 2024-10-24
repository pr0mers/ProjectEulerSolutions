#include <bits/stdc++.h>

using namespace std;

int dizi[105][105];

int dene(int say,int mn){
    if(say<0){
        return 0;
    }
    if(say==0 || mn==1){
        return 1;
    }
    if(dizi[say][mn]!=0){
        return dizi[say][mn];
    }
    int top=0;
    for(int i=mn;i>0;i--){
        top=top+dene(say-i,i);
    }
    dizi[say][mn]=top;
    return top;
}

int main(){
    cout<<dene(100,100)-1;
}   