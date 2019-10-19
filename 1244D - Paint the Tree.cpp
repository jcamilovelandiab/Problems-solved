#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<vll> graph(MAXN), paint(3);
vi indegree, color;

int N;

ll dfs(int u, int previousC, int currentC){
    color[u]=currentC;
    ll ans = paint[currentC][u];
    for(int j=0; j<graph[u].size(); j++){
        int v=graph[u][j];
        if(color[v]==-1){
            for(int nextColor=0; nextColor<3; nextColor++){
                if(nextColor!=currentC && nextColor!=previousC){
                    ans+=dfs(v, currentC, nextColor);
                    break;
                }
            }
        }
    }
    return ans;
}

void printPath(vector<int> path){
    cout<<path[0]+1;
    for(int i=1; i<path.size(); i++) cout<<" "<<path[i]+1;
    cout<<endl;
}

int main(){
    cin>>N;
    indegree.assign(N+1, 0);
    for(int i=0; i<3; i++){
        paint[i].clear();
        int value;
        for(int j=0; j<N; j++){
            cin>>value; paint[i].push_back(value);
        }
    }
    bool canPaint = true;
    for(int i=0; i<N-1; i++){
        int x,y; cin>>x>>y; x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        indegree[x]++; indegree[y]++;
        if(indegree[x]>=3 || indegree[y]>=3) canPaint=false;
    }

    if(!canPaint){
        cout<<-1<<endl;
    }else{

        int x,y,z;
        for(int i=0; i<N; i++){
            if(indegree[i]==1){
                x=i; y=graph[x][0];
                z=(graph[y][0]!=x)?graph[y][0]:graph[y][1];
                break;
            }
        }

        ll answer=LLONG_MAX; vi bestPath;
        for(int colorA=0; colorA<3; colorA++){
            for(int colorB=0; colorB<3; colorB++){
                if(colorA==colorB) continue;
                for(int colorC=0; colorC<3; colorC++){
                    if(colorC==colorA || colorC==colorB) continue;
                    color.assign(N,-1);
                    color[x]=colorA; color[y]=colorB; color[z]=colorC;
                    ll result = paint[colorA][x]+paint[colorB][y]+dfs(z, colorB, colorC);
                    if(result<answer){
                        bestPath = color;
                        answer = result;
                    }
                }
            }
        }
        cout<<answer<<endl;
        printPath(bestPath);
    }

    return 0;
}
