#include <bits/stdc++.h>

using namespace std;

int dikmi(int a,int b,int x,int y){

    if(a==x && b==y){
        return 0;
    }
    //00
    //ab
    //xy
    //00
    double alan=abs(a*y-x*b);
    double kenar1=a*a+b*b;
    double kenar2=(x-a)*(x-a)+(y-b)*(y-b);
    double kenar3=x*x+y*y;
    if(kenar1*kenar2==alan*alan || kenar1*kenar3==alan*alan|| kenar2*kenar3 == alan*alan){
        return 1;
    }
    return 0;
    
}


int main() {
    int N=50;
    int top=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==0&&j==0){
                continue;
            }
            for(int ii=0;ii<=N;ii++){
                for(int jj=0;jj<=N;jj++){
                    if(ii==0&&jj==0){
                        continue;
                    }
                    top=top+dikmi(i,j,ii,jj);
                }
            }
        }
    }
    cout<<top/2;
}
