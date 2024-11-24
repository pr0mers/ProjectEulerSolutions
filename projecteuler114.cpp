/*

For Mathematical Formula :
    https://oeis.org/A005252

*/

#include <bits/stdc++.h>

using namespace std;

long long int N=50;
long long int allarr[55];
long long int all(long long int ind,long long int redrem,char c){
    if(ind==0){
        if(redrem<3 && redrem!=0){
            return 0;
        }
        return 1;
    }
    if(allarr[ind]!=0&&c=='g'){
        return allarr[ind];
    }
    long long int top=0;  
    top+=all(ind-1,redrem+1,'r');
    if(redrem>=3 || c=='g'){
        top+=all(ind-1,0,'g');
    }
    if(c=='g'){
        allarr[ind]=top;
    }
    return top;
}


int main(){
    cout<<all(N,0,'g');
    /*
    
    ############################################
    #                                           #
    #       Mathematical Formula Solution       #
    #                                           #
    #  vector<int>pattern={0,1,1,0,-1,-1};      #
    #  long long int a=1;                       #
    #  long long int b=1;                       #
    #  long long int n=3;                       #
    #  long long int c=a+b+pattern[(n-3)%6];    #
    #  while(n!=50){                            #
    #      n++;                                 #
    #      a=b;                                 #
    #      b=c;                                 #
    #      c=a+b+pattern[(n-3)%6];              #
    #  }                                        #
    #  cout<<c;                                 #
    #                                           #
    #############################################
    */
}