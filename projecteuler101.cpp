#include <bits/stdc++.h>

using namespace std;
vector<pair<long long int,long long int>>funcval;

long long int f(long long int x){
    return (pow(x,11)+1)/(x+1);
}
long long int divdiff(long long int k,long long int j){
    if(k==j){
        return funcval[k].second;
    }
    return (divdiff(k+1,j)-divdiff(k,j-1))/(funcval[j].first-funcval[k].first);
}
long long int newtonpolynominal(long long int k){
    long long int say=0;
    for(long long int i=0;i<k;i++){
        long long int coef=divdiff(0,i);
        for(long long int j=0;j<i;j++){
            coef=coef*(k+1-funcval[j].first);
        }
        say=say+coef;
    }
    return say;
}

int main(){
    long long int top=0;
    long long int i;
    for(i=1;i<=10;i++){
        funcval.push_back(make_pair(i,f(i)));
        long long int a=newtonpolynominal(i);
        top=top+a;
    }
    cout<<top;
}