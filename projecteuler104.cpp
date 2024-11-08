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
bool pandigital(string x){
    int dizi[100]={0};
    for(int i=0;i<9 && i<x.size();i++){
        dizi[x[i]-'0']++;
        //dizi[x[x.size()-1-i]-'0']+=2;
    }
    for(int i=1;i<=9;i++){
        if(dizi[i]!=1){
            return false;
        }
    }
    return true;
}
string trimle(string c) {
    string ilk=c.substr(0,81);
    string son=c.substr(c.size()-9,9);
    return ilk+son;
    
}
int main(){
    string a="1";
    string b="2";
    string c="3";
    int t=4;
    while(!pandigital(c)){
        a=b;
        b=c;
        c=stringsum(a,b);
        t++;
        if(c.size()>=90){
            c=trimle(c);
        } 
        if(t%10000 ==0){
            cout<<t<<endl;
        } 
    }
    cout<<t<<endl;
    cout<<c;
}