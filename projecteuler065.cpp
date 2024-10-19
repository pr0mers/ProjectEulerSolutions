#include <bits/stdc++.h>

using namespace std;
int dizi[105];
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

void bul(string pay,string bolu,int n){
    // no need to look for gcd because gcd(a*b+1 , b) is always 1
    if(n==0){
        int top=0;
        for(int i=0;i<bolu.size();i++){
            top=top+bolu[i]-'0';
        }
        cout<<top;
        return;
    }
    int art=dizi[n-1];
    pay=stringsum(pay,stringprod(bolu,to_string(art)));
    bul(bolu,pay,n-1);
}
int main(){
    dizi[0]=2;
    for(int i=1;i<100;i++){
        dizi[i]=(i%3==2)?((i+1)/3*2):1;
    }
    bul("1",to_string(dizi[99]),99);
}
 