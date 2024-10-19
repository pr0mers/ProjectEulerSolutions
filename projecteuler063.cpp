#include <bits/stdc++.h>

using namespace std;

__int128 powera(int a, int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	__int128 say=powera(a,b/2);
	if(b%2==1){
		return say*say*a;
	}
	else{
		return say*say;
	}
}


int bas(__int128 x){
    int b=0;
    while(x!=0){
        b++;
        x=x/10;
    }
    return b;
}

int main(){
    int top=0;
    for(int i=1;;i++){
        int m=0;
        for(int j=1;j<=9;j++){
            if(bas(powera(j,i))==i){
                top=top+10-j;
                m=1;
                break;
            }
        }
        if(m==0){
            cout<<top;
            return 0;
        }
    }
}