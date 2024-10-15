#include <bits/stdc++.h>

using namespace std;

string stringsum(string sayi1, string sayi2) {
    int uzunluk1 = sayi1.size();
    int uzunluk2 = sayi2.size();
    int uzunluk = (uzunluk1 > uzunluk2) ? uzunluk1 : uzunluk2;

    int artan = 0;
    string toplam = "";

    for (int i = 0; i < uzunluk; ++i) {
        int basamak1 = (i < uzunluk1) ? sayi1[uzunluk1 - 1 - i] - '0' : 0;
        int basamak2 = (i < uzunluk2) ? sayi2[uzunluk2 - 1 - i] - '0' : 0;

        int basamak = basamak1 + basamak2 + artan;
        artan = basamak / 10;
        basamak %= 10;

        toplam = to_string(basamak) + toplam;
    }

    if (artan != 0) {
        toplam = to_string(artan) + toplam;
    }

    return toplam;
}
string stringprod(string sayi1, string sayi2) {
	int uzunluk1=sayi1.size();
	int uzunluk2=sayi2.size();
	
	vector<int>v(uzunluk1+uzunluk2,0);
	
    for(int i=0;i<uzunluk1;i++){
		int basamak1=sayi1[uzunluk1-i-1]-'0';
		for(int j=0;j<uzunluk2;j++){
			int basamak2=sayi2[uzunluk2-j-1]-'0';
			v[i+j]=v[i+j]+basamak1*basamak2;
		}
	}

	for(int i=0;i<v.size();i++){
		if(v[i]>=10){
			v[i+1]=v[i+1] + v[i]/10;
			v[i]=v[i]%10;
		}
	}
	string top;
	bool bitti=false;
	for(int i=v.size()-1;i>=0;i--){
		if (v[i] != 0) {
			bitti=true; 
            
        }
		if(bitti==true){
			top += (v[i] + '0');
		}
	}
	return top;
}
string power(string a, int b){
	if(b==0){
		return "1";
	}
	if(b==1){
		return a;
	}
	string say=power(a,b/2);
	if(b%2==1){
		return stringprod(stringprod(say,say),a);
	}
	else{
		return stringprod(say,say);
	}
}
int bul(string n){
	int toplam=0;
	for(int i=0;i<n.size();i++){
		toplam=toplam+n[i]-'0';
	}
	return toplam;
}
string uzeri(int a,int b){
	string astr=to_string(a);
	string top="1";
	for(int i=0;i<b;i++){
		top=stringprod(astr,top);
	}
	return top;
}
int main(){
	int mx=0;
	for(int i=1;i<100;i++){
		for(int j=1;j<100;j++){
			mx=max(mx,bul(power(to_string(i),j)));
		}
	} 
	cout<<mx; 
}
