#include <bits/stdc++.h>
using namespace std;
int dizi[150][150];
int main(){
	for(int i =0;i<100;i++){
		for(int j=0;j<=i;j++){
			cin>>dizi[i][j];
		}
	}
	for(int i=99;i>=0;i--){
		for(int j=0;j<=i;j++){
			dizi[i][j]=dizi[i][j]+max(dizi[i+1][j],dizi[i+1][j+1]);
		}
	}
	cout<<dizi[0][0];
}
