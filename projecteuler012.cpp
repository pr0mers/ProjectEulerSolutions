#include <bits/stdc++.h>

using namespace std;
int bolen(int x){
	int a=x;
	int cvp=1;
	for(int i=2;i<=x;i++){
		int s=0;
		while(x%i==0){
			s++;
			x=x/i;
		}
		cvp=cvp*(s+1);
	}
	return cvp;
}
int main(){
	int sayi=2;
	while(bolen((sayi*(sayi+1))/2)<500){
		sayi++;
	}
	cout<<(sayi*(sayi+1))/2;
}
