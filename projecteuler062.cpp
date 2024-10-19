#include <bits/stdc++.h>

using namespace std;

int dizi[10];
int dizi2[10];
bool permut(long long int a,long long int b){
    for(int i=0;i<10;i++){
        dizi[i]=0;
        dizi2[i]=0;
    }
    while(a!=0){
        dizi[a%10]++;
        a=a/10;
    }
    while(b!=0){
        dizi2[b%10]++;
        b=b/10;
    }
    for(int i=0;i<10;i++){
        if(dizi[i]!=dizi2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    
    for(long long int i =1;;i++){
        int t=0;
        long long int mn=0;
        for(long long int j =1;j<i;j++){
            if(permut(i*i*i,j*j*j)==true){
                t++;
                mn=(mn==0)?j:mn;
            }
        }
        if(t==4){
            cout<<mn*mn*mn;
            return 0;
        }
    }
}
