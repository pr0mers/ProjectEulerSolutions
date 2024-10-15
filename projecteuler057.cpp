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

int rakam(int x){
    int top=0;
    while(x!=0){
        top++;
        x=x/10;
    }
    return top;
}

int main(){
	string ust="1";
    string alt="1";
    string tmp="1";
    int t=0;
    for(int i=0;i<1000;i++){
        tmp=ust;
        ust=stringsum(ust,stringsum(alt,alt));
        alt=stringsum(tmp,alt); // no need to find HCM because (a+2b,a+b) = (a,b) = (2,3)
        if(ust.size()>alt.size()){
            t++;
        }
    }
    cout<<t;
}
