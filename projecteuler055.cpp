#include <bits/stdc++.h>

using namespace std;

bool palindrome(long long int x){
	stack<long long int>s;
	queue<long long int>q;
	while(x!=0){
		long long int bas=x%10;
		s.push(bas);
		q.push(bas);
		x/=10;
	}
	while(q.front()==s.top()){
		s.pop();
		q.pop();
		if(s.empty()==true){
			return true;
		}
	}

	return false;
}

long long int rev(long long int x){
	long long int aa=x;
	long long int say=x;
	long long int bas=0;
	while(say!=0){
		bas++;
		say/=10;
	}
	say=0;
	long long int a=0;
	while(x!=0){
		a++;
		say+=pow(10,bas-a)*(x%10);
		x=x/10;
	}
	return say;
}

int main(){
	long long int t=0;
	for(long long int i=1;i<10000;i++){
		long long int say=i;
		for(long long int j=0;j<50;j++){
			say=say+rev(say);
			if(palindrome(say)==true){
				t++;
				break;
			}
		}
	}
	cout<<9999-t;
}
