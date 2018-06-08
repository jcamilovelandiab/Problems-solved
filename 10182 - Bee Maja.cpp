#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int  i=a; i<b; i++)
#define MAXN 100001

using namespace std;

typedef pair<int,int> ii;

vector<ii> coord(100001);

void makeCoordSystem(){
    int n=1; coord[n]=ii(0,0);
    int level=1;
    while(n<MAXN){
        FOR(i,level+1) if(n<MAXN) coord[++n]=ii(-i,level);
        FOR(i,level)   if(n<MAXN) coord[++n]=ii(-level, level-i-1);
        FOR(i,level)   if(n<MAXN) coord[++n]=ii(-level+i+1, -i-1);
        FOR(i,level)   if(n<MAXN) coord[++n]=ii(i+1, -level);
        FOR(i,level+1) if(n<MAXN) coord[++n]=ii(level,-level+i+1);
        FOR(i,level-1) if(n<MAXN) coord[++n]=ii(level-i-1, i+2);
        level++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    makeCoordSystem();
    int n;
    while(cin>>n){
        cout<<coord[n].fi<<" "<<coord[n].se<<endl;
    }
    return 0;
}
