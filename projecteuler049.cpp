#include <bits/stdc++.h>

using namespace std;
vector<int>asal;
int dizi[100005];
long long int asalmi(long long int x){
	if(x==1 || x==0){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(long long int i =0;asal[i]*asal[i]<=x;i++){
		if(x%asal[i]==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	for(int i=1;i<10000;i++){
		if(asalmi(i)==1){
			asal.push_back(i);
			dizi[i]=1;
		}
	}
	for(int i=1000;i<10000;i++){
		for(int j=1;i+2*j<10000;j++){
			if(dizi[i]==1 && dizi[i+j]==1 && dizi[i+2*j]==1){
				//cout<<i<<" "<<i+j<<" "<<i+2*j<<" "<<j<<endl;
				string a=to_string(i+2*j);
				string b=to_string(i+j);
				string c=to_string(i);
				sort(a.begin(),a.end());
				sort(b.begin(),b.end());
				sort(c.begin(),c.end());
				
				if(a==b && b==c){
					cout<<i<<i+j<<i+2*j<<endl;
				}
			}
		}
	}
	
}
