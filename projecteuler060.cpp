#include <bits/stdc++.h>

using namespace std;

vector<int>prime;
vector<int>v[10005];

int N=5;

int mn=10000000;
int bul(vector<int>vp,int n){
    if(vp.size()==n){
        int t=0;
        for(auto it : vp){
            t+=it;
        }
        return t;
    }
    for(int i=0;i<v[vp.back()].size();i++){
        int olma=0;
        for(int j=0;j<vp.size();j++){ 
            if(binary_search(v[vp[j]].begin(),v[vp[j]].end(),v[vp.back()][i])==false){
                olma=1;
            }
        }
        if(olma ==0){
            vector<int>nvp=vp;
            nvp.push_back(v[vp.back()][i]);
            mn=min(mn,bul(nvp,n));
        }
    }
    return mn;
}

bool is_prime(int x){
	if(x<=1){
		return false;
	}
	int say=sqrt(x);
	for(int i=2;i<=say;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    prime.push_back(2);
    prime.push_back(3);
    for(int i=4;i<10000;i++){
        if(is_prime(i) == true){
            prime.push_back(i);
        }
    }
    for(int i=0;i<prime.size();i++){
        for(int j=i+1;j<prime.size();j++){
            int s1=prime[i];
            int s2=prime[j];
            int bas1=0;
            int bas2=0;
            while(s1!=0){
                s1=s1/10;
                bas1++;
            }
            while(s2!=0){
                s2=s2/10;
                bas2++;
            }
            int x1=prime[i]*pow(10,bas2)+prime[j];
            int x2=prime[j]*pow(10,bas1)+prime[i];

            if(is_prime(x1)==true && is_prime(x2)==true){
                v[prime[i]].push_back(prime[j]);
            }
        }
    }
    int mn=0;
    for(int i=0;i<prime.size();i++){
        vector<int>vi={};
        vi.push_back(prime[i]);
        mn=bul(vi,N);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout<<mn<<" "<<elapsed.count()<<endl;
}  
