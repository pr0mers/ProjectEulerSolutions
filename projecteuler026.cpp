#include<bits/stdc++.h>

using namespace std;

int kalanlar[1000][1000];

int tekrar(int n){
	kalanlar[n][0]=1;
	int toplam =0;
	int sayi=1;
	while(kalanlar[n][sayi]==0)
	{
		
		kalanlar[n][sayi]=1;
		toplam++;
		while(sayi/n==0){
			sayi=sayi*10;
			toplam++;
		}
		toplam--;
		sayi=sayi%n;
	}
	return toplam;
}


int main(){
	int mx=0;
	int sayis=0;
	//cout<<tekrar(1000);
	for(int i=2;i<=1000;i++){
		//cout<<tekrar(i)<<endl;
		int a=tekrar(i);
		if(a>=mx){
			mx=a;
			sayis=i;
		}
	}
	cout<<sayis;
}
