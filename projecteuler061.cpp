#include <bits/stdc++.h>

using namespace std;
vector<int>v[100][10];
void dene(int x,int olanlar[]){
    int top=0;
    int t=0;
    for(int i=1;i<=6;i++){
        if(olanlar[i]!=0){
            top++;
            t=t+olanlar[i];
        }
    }
    
    if(top==5){
        int sif=-1;
        for(int i=1;i<=6;i++){
            if(olanlar[i]==0){
                sif=i;
            }
        }
        for(int j=0;j<v[x%100][sif].size();j++){
                if(v[x%100][sif][j]==olanlar[1]/100){
                    cout<<t+x%100 * 100+v[x%100][sif][j]<<endl;
                }
            }
            
        
    }
    for(int i=1;i<=6;i++){
        for(int j=0;j<v[x%100][i].size()&&olanlar[i]==0;j++){
            int nolanlar[]={0,0,0,0,0,0,0};
            for(int ji=1;ji<=6;ji++){
                nolanlar[ji]=olanlar[ji];
            }
            nolanlar[i]=x%100 * 100+v[x%100][i][j];
            dene(x%100 * 100+v[x%100][i][j],nolanlar);
        }
    }
}
int main(){
    int i=1;
    while(i*(i+1)/2 <10000){
        if(i*(i+1)/2 <10000 && i*(i+1)/2 >=1000){
            v[(i*(i+1)/2)/100][1].push_back((i*(i+1)/2)%100);
        }
        if(i*i <10000 && i*i >=1000){
            v[i*i/100][2].push_back((i*i)%100);
        }
        if(i*(3*i-1)/2 <10000 && i*(3*i-1)/2 >=1000){
            v[(i*(3*i-1)/2)/100][3].push_back((i*(3*i-1)/2)%100);
        }
        if(i*(2*i-1) <10000 && i*(2*i-1) >=1000){
            v[(i*(2*i-1))/100][4].push_back((i*(2*i-1))%100);
        }
        if(i*(5*i-3)/2 <10000 && i*(5*i-3)/2 >=1000){
            v[(i*(5*i-3)/2)/100][5].push_back((i*(5*i-3)/2)%100);
        }
        if(i*(3*i-2) <10000 && i*(3*i-2) >=1000){
            v[(i*(3*i-2))/100][6].push_back((i*(3*i-2))%100);
        }  
       i++;
    }
    for(int i=45;(i*(i+1)/2)<10000;i++){
        int olanlar[]={0,(i)*(i+1)/2,0,0,0,0,0};
        dene((i)*(i+1)/2,olanlar);
    }
}