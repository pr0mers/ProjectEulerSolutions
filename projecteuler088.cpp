#include <bits/stdc++.h>

using namespace std;

int dizi[100005];
int tane=0;
void dene(int say,int mn,int carpim,int toplam,int N,int yap){
    if(mn == 1){
        int nbir=carpim-toplam;
        if(nbir>=0 && carpim==N)
            if(dizi[yap+nbir]==0){
                dizi[yap+nbir]=N;
            }
        return;
    }
    if(toplam==carpim && carpim==N){
        if(yap!=1){
            if(dizi[yap]==0){
                dizi[yap]=N;
            }
            return;    
        }
    }
    vector<int>v;
    for(int i =1;i*i<=say;i++){
        if(say%i==0){
            v.push_back(i);
            if(say != i*i){
                v.push_back(say/i);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]<=mn){
            dene(say/v[i],v[i],carpim*v[i],toplam+v[i],N,yap+1);
        }
    }
    return;
}

int main(){
    for(int sa=0;sa<=24000;sa++){
        dene(sa,sa,1,0,sa,0);
       
    } 
    int ola=0;
    unordered_set<int>s;
    for(int i=2;i<=12000;i++){
        s.insert(dizi[i]);
    }
    int top=0;
    for(auto it :s){
        top=top+it;
    }
    cout<<top;
}   