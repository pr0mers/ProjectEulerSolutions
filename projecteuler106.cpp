#include <bits/stdc++.h>

using namespace std;
int dizi[100];
int metatesting(int n){
    int ans=0;
    int siz=n;
    int twosiz=1<<siz;
    for(int i=1;i<twosiz;i++){
        vector<pair<int,int>>tmponenums={};
        for(int j=0;j<siz;j++){
            if((i & (1<<j)) != 0){
                tmponenums.push_back(make_pair(j,1));
            }
        }        
        if(tmponenums.size()>siz/2){
            continue;
        }
        for(int k=i+1;k<twosiz;k++){
            vector<pair<int,int>>onenums=tmponenums;
            if ((i & k)!=0) {
                continue;
            }
            for (int l=0;l<siz;l++) {
                if((k & (1<<l)) != 0){
                    onenums.push_back(make_pair(l,-1));
                }
            }
            if(onenums.size()!=tmponenums.size()*2){
                continue;
            }
            sort(onenums.begin(),onenums.end());
            int frst=onenums[0].second;
            int sam=frst;
            for(int it=1;it<onenums.size();it++){
                sam=sam+onenums[it].second;
                if(sam*frst==-1){
                    dizi[tmponenums.size()]++;
                    ans++;
                    break;
                }
            }
        } 
    }
    return ans;
}
/*
-----FOR MATH FORMULATION SOLVING----

unsigned long long combination(int n, int k) {
    if (k > n || k < 0){
        return 0;
    }
    k=(n-k>k)?k:n-k;
    unsigned long long ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

*/
int main(){
    cout<<metatesting(12)<<endl;

    /*



        ANOTHER WAY TO SOLVE AS MATH FORMULA :
        ########################################################################
        #                                                                      #
        #  int n=12;                                                           #
        #  int summation=0;                                                    #
        #  for(int i=2;i<=n/2;i++){                                            #
        #      summation=summation+combination(2*i-1,i-2)*combination(n,2*i);  #
        #  }                                                                   #
        #  cout<<summation;                                                    #
        #                                                                      #
        ########################################################################


    */

}