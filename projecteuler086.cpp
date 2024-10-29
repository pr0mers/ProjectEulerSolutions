#include <bits/stdc++.h>

using namespace std;

int main(){
    int M=0;
    int top=0;
    while(top<1000000){
        M++;
        int i=M;
        for(int j=1;j<=i;j++){
            for(int k=1;k<=j;k++){
                int a=min(i*i+(j+k)*(j+k),min(k*k+(j+i)*(j+i),j*j+(i+k)*(i+k)));
                int b=sqrt(a);
                if(b*b==a){
                    top++;
                }
            }
        }
    }
    cout<<M;
}