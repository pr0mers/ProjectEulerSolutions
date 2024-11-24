#include <bits/stdc++.h>

using namespace std;

long long int N=50;
long long int M=50;
long long int allarr[1005];
long long int all(long long int ind,long long int redrem,char c){
    if(ind==0){
        if(redrem<M && redrem!=0){
            return 0;
        }
        return 1;
    }
    if(allarr[ind]!=0&&c=='g'){
        return allarr[ind];
    }
    long long int top=0;  
    top+=all(ind-1,redrem+1,'r');
    if(redrem>=M || c=='g'){
        top+=all(ind-1,0,'g');
    }
    if(c=='g'){
        allarr[ind]=top;
    }
    return top;
}


int main(){
    for(int i=50;;i++){
        N=i;
        memset(allarr,0,sizeof(allarr));
        if(all(N,0,'g')>1000000){
            cout<<N<<endl;
            return 0;
        }
    }
}