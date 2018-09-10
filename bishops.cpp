#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define x first
#define y second

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,k, cnt;
vii alfiles;

bool check(int i, int j){
    FOR(k,alfiles.size()){
        int x = alfiles[k].x, y=alfiles[k].y;
        if(abs(x-i)==abs(y-j)) return false;
    }
    return true;
}

void backtrack(int i, int j){
    if(alfiles.size()==k){
        cnt++; return;
    }
    if(i==n) return;
    int x=i, y=j+1;
    if(y>=n){
        x++; y=0;
    }
    if(check(i,j)){
        alfiles.push_back(ii(i,j));
        backtrack(x,y);
        alfiles.pop_back();
    }
    backtrack(x,y);
}

int main(){
    while(cin>>n>>k, n){
        cnt=0; alfiles.clear();
        backtrack(0,0);
        cout<<cnt<<endl;
    }
    return 0;
}
