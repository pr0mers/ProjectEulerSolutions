#include <bits/stdc++.h>

using namespace std;
string birler[21] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string onlar[11] = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
int main(){
	int toplam=0;
	for(int i=1;i<=19;i++){
		toplam=toplam+birler[i].size();
	}
	for(int i=20;i<=99;i++){
		toplam=toplam+onlar[i/10].size()+birler[i%10].size();
	}
	for(int i=100;i<=999;i++){
		if(i%100 < 20){
			toplam=toplam+birler[i/100].size()+10+onlar[i/10 % 10].size()+birler[i%100].size();
		}
		else{
			toplam=toplam+birler[i/100].size()+10+onlar[i/10 % 10].size()+birler[i%10].size();
		}
		if(i%100==0){
			toplam=toplam-3;
		}
	}
	toplam=toplam+11;
	cout<<toplam;
}
