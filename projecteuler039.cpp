#include <bits/stdc++.h>

using namespace std;

int dene(int n,int p){
	int b=sqrt(n);
	for(int i =1;i*i<=n;i++){
		//i ===> p-2a-b
		int a= (p-i-b)/2;
		if(n%i == 0 && p-2*a-b==i && n/i==p-b){
			//cout<<n<<" "<<p<<" "<<a<<" "<<b<<" "<<p-a-b<<endl;
			return 1;
		}
	}
	return 0;
}

int main(){
	//a , b , p-a-b
	//(p-a-b)^2 - a^2 = b^2 ===> (p-2a-b)(p-b) == b^2
	pair<int,int>mx=make_pair(0,0);
	int p=0;
	for(p=1;p<=1000;p++){
		int t=0;
		for(int i =1;i<p/2;i++){
			t=t+dene(i*i,p);
		}
		t=t/2;
		if(t>mx.first){
			mx.first=t;
			mx.second=p;
		}
	}
	cout<<mx.second;
}
