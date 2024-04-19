#include <bits/stdc++.h>

using namespace std;

bool palindrom(int sayi){
	queue<int>q;
	stack<int>s;
	while (sayi!=0){
		int sonbas=sayi%10;
		q.push(sonbas);
		s.push(sonbas);
		sayi=sayi/10;
	}
	while(q.empty()==false && s.empty()==false){
		if(q.front()!=s.top()){
			return false;
		}
		q.pop();
		s.pop();
	}
	return true;
}

int main(){
	int mx=0;
	for(int i=100;i<=999;i++){
		for(int j=i;j<=999;j++){
			if(palindrom(i*j)==true){
				mx=max(mx,i*j);	
			}
		}
	}
	cout<<mx;
}
