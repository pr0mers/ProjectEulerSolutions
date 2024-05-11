#include <bits/stdc++.h>

using namespace std;

int dene(int n){
	int toplam=0;
	while(n!=0){
		toplam=toplam+((n%10)*(n%10)*(n%10)*(n%10)*(n%10));
		n=n/10;
	}
	return toplam;
}

int main(){
	int top=0;
	for(int i=10;i<=999999;i++){ // 9^5*n must be >= than 10^(n-1) so number cant have more than 6 digits
		if(dene(i)==i){
			top=top+i;
		}
	}
	cout<<top;
}
