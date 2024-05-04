#include <bits/stdc++.h>

using namespace std;
vector<long long int>asallar;
long long int dp[50005][250];
int asalmi(int x){
	if(x==1 || x==0){
		return 0;
	}
	if(x==2){
		return 1;
	}
	for(int i =2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
long long int dene(long long int kalanasallar,long long int suan){
	if(kalanasallar <0){
		return 0;
	}
	if(dp[kalanasallar][suan] !=0){
		return dp[kalanasallar][suan];
	}

	if(kalanasallar ==0){
		return 1;
	}
	for(long long int i =0;i<asallar.size();i++){
		if(asallar[i]>asallar[suan]){
			break;
		}
		long long int a = dene(kalanasallar-asallar[i],i);
		dp[kalanasallar][suan]+=a;
		
	}
	return dp[kalanasallar][suan];
}	

int main(){
	for(int i=1;i;i++)
	{	
		if(asalmi(i)==1){
			asallar.push_back(i);
		}
		if(dene(i,asallar.size()-1)>5000){
			cout<<i;
			break;
		}
	}
	
}
