#include <bits/stdc++.h>

using namespace std;


int N=59;
int mn=999;
int solve(vector<int>chain){
    if(chain[chain.size()-1]==N){
        return chain.size();
    }
    if(chain.size()>=mn){
        return 999;
    }
    for(int i=chain.size()-1;i>=0;i--){
        if(chain[i]+chain[chain.size()-1]>N){
            continue;
        }
        chain.push_back(chain[i]+chain[chain.size()-1]);
        mn=min(mn,solve(chain));
        chain.pop_back();
    }
    return mn;
}

int main(){
    int sum=0;
    for(int i=1;i<=200;i++){
        N=i;
        mn=999;
        vector<int>v={1};
        sum=sum+solve(v)-1;
    } 
    cout<<sum;
}