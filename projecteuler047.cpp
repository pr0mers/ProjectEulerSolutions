#include <bits/stdc++.h>

using namespace std;
vector<int>asal;
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

int dene(int n){
	int bolen=0;
	for(int i =0;i<asal.size();i++){
		int ol=0;
		while(n%asal[i]==0){
			n=n/asal[i];
			ol=1;
		}
		bolen=bolen+ol;
	}
	return bolen;
}

int main(){
	for(int i=1;i;i++)
	{	
		if(asalmi(i)==1){
			asal.push_back(i);
		}
		if(dene(i)==4 && dene(i+1)==4 && dene(i+2)==4 && dene(i+3)==4){
			cout<<i;
			break;
		}
	}
	
}
