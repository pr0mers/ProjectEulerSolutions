#include<bits/stdc++.h>

using namespace std;

int main(){
	for(long long int i=287;i<=100000;i=i+2){
		long long int toplam1= (i)*(i+1);
		for(long long int j =1;j<=i;j++){
			long long int toplam2= (j)*(3*j-1);
			
			if(toplam1==toplam2){
				cout<<toplam1/2;
				return 0;
				
			}
		}
	}	
	
}



