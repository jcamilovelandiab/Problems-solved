/**
    @author JCamiloVB
    Square Matrix Exponentation (Matrix power). Implementation from the book Competitive Programming 3
**/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 2

typedef long long ll;

ll n,m;

struct Matrix{
    ll mat[MAXN][MAXN];
};

Matrix matMul(Matrix a, Matrix b){
    Matrix ans; int i,j,k;
    for(i=0; i<MAXN; i++){
        for(j=0; j<MAXN; j++){
            for(ans.mat[i][j]=k=0; k<MAXN; k++){
                ans.mat[i][j]=(a.mat[i][k]*b.mat[k][j]+ans.mat[i][j])%m;
            }
        }
    }
    return ans;
}

Matrix matPow(Matrix base, ll p){
    if(p==1) return base;
    Matrix ans; int i,j;
    for(i=0; i<MAXN; i++){
        for(j=0; j<MAXN; j++) ans.mat[i][j]=(i==j); //identity matrix
    }
    while(p){
        if(p&1) ans=matMul(ans, base);
        base = matMul(base, base);
        p>>=1;
    }
    return ans;
}

void printMat(Matrix a){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++) cout<<" "<<a.mat[i][j];
        cout<<endl;
    }
}

int main(){
    while(cin>>n>>m){

        if(n==0) cout<<0<<endl;
        else{
            m=1<<m;
            Matrix base; base.mat[0][0]=base.mat[0][1]=base.mat[1][0]=1; base.mat[1][1]=0;
            Matrix ans = matPow(base,n-1);
            //cout<<" M: "<<m<<endl;
            //printMat(ans);
            cout<<ans.mat[0][0]<<endl;
        }
    }
    return 0;
}
