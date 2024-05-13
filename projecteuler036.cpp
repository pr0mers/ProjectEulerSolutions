#include <bits/stdc++.h>

using namespace std;

string baseiki(int x){
	string s="";
	while(x!=0){
		s=s+char((x%2)+'0');
		x=x/2;
	}
	return s;
}
bool palindrome(string x){
	string y=x;
	reverse(x.begin(),x.end());
	return (x==y)? true : false;
}
int main(){
	int topl=0;
	for(int i=1;i<1000000;i++){
		if(palindrome(baseiki(i))==true && palindrome(to_string(i))){
			topl=topl+i;
		}
	}
	cout<<topl;
}
