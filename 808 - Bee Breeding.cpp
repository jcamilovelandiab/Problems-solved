#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 10005
#define INF 1e09
#define fi first
#define se second

/*
I did it in two ways, one per bfs and another applying math
time:
math:  0.000
bfs: 1.020
*/

using namespace std;

typedef pair<int,int> ii;

map<int, ii> coord;
//map<ii, int> mapCoord; // do it by bfs

void printN(int n){
    cout<<n<<": "<<coord[n].first<<","<<coord[n].second<<endl;
}

void makeSystemCoord(){
    coord[1]=ii(0,0); //mapCoord[ii(0,0)]=1;
    int beforeXN=1, beforeYP=1;
    loop(i,1,59){
        int n = beforeXN+6*(i-1)+3; // f(n) = f(n-1)+6(n-1)+3 calcula (-X,0)
        coord[n]=ii(-i,0); beforeXN=n;
        //mapCoord[ii(-i,0)]=n;
        FOR(j,i){
            n++; coord[n]=ii(-i, j+1);
            //mapCoord[ii(-i, j+1)]=n;
        }

        n-=i;
        FOR(j,i){
    	    n--; coord[n]=ii(-i+j+1, -j-1);
    	    //mapCoord[ii(-i+j+1, -j-1)]=n;
	    }

	    FOR(j,i){
	        n--; coord[n]=ii(j+1, -i);
	        //mapCoord[ii(j+1, -i)]=n;
	    }

        n = beforeYP + 6*(i-1)+5; //f(n) = f(n-1) + 6(n-1) + 5 calcula (0,Y)
        coord[n]=ii(0,i); beforeYP=n;
        //mapCoord[ii(0,i)]=n;

        FOR(j,i-1){
            n--; coord[n]=ii(-j-1, i);
            //mapCoord[ii(-j-1, i)]=n;
        }

        n+=i-1; //(0,Y)
        FOR(j,i+1){
            n++; coord[n]=ii(j+1,i-j-1);
            //mapCoord[ii(j+1,i-j-1)]=n;
        }

        FOR(j,i-1){
            n++; coord[n]=ii(i+1,-j-2);
            //mapCoord[ii(i+1,-j-2)]=n;
        }
    }
}

/* -------- DO IT BY BFS ------------
int dx [] = { 1, 1, 0,-1,-1, 0}; // Seis direcciones
int dy [] = { 0,-1,-1, 0, 1, 1};

typedef vector<int> vi;
vector<vi> graph(10005);

void makeGraph(){
    loop(u,1,10001){
        FOR(k,6){
            int x = coord[u].fi+dx[k], y=coord[u].se+dy[k];
            if(abs(x)>=59 || abs(y)>=59) continue;
            int v = mapCoord[ii(x,y)];
            if(v>10000) continue;
            graph[u].push_back(v);
        }
    }
}

int bfs(int src, int tgt){
    vector<int> dist(10005, INF); dist[src]=0;
    queue<int> q; q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u==tgt) break;
        FOR(j,graph[u].size()){
            int v = graph[u][j];
            if(dist[v]==INF){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    assert(dist[tgt]!=INF);
    return dist[tgt];
}*/

int main(){
    ios::sync_with_stdio(false);
    makeSystemCoord();
    //makeGraph(); //do it by bfs

    int n,m, x, y;
    while(cin>>n>>m, n&&m){
        int x=coord[n].fi-coord[m].fi, y = coord[n].se-coord[m].se;

        cout<<"The distance between cells "<<n<<" and "<<m<<" is ";
        if((x<0 && y>0) || (x>0 && y<0)) cout<<max(abs(x), abs(y));
        else cout<<abs(x)+abs(y);
        //cout<<bfs(n,m); //do it by bfs
        cout<<"."<<endl;
    }
    return 0;
}
