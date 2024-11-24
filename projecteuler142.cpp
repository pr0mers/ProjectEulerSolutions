#include <bits/stdc++.h>

using namespace std;

int main(){
    for(long long int a=3;;a++){
        for(long long int b=(a%2)?3:2;b<a;b=b+2){
            if(b%2!=a%2){
                continue;
            }
            for(long long int c=sqrt((a*a+b*b)/2)+1;c<a;c++){
                long long int x= (a*a+b*b)/2;
                long long int y= (a*a-b*b)/2;
                long long int z= (2*c*c-a*a-b*b)/2;
                long long int sqd=sqrt(x-z);
                long long int sqe=sqrt(y+z);
                long long int sqf=sqrt(y-z);
                if(sqd*sqd==x-z && sqe*sqe==y+z && sqf*sqf==y-z){
                    cout<<x<<" "<<y<<" "<<z<<"/"<<x+y+z<<endl;
                    return 0;
                }
            }
        }
    }
}