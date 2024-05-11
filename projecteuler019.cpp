#include <bits/stdc++.h>

using namespace std;

int dizi[13]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int yil=1901;
	int gun=1;
	int toplam=0;
	while(yil!=2001){
		dizi[1]=28;
		int artik=0;
		if(yil %4 == 0){
			if(yil%100!=0){
				artik=1;
			}
			else if(yil%400==0){
				artik=1;
			}
		}
		if(artik==1){
			dizi[1]=29;
		}
		
		for(int i =0;i<12;i++){
			for(int j=0;j<dizi[i];j++){
				gun++;
				if(gun%7==0 && j==0){
					toplam++;
				}
			}
		}
		
		yil++;
	}
	cout<<toplam;
}
