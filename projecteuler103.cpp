#include <bits/stdc++.h>

using namespace std;

int N = 255;
vector<int>ans={};
int mn=256;
int isspecial(vector<int>special){
    int siz=special.size();
    int twosiz=1<<siz;
    for(int i=1;i<twosiz;i++){
        pair<int,int> sumone=make_pair(0,0);
        for(int j=0;j<siz;j++){
            if((i & (1<<j)) != 0){
                sumone.first+=special[j];
                sumone.second++;
            }
        }        
        for(int k=i+1;k<twosiz;k++){
            pair<int,int> sumzero=make_pair(0,0);
            if ((i & k)!=0) {
                continue;
            }
            for (int l=0;l<siz;l++) {
                if ((k & (1<<l)) != 0) {
                    sumzero.first+=special[l];
                    sumzero.second++;
                }
            }
            if(sumzero.second==0 || sumone.second==0){
                continue;
            }
            if(sumone.first == sumzero.first || (sumone.second>sumzero.second && sumone.first<=sumzero.first) || (sumone.second<sumzero.second && sumone.first>=sumzero.first)){
                return 0;
            }

        } 
    }
    return 1;
}

void setfinder(int x, vector<int>vset){
    //cout<<x<<" "<<vset.size()<<endl;
    if(vset.size()>=8){
        return;
    }
    int top=0;
    for(int i=0;i<vset.size();i++){
        top=top+vset[i];
    }
    if(top>N){
        return;
    }
    if(vset.size()==7){
        if(isspecial(vset)){
            if(top<mn){
                mn=top;
                ans=vset;
            }
        }
    }
    for(int i=x+1;i<=N-top && (x+1)*(7-vset.size())<=mn;i++){
        vset.push_back(i);
        setfinder(i,vset);
        vset.pop_back();
    }
}


int main(){
    //Expected(b,b+a1,b+a2,b+a3,b+a4,b+a5,b+a6) : 20, 31, 38, 39, 40, 42, 45 ==> 255
    vector<int>tempv={};
    for(int i=19;i<=N && 7*i<=mn;i++){
        tempv.push_back(i);
        setfinder(i,tempv);
        tempv.pop_back();
    }
    for(auto it : ans){
        cout<<it;
    }
}