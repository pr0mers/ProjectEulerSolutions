#include <bits/stdc++.h>

using namespace std;
int arr[10000005];
int numofdiv(int x){
    int say=2;
    int num=1;
    while(say*say<=x){
        int top=0;
        while(x%say==0){
            top++;
            x/=say;
        }
        say++;
        num=num*(top+1);
    }
    if(x!=1){
        num=num*2;
    }
    return num;
}
int main(){
    /*--------------Faster Solution With Sieve (but i've made second solution first)--------
    for(int i=2;i<=5000000;i++){
        for(int j=i;j<=10000000;j=j+i){
            arr[j]++;
        }
    }
    for(int i=2;i<=10000000;i++){
        if(arr[i]==arr[i-1]){
            ans++;
        }
    }
    */
    int ans=0;
    int previous=1;
    for(int i=2;i<10000000;i++){ // We could use sieve,as shown above, but this gets the job done too.
        int divnum=numofdiv(i);
        if(divnum==previous){
            //cout<<i-1<<" "<<i<<endl;
            ans++;
        }
        previous=divnum;
    }
    cout<<ans;
}