
//Dear programmer:
//When I wrote this code, only god and
//I knew how it worked.
//Now, only god knows it!
//
//Therefore, if you are trying to optimize
//this routine and it fails (most surely),
//please increase this counter as a
//warning for the next person:
//
// total_hours_wasted_here = 2.5;
//

#include <bits/stdc++.h>
using namespace std;

string str="123456789";
int elemansayisi[20];
int dizi[10];
int fak[10]={1,2,6,24,120,720,5040,40320,362880};
int asalmi(int x){
	if(x==1 || x==0){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(int i =2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int yap(string s){
	int uz=str.size();
	for(int i =0;i<(1<<uz-1);i++){
		int elsay=0;
		int asaldi=0;
		int sayim=s[0]-48;
    	for(int j=uz-2;j>=0;j--){
    		if((i&(1<<j)) != 0){
    			elsay++;
    			if(asalmi(sayim)==0){
    				asaldi=1;
				}
    			sayim=s[uz-1-j]-48;
    			
			}
			else{
				sayim=sayim*10+(s[uz-1-j]-48);
			}	
		}
		elsay++;
		if(asalmi(sayim)==0){
    		asaldi=1;
		}
		if(asaldi==0){
	    	elemansayisi[elsay]++;	
		}
	}
}


int main(){
	do
    {
       yap(str);
    }
    while (next_permutation(str.begin(), str.end()));
	int toplam=0;	
    for(int i =1;i<=9;i++){
    	toplam=toplam+elemansayisi[i]/fak[i-1];
    	
	}
	cout<<toplam;
}
