#include <bits/stdc++.h>

using namespace std;

__int128  MOD=10000000000;

__int128 power(__int128  a, __int128  b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	__int128 say=power(a,b/2);
	if(b%2==1){
        __int128 tmp=(say*say*a)%MOD;
		return tmp;
	}
	else{
        __int128 tmp=(say*say)%MOD;
		return tmp;
	}
}
void print128(__int128 say) {
    
    stack<char>s;
    while (say > 0) {
        s.push('0'+say%10);
        say=say/10;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main() {
    __int128 x=(power(2,7830457)*28433 +1) %MOD;
    print128(x);
    
}

