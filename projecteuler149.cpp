/*

    Maximum Sum of Subarrays // A.K.A Kadane's Algorithm
    https://en.wikipedia.org/wiki/Maximum_subarray_problem#:~:text=%5B12%5D-,Kadane%27s%20algorithm,-%5Bedit%5D
    
*/
#include <bits/stdc++.h>

using namespace std;
long long int N=2000;
long long int dizi[2005][2005];
long long int horizontal(){
    long long int mx=0;
    for(long long int i=0;i<N;i++){
        long long int crr=0;
        for(long long int j=0;j<N;j++){
            crr=max(dizi[i][j],crr+dizi[i][j]);
            mx=max(mx,crr);
        }
    }
    return mx;
}
long long int vertical(){
    long long int mx=0;
    for(long long int i=0;i<N;i++){
        long long int crr=0;
        for(long long int j=0;j<N;j++){
            crr=max(dizi[j][i],crr+dizi[j][i]);
            mx=max(mx,crr);
        }
    }
    return mx;
}
long long int diagonal(){
    long long int mx=0;
    for(long long int i=0;i<N;i++){
        long long int crr=0;
        for(long long int j=0;j<=i;j++){
            crr=max(dizi[i-j][j],crr+dizi[i-j][j]);
            mx=max(mx,crr);
        }
    }
    for(long long int i=0;i<N-1;i++){
        long long int crr=0;
        for(long long int j=0;j<=i;j++){
            crr=max(dizi[N-i+j-1][N-j-1],crr+dizi[N-i+j-1][N-j-1]);
            mx=max(mx,crr);
        }
    }
    
    return mx;
}
long long int antidiagonal(){
    long long int mx=0;
    for(long long int i=0;i<N;i++){
        long long int crr=0;
        long long int basy=N-1-i;
        long long int basx=0;
        for(long long int j=0;j<=i;j++){
            crr=max(dizi[basy+j][basx+j],crr+dizi[basy+j][basx+j]);
            mx=max(mx,crr);
        }
    }
    for(long long int i=0;i<N-1;i++){
        long long int crr=0;
        long long int basy=0;
        long long int basx=N-i-1;
        for(long long int j=0;j<=i;j++){
            crr=max(dizi[basy+j][basx+j],crr+dizi[basy+j][basx+j]);
            mx=max(mx,crr);
        }
    }
    
    return mx;
}


int main(){
    long long int k=1;
    for(long long int i=0;i<N;i++){
        for(long long int j=0;j<N;j++){
            if(k<=55){
                dizi[i][j]=(100003-200003*k+1ll*300007*k*k*k)%1000000-500000;
            }
            else{
                dizi[i][j]=(dizi[(k-25)/N][(k-25)%N]+dizi[(k-56)/N][(k-56)%N]+1000000)%1000000-500000;
            }
            k++;
        }
    }
    long long int mx=0;
    mx=max(mx,horizontal());
    mx=max(mx,vertical());
    mx=max(mx,diagonal());
    mx=max(mx,antidiagonal());
    cout<<mx;
}