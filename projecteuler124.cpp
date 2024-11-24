#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>>rad;

int solve(int x)
{
    int ans=1;
    int say=2;
    while(say*say<=x){
        int top=0;
        while(x%say==0){
            if(top==0){
                ans=ans*say;
            }
            top++;
            x=x/say;
        }
        say++;
    }
    if(x!=1){
        ans=ans*x;
    }
    return ans;
}
int main(){
    rad.push_back({1,1});
    for(int i=2;i<=100000;i++){
        int say=solve(i);;
        rad.push_back({say,i});
    }
    sort(rad.begin(),rad.end());
    cout<<rad[9999].second;
}