#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>>points;

int N=6;

int solve(int ind,int rem,int dart){
    if(ind>=points.size()||rem<0||dart>3){
        return 0;
    }
    if(rem==0){
        return 1;
    }
    int num=0;
    for(int i=ind;i<points.size();i++){
        num+=solve(i,rem-points[i].first,dart+1);
    }
    return num;
}

int main(){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=3;j++){
            points.push_back(make_pair(i*j,j));
        }
    }
    points.push_back(make_pair(25,1));
    points.push_back(make_pair(50,2));
    sort(points.begin(),points.end(),greater<pair<int,int>>());
    int sum=0;
    for(int j=2;j<100;j++){
        N=j;
        for(int i=0;i<points.size();i++){
            if(points[i].second==2){
                sum+=solve(0,N-points[i].first,1);
            }
        }    
    }
    cout<<sum;
}