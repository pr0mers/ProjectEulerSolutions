#include <bits/stdc++.h>

using namespace std;
long long int para[10] = {1,2,5,10,20,50,100,200};
long long int dp[50005][250];
//long long int cevap =0;
long long int dene(long long int kalanpara,long long int suan){
	if(kalanpara <0){
		return 0;
	}
	
	//cout<<kalanpara<<" "<<suan<<" "<<"("<<dp[kalanpara][suan]<<")"<<"/"<<yollayan<<endl;
	if(dp[kalanpara][suan] !=0){
		//cout<<"hesapli"<<dp[2][1];
		return dp[kalanpara][suan];
	}

	if(kalanpara ==0){
		//cevap++;
		//cout<<"a";
		///cout<<kalanpara<<" "<<suan<<" "<<"("<<dp[kalanpara][suan]<<")"<<"/"<<endl;
		return 1;
	}
	
	
	for(long long int i =0;i<8;i++){
		if(para[i]>suan){
			break;
		}
		//dene(kalanpara-para[i],para[i])
		///cout<<kalanpara<<" "<<suan<<" "<<"("<<dp[kalanpara][suan]<<")"<<"/"<<"dene("<<kalanpara-para[i]<<","<<para[i]<<")"<<endl;
		long long int a = dene(kalanpara-para[i],para[i]);
		dp[kalanpara][suan]+=a;
		
	}
	return dp[kalanpara][suan];
	//return 1;
}	

int main(){
	//cout<<dene(3,3)<<endl;
	long long int x = dene(200,200);
	cout<<dp[200][200]<<"//"<<x<<endl;
	/*for(long long int i=0;i<600;i++){
		for(long long int j=0;j<600;j++){
			if(dp[i][j]!=0){
				cout<<"("<<i<<" "<<j<<")"<<" "<<dp[i][j]<<endl;
			}
		}
	}*/
	
	//cout<<cevap;
}
