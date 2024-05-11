#include <bits/stdc++.h>

using namespace std;

set<pair<int,int>>sayi;
int yap[1002];
int main(){
	for(int i=2;i<=100;i++){
		int a=1;
		int s=i;
		while(s<=100){
			if(yap[s]==0){
				for(int j=2;j<=100;j++){
					auto pa = make_pair(i,a*j);
					sayi.insert(pa);
				}
			}
			yap[s]=1;
			s=s*i;
			a++;
		}
	}
	cout<<sayi.size();
}
