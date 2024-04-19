#include <bits/stdc++.h>

using namespace std;

int main(){
	int n=100;
	long long int x=n*(n+1)*(2*n+1)/6;
	long long int y=(n*(n+1)/2)*(n*(n+1)/2);
	cout<<y-x;
}
