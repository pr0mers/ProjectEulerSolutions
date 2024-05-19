#include <bits/stdc++.h>

using namespace std;

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
vector<int>v;
set<string>sets;
int dene(string x){
	for(int i=0;i<(1<<x.size());i++){
		v.clear();
		sets.clear();
		for(int j=0;j<x.size();j++){
			if((i & (1<<j)) !=0){
				v.push_back(j);
			}		
		}
		int top=0;
		for(int i=0;i<10;i++){
			string kx=x;
			for(int j=0;j<v.size();j++){
				kx[v[j]]=(i+'0');
			}
			if(kx[0]=='0'){
				continue;
			}
			if(asalmi(stoi(kx))==1){
				sets.insert(kx);
			}
		}
		if(sets.size()==8){
			string mn=*sets.begin();
			for(auto i : sets){
				if(i<mn){
					mn=i;
				}
			}
			return	stoi(mn);
		}
	}
	return 0;
}

int main(){
	for(int i=1;;i++){
		if(asalmi(i)==1){
			if(dene(to_string(i))!=0){
				cout<<dene(to_string(i))<<endl;
				return 0;
			}
		}
	}
}
