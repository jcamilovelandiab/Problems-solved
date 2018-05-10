#include <bits/stdc++.h>
#define loop(i,a) for(int i=0; i<a; i++)
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;

vector<int> start, destination;
map<vi, vector<vi> > mapAdy;
map<vi, vector<vi> >::iterator it;
map<vi, int> dist;

void constructGraph(){
    vector<int> node, v;
    loop(i,10){
        node.push_back(i);
        loop(j,10){
            node.push_back(j);
            loop(k,10){
                node.push_back(k);
                loop(m, 10){
                    node.push_back(m);// keys.push_back(node);
                    loop(t,4){
                        v.clear();
                        loop(r,4){
                            if(r==t) v.push_back((node[t]+1)%10);
                            else v.push_back(node[r]);
                        }
                        mapAdy[node].push_back(v);

                        v.clear();
                        loop(r,4){
                            if(r==t) v.push_back((node[t]==0)? 9 : node[t]-1);
                            else v.push_back(node[r]);
                        }
                        mapAdy[node].push_back(v);
                    }
                    node.pop_back();
                }
                node.pop_back();
            }
            node.pop_back();
        }
        node.pop_back();
    }
}

int bfs(){

    dist[start]=0;
    queue<vi> q; q.push(start);
    while(!q.empty()){
        vi u = q.front(); q.pop();
        if(u==destination) break;
        loop(i,mapAdy[u].size()){
            vi v=mapAdy[u][i];
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    
    if(dist[destination]==INT_MAX) return -1;
    return dist[destination];
}

int main(){
    ios::sync_with_stdio(false);
    constructGraph();
    
    int tc, n, digit;
    vi v;

    cin>>tc;
    while(tc--){
        start.clear(); destination.clear();
        loop(i,4){
            cin>>digit; start.push_back(digit);
        }
        loop(i,4){
            cin>>digit; destination.push_back(digit);
        }
        
        for(it=mapAdy.begin(); it!=mapAdy.end(); it++) dist[it->fi]=-1;
        
        cin>>n;
        while(n--){
            v.clear();
            loop(i,4){
                cin>>digit; v.push_back(digit);
            }
            dist[v]=INT_MAX;
        }
        cout<<bfs()<<endl;
    }
}
