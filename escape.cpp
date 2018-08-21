#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXV 100005
#define MAXK 50005

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> graph(MAXV);
vector<bool> keysTaken(MAXK);
vi chamberHasKey(MAXV), chamberHasDoor(MAXV);
vi doorInChamber(MAXK), visited(MAXV);

bool bfs(int s, int t){
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        visited[u]=1;
        if(u==t) return true;
        //cout<<"NODE: "<<u<<endl;
        FOR(j, graph[u].size()){
            int v = graph[u][j];
            if(v==t) return true;
            if(visited[v]!=0) continue;
            if(chamberHasKey[v]==-1 && chamberHasDoor[v]==-1){
                // no tiene ni puerta ni llave
                q.push(v);
            }else{
                if(chamberHasDoor[v]!=-1 && !keysTaken[chamberHasDoor[v]]){ //llego a una puerta y no tengo la llave
                    visited[v]=2; // digo que la visite la puerta pero no pude entrar entonces no lo empujo a la cola
                }else if(chamberHasKey[v]!=-1){ // si hay una llave en la sala
                    q.push(v);
                    keysTaken[chamberHasKey[v]]=true; //recojo la llave
                    //miro a que sala pertenece la llave
                    int chamber = doorInChamber[chamberHasKey[v]];
                    // si ya visite la sala eso quiere decir que ya tengo
                    // algun camino hacia la sala, y ya tengo la llave de
                    //la puerta, empujo la sala a la cola
                    if(visited[chamber]==2){
                        q.push(chamber);
                    }
                }
            }

        }
    }
    return false;
}

int main(){
    int N,K,M, A,B, u, v;
    while(cin>>N>>K>>M, N!=-1 && K!=-1 && M!=-1){
        FOR(i,N+1){
            chamberHasKey[i]=-1; chamberHasDoor[i]=-1;
            graph[i].clear(); visited[i]=0;
        }

        FOR(i,K){
            cin>>A>>B;
            chamberHasKey[A]=i; chamberHasDoor[B]=i;
            doorInChamber[i]=B; keysTaken[i]=false;
        }

        FOR(i,M){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool answer = bfs(1,N);
        cout<<((answer)?"Y":"N")<<endl;
    }
    return 0;
}
/*
4 1 4 
2 3 
3 4 
2 3 
1 3 
2 4 
6 2 5 
5 4 
3 2 
2 6 
2 5 
1 4 
1 5 
3 4 
4 1 1 
3 2 
2 3 
-1 -1 -1 
*/


