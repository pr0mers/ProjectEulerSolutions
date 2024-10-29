#include <bits/stdc++.h>

using namespace std;

int main(){
    int fark=99999999;
    int N=2000000;
    int ix,jx;
    for(int i=1;;i++){
        if((i*i-i)/4-N>fark){
            break;
        }
        for(int j=1;j<=i;j++){
            if(((i*i-i)*(j*j-j))/4-N>fark){
                break;
            }
            if(abs(((i*i-i)*(j*j-j))/4-N)<fark){
                fark=abs(((i*i-i)*(j*j-j))/4-N);
                ix=i;
                jx=j;
            }
        }
    }
    cout<<(jx-1)*(ix-1);
    
}