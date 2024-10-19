#include <bits/stdc++.h>

using namespace std;

long long int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int a0,b0,c0;

int lla=0;
int sa=0;
int bul(int n,int pay,int bolu,int car){
    
    int gc=gcd(bolu,car);
    bolu=bolu/gc;
    car=car/gc;
    int t=0;
    int kok=sqrt(n);
    t=(pay+kok)/bolu;
    pay=pay-t*bolu;
    if(abs(pay)==b0 && bolu==c0 && t==a0){
        return sa;
    }
    sa++;
    if(lla==0){
        b0=abs(pay);
        c0=bolu;
        a0=t;

    }
    lla=1;
    return bul(n,abs(pay), n-pay*pay,bolu);
}


int main(){

    int top=0;
    for(int i=2;i<=10000;i++){
        sa=0;
        lla=0;
        int ix=sqrt(i); 
        if(ix*ix != i && bul(i, ix,i-ix*ix,1)%2==1){
            top++;
        }
    }
    cout<<top;
}
