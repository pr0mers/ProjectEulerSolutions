#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int say=600851475143;
	int a=1;
	while(a<=say){
		a++;
		while(say%a==0){
			say=say/a;
		}
	}
	cout<<a;
}
