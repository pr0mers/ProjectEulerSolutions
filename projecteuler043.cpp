#include <bits/stdc++.h>

using namespace std;
string s="0123456789";
int main(){
	long long int top=0;
	do{
		long long int a=top;
		
		top+=(stoll(s.substr(1,3)) % 2 == 0 && stoll(s.substr(2,3)) % 3 == 0 && stoll(s.substr(3,3)) % 5 == 0 && stoll(s.substr(4,3)) % 7 == 0 && stoll(s.substr(5,3)) % 11 == 0 && stoll(s.substr(6,3)) % 13 == 0 && stoll(s.substr(7,3)) % 17 == 0 )?stoll(s):0;
	}while(next_permutation(s.begin(),s.end()));
	cout<<top;
}
