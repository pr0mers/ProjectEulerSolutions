#include <bits/stdc++.h>

using namespace std;

long long int dizi[25][25];


int main(){
	for(int i =4;i<24;i++){
		for(int j=4;j<24;j++){
			cin>>dizi[i][j];
		}	
	}
	long long int mx=0;
	for(int i =4;i<24;i++){
		for(int j=4;j<24;j++){
			mx=max(dizi[i][j]*dizi[i][j+1]*dizi[i][j+2]*dizi[i][j+3],mx);
			mx=max(mx,dizi[i][j]*dizi[i+1][j]*dizi[i+2][j]*dizi[i+3][j]);
			mx=max(dizi[i][j]*dizi[i+1][j+1]*dizi[i+2][j+2]*dizi[i+3][j+3],mx);
			mx=max(mx,dizi[i][j]*dizi[i-1][j+1]*dizi[i-2][j+2]*dizi[i-3][j+3]);
		}	
	}
	cout<<mx;
	
}
