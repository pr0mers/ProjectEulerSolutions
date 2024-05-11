#include <bits/stdc++.h>

using namespace std;


int main(){
	int n=1;
	int toplam=1;
	int kez=0;
	int a=2;
	while(n<=1001*1001){
		for(int i =0;i<4;i++){
			if(n+a>1001*1001){
				cout<<toplam;
				return 0;
			}
			toplam=toplam+n+a;
			n=n+a;
		}
		a=a+2;
	}
	cout<<toplam;
}
