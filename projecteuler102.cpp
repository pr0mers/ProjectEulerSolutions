#include <bits/stdc++.h>

using namespace std;

int main(){
	int cvp=0;
	for(int i =0;i<1000;i++){
	
		float x1,x2,x3,y1,y2,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		
		float egim1=(y1-y2)/(x1-x2);
		float sabit1=(y1-x1*egim1)*-1;
		
		float egim2=(y2-y3)/(x2-x3);
		float sabit2=(y2-x2*egim2)*-1;
		
		float egim3=(y3-y1)/(x3-x1);
		float sabit3=(y3-x3*egim3)*-1;
		//cout<<sabit1<<" "<<sabit2<<" "<<sabit3;
		if(((sabit1<=0 && y3-x3*egim1+sabit1<=0) || (sabit1>=0 && y3-x3*egim1+sabit1>=0)) && ((sabit2<=0 && y1-x1*egim2+sabit2<=0) || (sabit2>=0 && y1-x1*egim2+sabit2>=0)) && ((sabit3<=0 && y2-x2*egim3+sabit3<=0) || (sabit3>=0 && y2-x2*egim3+sabit3>=0))){
			cvp++;
			cout<<"yessir";	
		}
	}
	cout<<endl<<cvp;
}
