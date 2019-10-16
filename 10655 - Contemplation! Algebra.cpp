#include <bits/stdc++.h>

using namespace std;

#define MAXN 2

typedef long long ll;

struct Matrix{
    ll mat[MAXN][MAXN];
};

Matrix matMult(Matrix a, Matrix b){
    Matrix ans; int i,j,k;
    for(i=0; i<MAXN; i++){
        for(j=0; j<MAXN; j++){
            for(ans.mat[i][j]=k=0; k<MAXN; k++){
                ans.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return ans;
}



Matrix matPow(Matrix base, ll p){
    if(p==1) return base;
    Matrix ans; int i,j,k;
    for(i=0; i<MAXN; i++) for(j=0; j<MAXN; j++) ans.mat[i][j]=(i==j);

    while(p){
        if(p&1) ans=matMult(ans, base);
        base=matMult(base,base);
        p>>=1;
    }
    return ans;
}

int main(){
    ll p,q,n;
    string line;
    //freopen("contemplation.txt","r", stdin);
    while(getline(cin,line)){
        stringstream ss(line);
        vector<int> numbers;
        while(ss>>p){
            numbers.push_back(p);
        }
        if(numbers.size()!=3) break;
        p=numbers[0]; q=numbers[1]; n=numbers[2];

        Matrix base; base.mat[0][0]=p; base.mat[0][1]=-q; base.mat[1][0]=1; base.mat[1][1]=0;
        Matrix m1 = matPow(base, n);
        Matrix m2; m2.mat[0][0]=p; m2.mat[0][1]=0; m2.mat[1][0]=2; m2.mat[1][1]=0;
        //printMat(m1);
        //printMat(m2);
        Matrix ans = matMult(m1,m2);
        //printMat(ans);
        cout<<ans.mat[1][0]<<endl;
    }
    return 0;
}
