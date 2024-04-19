#include <bits/stdc++.h>

using namespace std;
queue<int>fib;
long long int cift;
int main(){
	fib.push(1);
	fib.push(1);
	while(fib.back()<=4000000){
		//cout<<fib.back()<<endl;
		int say=fib.front()+fib.back();
		fib.pop();
		fib.push(say);
		if(say%2==0){
			cift=cift+say;
		}
		
	}
	cout<<cift;
	//while(fib)
	
}
