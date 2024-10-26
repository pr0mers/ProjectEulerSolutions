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
int comparestr(string a,string b){
    if(a.size() != b.size()){
        return (a.size()>b.size())?1:-1;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            return (a[i]>b[i])?1:-1;
        }
    }
    return 0;
}
string stringsub(string sayi1, string sayi2) {
    bool neg = false;
    if (comparestr(sayi1,sayi2)==-1) {
        swap(sayi1, sayi2);
        neg = true;
    }

    int uzunluk1 = sayi1.size();
    int uzunluk2 = sayi2.size();
    int uzunluk = uzunluk1;

    int artan = 0;
    string sonuc = "";

    for (int i = 0; i < uzunluk; ++i) {
        int basamak1 = sayi1[uzunluk1 - 1 - i] - '0';
        int basamak2 = (i < uzunluk2) ? (sayi2[uzunluk2 - 1 - i] - '0') : 0;

        int basamak = basamak1 - basamak2 - artan;

        if (basamak < 0) {
            basamak += 10;
            artan = 1;
        } else {
            artan = 0;
        }

        sonuc = to_string(basamak) + sonuc;
    }

    while (sonuc.size() > 1 && sonuc[0] == '0') {
        sonuc.erase(0, 1);
    }

    if (neg) {
        sonuc = "-" + sonuc;
    }

    return sonuc;
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

int main(){
    int i=0;
    int toplam=0;
    for(int i=2;i<=100;i++){
        int c=sqrt(i);
        if(c*c==i){continue;}
        string a=stringprod(to_string(i),"5");
        string b="5";
        int bas=0;
        int t=i;
        while(t!=0){
            bas++;
            t=t/10;
        }
        while(b.size()!=102){
            if(comparestr(a,b)!=-1){
                a=stringsub(a,b);
                b=stringsum(b,"10");
            }
            else{
                a=stringprod(a,"100");
                char c=b[b.size()-1];
                b[b.size()-1]='0';
                b=b+c;
            }
        }
        for(int i=0;i<100;i++){
            toplam=toplam+b[i]-'0';
        }
    }
    cout<<toplam;
}   