#include <bits/stdc++.h>
/*

https://en.wikipedia.org/wiki/Pell%27s_equation

*/
using namespace std;

int xx=0;
int a0,b0,c0;
vector<int>v;
int lla=0;
int sa=0;
string mx="0";
long long int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

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

string bul65(string pay,string bolu,int n){
    // no need to look for gcd because gcd(a*b+1 , b) is always 1
    if(n==0){
        //cout<<bolu<<"/"<<pay;
        return bolu;
    }
    int art=v[n-1];
    pay=stringsum(pay,stringprod(bolu,to_string(art)));
    return bul65(bolu,pay,n-1);
}

int bul64(int n,int pay,int bolu,int car){
    int gc=gcd(bolu,car);
    bolu=bolu/gc;
    car=car/gc;
    int t=0;
    int kok=sqrt(n);
    t=(pay+kok)/bolu;
    pay=pay-t*bolu;
    if(abs(pay)==b0 && bolu==c0 && t==a0){
        return sa;
    }
    sa++;
    if(lla==0){
        b0=abs(pay);
        c0=bolu;
        a0=t;

    }
    v.push_back(t);
    lla=1;
    return bul64(n,abs(pay), n-pay*pay,bolu);
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
int main(){
    int mxd=0;
    for(long long int i=1;i<=1000;i++){
        
        int top=0;
        sa=0;
        lla=0;
        int ix=sqrt(i); 
        
        if(ix*ix==i) continue;

        v.clear();
        v.push_back(ix);
        if(bul64(i, ix,i-ix*ix,1)%2==1){
            int kl=v.size()-1;
            for(int i=1;i<kl;i++){
                v.push_back(v[i]);
            }
        }
        else{
            v.pop_back();
        }
        string sayi=bul65("1",to_string(v[v.size()-1]),v.size()-1);
        string emx=mx;
        mx=(comparestr(mx,sayi)==1)?mx:sayi;
        if(emx!=mx){
            mxd=i;
        }   
    } 
    cout<<mxd;
}
