#include <bits/stdc++.h>

using namespace std;

int main(){
	string x="0123456789";
	
	for(int i=1;i<1000000;i++){
		next_permutation(x.begin(),x.end());
		
	}
	cout<<x;
}
