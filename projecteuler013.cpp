#include <bits/stdc++.h>

using namespace std;
#include <iostream>
#include <string>

string topla(string sayi1, string sayi2) {
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

int main() {
    string toplam;
    string sayi;
	for(int i =0;i<100;i++){
		cin>>sayi;
		toplam=topla(sayi,toplam);
	}
	for(int i =0;i<10;i++){
		cout<<toplam[i];
	}
	

}

