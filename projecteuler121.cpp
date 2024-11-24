#include <bits/stdc++.h>

using namespace std;

vector<long long int>rakamlar={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
long long int yap(long long int x,long long int ind,long long int carpim){
    if(x==0){
        //cout<<carpim<<endl;
        return carpim;
    }
    long long int toplams=0;
    for(long long int i=ind+1;i<rakamlar.size();i++){
        toplams+=yap(x-1,i,carpim*rakamlar[i]);
    }
    return toplams;

}
int main(){
    //yap(2,-1,1);
    long long int toplam=0;
    for(long long int i=0;i<(rakamlar.size()+1)/2;i++){
        toplam+=yap(i,-1,1);
    }
    cout<<floor(20922789888000.0/toplam);
}