#include <bits/stdc++.h>

using namespace std;
int numofdiv(int x){
    int say=2;
    int num=1;
    while(say*say<=x){
        int top=0;
        while(x%say==0){
            top++;
            x/=say;
        }
        say++;
        num=num*(top+1);
    }
    if(x!=1){
        num=num*2;
    }
    return num;
}
int main(){
    int num=0;
    for(int i=1;i<=1000000;i++){
        if(i%4!=0){
            continue;
        }
        num=num+numofdiv(i/4)/2;
    }
    cout<<num;
}