#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>vec;

int top=0;

void komb(vector<int>v, vector<int>vi, int ind, int uzunluk) {
    if (vi.size() == uzunluk) {
        vec.push_back(vi);
        return;
    }

    for (int i = ind; i < v.size(); i++) {
        vi.push_back(v[i]);
        komb(v, vi, i + 1, uzunluk);
        vi.pop_back();
    }
}
int klas=0;
void oluyomu(vector<int>v,vector<int>vi){
    int diziv[10]={};
    int dizivi[10]={};
    for(int i=0;i<vi.size();i++){
        diziv[v[i]]=1;
        if(v[i]==6 || v[i]==9){
            diziv[9]=1;
            diziv[6]=1;
        }
        dizivi[vi[i]]=1;
        if(vi[i]==6 || vi[i]==9){
            dizivi[9]=1;
            dizivi[6]=1;
        }
    }
    // 01,04,09,16,25,36,49,64,81
    int kare[9][2] = {
        {0, 1}, {0, 4}, {0, 9},
        {1, 6}, {2, 5}, {3, 6},
        {4, 9}, {4, 6}, {1, 8}
    };
    int xls=1;
    for(int i=0;i<9;i++){
        int a=kare[i][0];
        int b=kare[i][1];
        if (!((diziv[a] == 1 && dizivi[b] == 1) || (diziv[b] == 1 && dizivi[a] == 1))) {
            xls=0;
            break;
        }
    }
    top=top+xls;
    return;
}

int main() {
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int uz = 6;
    vector<int> vi;
    komb(v, vi, 0, uz);
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            int a=top;
            oluyomu(vec[i],vec[j]);
        }
    }
    cout<<top;
    return 0;
}
