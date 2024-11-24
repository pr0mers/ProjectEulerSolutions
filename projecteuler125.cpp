#include <bits/stdc++.h>

using namespace std;

vector<long long int>prefix;
unordered_set<long long int>prefset;
bool is_palindrome(long long int n){
	long long int say=0;
	long long int tmp=n;
	while(tmp!=0){
		say=say*10+tmp%10;
		tmp/=10;
	}
	return n==say;
}

int main(){
    long long int top=0;
    for(long long int i=0;i<=10000;i++){
        top=top+i*i;
        prefix.push_back(top);
    }
    for(long long int i=0;i<prefix.size();i++){
        for(long long int j=i+1;j<prefix.size();j++){
            if(prefix[j]-prefix[i]>100000000){
                break;
            }
            if(is_palindrome(prefix[j]-prefix[i]) &&  j-i>1){    
                prefset.insert(prefix[j]-prefix[i]);
            }
        }
    }
    long long int ans=0;
    for(auto it : prefset){
        ans+=it;
    }
    cout<<ans;
}