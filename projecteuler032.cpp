#include <bits/stdc++.h>

using namespace std;
set<int>s;

vector<int>v={1,2,3,4,5,6,7,8,9};

int dene(int n,int m){
	int say1=0;
	int say2=0;
	int say3=0;
	int a=1;
	for(int i=0;i<n;i++){
		say1=say1+v[i]*a;
		a=a*10;
	}	
	a=1;
	for(int i=n;i<n+m;i++){
		say2=say2+v[i]*a;
		a=a*10;
	}
	a=1;
	for(int i=n+m;i<9;i++){
		say3=say3+v[i]*a;
		a=a*10;
	}
	if(say1*say2==say3){
		s.insert(say3);
	}
	
}
int yap(){
	for(int i=1;i<5;i++){
		for(int j=1;j<5;j++){
			dene(i,j);
		}
	}
}
int main(){
	do
    {
        yap();
    }
    while (next_permutation(v.begin(), v.end()));
    int top=0;
    for(auto i : s){
    	top=top+i;
	}
	cout<<top;
}

