#include <bits/stdc++.h>

using namespace std;
set<int>v[10];
int tmptane[10][10];
int tpo=0;
int dizi[55]={319,680,180,690,129,620,762,689,762,318,368,710,720,710,629,168,160,689,716,731,736,729,316,729,729,710,769,290,719,680,318,389,162,289,162,718,729,319,790,680,890,362,319,760,316,729,380,319,728,716};
int minpoz[10];
vector<int>vs(999,-1);
bool oluyormu(vector<int>vd){
    for(int i=0;i<10;i++){
        minpoz[i]=-1;
    }
    for(int i=0;i<vd.size();i++){
        if(minpoz[vd[i]]!=-1){
            continue;
        }
        minpoz[vd[i]]=i;
    }
    if(tpo==1){
        for(int i=0;i<10;i++){
            cout<<minpoz[i]<<" "<<i<<endl;
        }
    }
    for(int i=0;i<50;i++){
        int bir=dizi[i]/100;
        int iki=dizi[i]/10 % 10;
        int uc = dizi[i] %10;
        if(minpoz[bir]==-1 || minpoz[iki]==-1 || minpoz[uc]==-1){
            return false;
        }
        if(!(minpoz[iki]>minpoz[bir] && minpoz[uc]>minpoz[iki])){
            return false;
        }
    }
    return true;
}
vector<int> dene(int n,vector<int>vi,int ztane[10][10]){
    int tane[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tane[i][j]=ztane[i][j];
        }
    }
    vector<int>vgec=vi;
    vgec.push_back(n);
    if(oluyormu(vgec)==true){
        return vgec;
    }
    for(auto it: v[n]){
        tane[n][it]--;
        if(tane[n][it]<0){
            return vs;
        }
        vector<int>dn=dene(it,vgec,tane);
        if(dn.size()<vs.size() && oluyormu(dn)==true){
            vs=dn;
        }
    }
    return vs;
}
int main(){
    for(int i=0;i<50;i++){
        int bir=dizi[i]/100;
        int iki=dizi[i]/10 % 10;
        int uc = dizi[i] %10;
        tmptane[bir][iki]++;
        tmptane[bir][uc]++;
        tmptane[iki][uc]++;
        v[bir].insert(iki);
        v[bir].insert(uc);
        v[iki].insert(uc);
    }
    int kls=0;
    for(int i=1;i<10;i++){
        vector<int>v;
        vector<int>vz=dene(i,v,tmptane);
        if(vz.size()<vs.size()){
            vs=vz;
        }
    }
    for(auto it:vs){
        cout<<it;
    }    
}   