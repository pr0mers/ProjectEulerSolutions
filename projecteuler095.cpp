#include <bits/stdc++.h>

using namespace std;
int N=1000000;
int dizi[1000005];
int topdiv(int x){
    int top=1;
    for(int i =2;i*i<=x;i++){
        if(x%i==0){
            top=top+i;
            if(x/i != i){
                top=top+x/i;
            }
        }
    }
    return top;
}
pair<int,int> chain(int x,int ind){
    //cout<<x<<" "<<ind<<endl;
    if(x>N){
        return make_pair(0,0);
    }
    if(dizi[x]!=0){
        return make_pair(ind-dizi[x],x);
    }
    dizi[x]=ind;
    pair<int,int> say=chain(topdiv(x),ind+1);
    dizi[x]=0;
    return make_pair(say.first,say.second);
}

int main() {
    int mx=0;
    int sayim=0;
    for(int i=1;i<=N;i++){
        int ch=mx;
        pair<int,int>p=chain(i,1);
        mx=max(p.first,mx);
        if(ch!=mx){
            sayim=p.second;
        }
    }
    cout<<sayim<<" "<<mx;
}

