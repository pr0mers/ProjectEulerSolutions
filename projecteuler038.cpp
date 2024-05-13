#include <bits/stdc++.h>

using namespace std;

int pandigital(string s){
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=char(i+'0'+1)){
			return 0;
		}
	}
	return 1;
}

int main(){
	int mx=0;
	for(int i=1;i<100000;i++){ // it cant be more than 5 digit
		string s="";
		int a=1;
		while(s.size()!=9){
			if(s.size()>9){
				break;
			}
			s=s+to_string(a*i);
			a++;
			if(s.size()==9 && pandigital(s)==1){
				mx=max(mx,stoi(s));
			}
		}
	}
	cout<<mx;
}
