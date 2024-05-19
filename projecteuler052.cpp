#include <bits/stdc++.h>

using namespace std;
int dene(int n){
	string x=to_string(n);
	sort(x.begin(),x.end());
	for(int i=2;i<=6;i++){
		string y=to_string(i*n);
		sort(y.begin(),y.end());
		if(y!=x){
			return 0;
		}
	}
	return 1;
	
}

int main(){
	for(int i=1;;i++){
		if(dene(i)==1){
			cout<<i;
			return 0;
		}
	}
}
