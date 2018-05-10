#include <bits/stdc++.h>
#define loop(i,a) for(int i=0; i<a; i++)
#define INF 1e9

using namespace std;
typedef vector<int> vi;

vector<vi>listAdy(210);
vector<int> color(210);

int main(){
    ios::sync_with_stdio(false);
    int n, l, x,y;
    while(cin>>n, n){
        loop(i,n+2) listAdy[i].clear();
        cin>>l;
        while(l--){
            cin>>x>>y;
            listAdy[x].push_back(y);
            listAdy[y].push_back(x);
        }
        int s=0;
        queue<int>q; q.push(s);
        vi color(n+2,INF); color[s]=0;
        bool isBipartite=true;
        while(!q.empty() && isBipartite){
            int u=q.front(); q.pop();
            loop(j,listAdy[u].size()){
                int v=listAdy[u][j];
                if(color[v]==INF){
                    color[v]=1-color[u];
                    q.push(v);
                }else if(color[v]==color[u]){ // ya no es bipartito
                    isBipartite=false; break;
                }
            }
        }
        if(!isBipartite) cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;

    }
    return 0;
}
