#include <bits/stdc++.h>

using namespace std;
double dene(vector<int>A){
    int say=0;
    for(int i=2;i<=5;i++){
        say+=A[i];
    }
    double ans=0;
    if(say==1){ 
        if(A[5]==1){
            return 0;
        }
        ans=1;  
    }
    for(int i=2;i<=5;i++){
        double iht=1.0*A[i]/say;
        if(iht==0){
            continue;
        }
        vector<int>tmpA=A;
        tmpA[i]--;
        for(int j=i+1;j<=5;j++){
            tmpA[j]++;
        }
        ans+=dene(tmpA)*iht;
    }
    return ans;
}
int main(){
    vector<int>A={0,0,1,1,1,1};
    cout<<dene(A);
}