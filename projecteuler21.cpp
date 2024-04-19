#include <bits/stdc++.h>

using namespace std;
int bolentop(int x){
	if(x==1){
		return 1;
	}
	int a=x;
	int cvp=1;
	for(int i=2;i<=x;i++){
		int s=0;
		int n=0;
		while(x%i==0){
			n=n+1;
			s=s+pow(i,n);
			x=x/i;
		}
		cvp=cvp*(s+1);
	}
	return cvp-a;
}
int main(){
	int toplam=0;
	for(int i=1;i<=10000;i++){
		int j=bolentop(bolentop(i));
		if(i==j && i!= bolentop(i)){
			toplam=toplam+i;
		}
	}
	cout<<toplam;
}
