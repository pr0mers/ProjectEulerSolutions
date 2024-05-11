#include <bits/stdc++.h>

using namespace std;

int ebob(int sayi1, int sayi2) {
    if (sayi2 == 0) {
        return sayi1;
    }
    
    return ebob(sayi2, sayi1 % sayi2);
    
}
int ust=1;
int alt=1;
int dene(int n, int m){
	int a=n;
	int b=m;
	int v=0;
	if(n%10 == m/10%10){
		n=(n-n%10)/10;
		m=m-(m/10%10)*10;
		v=1;
	}
	if(m%10 == n/10%10){
		m=(m-m%10)/10;
		n=n-(n/10%10)*10;
		v=1;
	}
	if(v==0){
		return 0;
	}
	if(n/ebob(n,m) == a/ebob(a,b) && m/ebob(n,m)==b/ebob(a,b)){
		ust=ust*a;
		alt=alt*b;
	}
}

int main(){
	for(int i=10;i<100;i++){
		for(int j=10;j<i;j++){
			dene(j,i);
		}
	}
	cout<<alt/ebob(alt,ust);
}
