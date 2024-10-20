#include <bits/stdc++.h>

using namespace std;

vector<int>v;
string mx="1";
pair<int,pair<int,int>>dizi[5]={make_pair(1,make_pair(6,7)), make_pair(2,make_pair(7,8)), make_pair(3,make_pair(8,9)), make_pair(4,make_pair(9,10)), make_pair(5,make_pair(10,6))};
int comparestr(string a,string b){
    if(a.size() != b.size()){
        return (a.size()>b.size())?1:-1;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            return (a[i]>b[i])?1:-1;
        }
    }
    return 0;
}
int main(){
    for(int i=0;i<10;i++){
        v.push_back(i+1);
    }
    do{
        //1,6,7 ; 2,7,8 ; 3,8,9 ; 4,9,10 ; 5,10,6
        int mn=11;
        int mni=0;
        for(int i=0;i<5;i++){
            if(mn>v[i]){
                mn=v[i];
                mni=i;
            }
        }
        int t=0;
        string dene="";
        int on=0;
        int bo=0;
        int top=0;
        for(int i=mni;t<5;i++){
            i=i%5;
            dene+=to_string(v[dizi[i].first-1]);
            if(v[dizi[i].first-1] == 10) on++;
            dene+=to_string(v[dizi[i].second.first-1]);
            if(v[dizi[i].second.first-1] == 10) on++;
            dene+=to_string(v[dizi[i].second.second-1]);
            if(v[dizi[i].second.second-1] == 10) on++;
            if(top==0){
                top=top+v[dizi[i].second.second-1]+v[dizi[i].second.first-1]+v[dizi[i].first-1];
            }
            else if(top!=v[dizi[i].second.second-1]+v[dizi[i].second.first-1]+v[dizi[i].first-1]){
                bo=1;
                break;
            }
            t++;
            
        }
        if(on == 1 && bo!=1){
            if(comparestr(dene,mx)==1){
                mx=dene;
            }
        }
        

    }while(next_permutation(v.begin(),v.end()));
    cout<<mx<<endl;
}