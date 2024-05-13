#include <bits/stdc++.h>

using namespace std;

int pentagonal(int a){
	//a == 3n^2-n ===> 3n^2-n-a=0 ; x1 = [+1+sqrt(1+12a)]/6, x2= [+1-sqrt(1+12a)]/6
	int x=sqrt(1+12*a);
	if(x*x==1+12*a && ((1+x)%6 ==0 || (1-x)%6==0 && x<1)){
		return 1;
	}
	return 0;
}

int main(){
	int i=4;
	int j=7;
	//cout<<pentagonal(i*i*3-i+3*j*j-j)<<" "<<pentagonal(i*i*3-i-3*j*j+j);
	for(int i=1;;i++){
		for(int j=1;j<i;j++){
			if(pentagonal(i*i*3-i+3*j*j-j)==1 && pentagonal(i*i*3-i-3*j*j+j)==1){
				cout<<(i*i*3-i-3*j*j+j) / 2;
				return 0;
			}
		}
	}
}
