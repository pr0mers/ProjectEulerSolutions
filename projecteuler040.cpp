#include <bits/stdc++.h>

using namespace std;

//my math olympiad experiences really come in handy in project euler ;)

int bul(int n){
	int s=9;
	int bas=1;
	int top=0;
	while(top+s*bas<n){
		top=top+s*bas;
		s=s*10;
		bas=bas+1;
	}
	n=n-top;
	int say=pow(10,bas-1)+(n+bas-1)/bas-1;
	int kalan=(n-1)%bas + 1;
	string sa = to_string(say);
	return (sa[kalan-1]-'0');
}

int main(){
	int carp=1;
	for(int i =0;i<=6;i++){
		carp = carp*bul(pow(10,i));
	}
	cout<<carp;
}
