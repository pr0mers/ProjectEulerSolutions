#include <bits/stdc++.h>

using namespace std;
int dizi[30000];
int abundant[30000];
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
	int n=0;
	for(int i=1;i<=28123;i++){
		int yazdim=0;
		if(bolentop(i)>i){
			dizi[i]=1;
			abundant[n]=i;
			n++;
		}
		for(int j=0;j<n;j++){
			if(dizi[i-abundant[j]]==1){
				yazdim=1;
				break;
			}
		}
		if(yazdim==0){
			//cout<<i<<endl;
			toplam=toplam+i;
		}
	}
	cout<<toplam;
}
