#include <bits/stdc++.h>

using namespace std;
vector<long long int>asal;
vector<long long int>topl;
//long long int dizi[100000005];
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
	long long int top=0;
	topl.push_back(0);
	for(long long int i=1;i<1000000;i++){
		if(asalmi(i)==1){
			asal.push_back(i);
			//dizi[i]=1;
			top=top+i;
			topl.push_back(top);
		}
	}
	pair<long long int,long long int>mx=make_pair(0,0);
	for(long long int i=0;i<topl.size();i++){
		for(long long int j=i;j<topl.size() && topl[j]-topl[i]<=1000000;j++){
			if(asalmi(topl[j]-topl[i])==1){
				if(j-i > mx.second){
					mx.first=topl[j]-topl[i];
					mx.second=j-i;
				}
			}
		}
	}
	cout<<mx.first;
	
}
