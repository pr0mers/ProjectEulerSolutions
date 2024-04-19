#include <bits/stdc++.h>

using namespace std;

int main(){
	double s=1;
	for(int i=40;i>=21;i--){
		s=s*i/(i-20);
	}
	printf("%0f",s);	
}
