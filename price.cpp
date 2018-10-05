#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

typedef long long large;

large dp[310][310];

large f(int n, int coin){
    if(n==0) return 1;
    if(n<0) return 0;
    if(coin<1) return 0;
    if(dp[n][coin]!=0) return dp[n][coin];
    else{
        dp[n][coin]=f(n, coin-1)+f(n-coin, coin);
        return dp[n][coin];
    }
}

int main(){
    string line;
    int lista[3];
    memset(dp, 0, sizeof dp);
    FOR(x, 305) dp[0][x]=1;
    while(getline(cin,line), line!=""){
        stringstream ss(line);
        int i=0;
        while(ss>>lista[i]){ i++; };
        int n=lista[0];
        if(i==1){
            cout<<f(n,n)<<endl;
        }else if(i==2){
            int a=lista[1];
            cout<<f(n,a)<<endl;
        }else{
            int a=lista[1], b=lista[2];
            if(n==0 && a==0 && (b==0 || b==1)) cout<<1<<endl;
            else cout<<f(n, min(b,n))-f(n, min(n,a-1))<<endl;
        }
    }
    return 0;
}
