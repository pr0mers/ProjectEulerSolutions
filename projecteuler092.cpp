#include <bits/stdc++.h>

using namespace std;
int dene(int x){
    if(x==1){
        return 0;
    }
    if(x==89){
        return 1;
    }
    int top=0;
    while(x!=0){
        int bas=x%10;
        top=top+(bas * bas);
        x=x/10;
    }
    return dene(top);
}

int main() {
    int top=0;
    for(int i=1;i<10000000;i++){
        top=top+dene(i);
    }
    cout<<top;
}
