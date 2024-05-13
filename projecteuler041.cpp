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

int main(){
	for(int i=8;i>=1;i--){ // n cant be 9 because always 3 is divisor.
		string s="";
		
		for(int j=i;j>=1;j--){
			s=s+char(j+'0');
		}
		
		do{
			if(asalmi(stoi(s))==1){
				cout<<s;
				return 0;
			}
		}while(prev_permutation(s.begin(),s.end()));
	}
}
