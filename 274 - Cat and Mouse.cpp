#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define pushb push_back
#define popb pop_back

using namespace std;

int cat, mouse, rooms;

typedef vector<int> vi;
typedef vector<char*> vs;

vector<vi> graphCat(505), graphMouse(505);
bool visCat[505], visMouse[505];

void dfsCat(int u){
    visCat[u]=true;
    FOR(j, graphCat[u].size()){
        int v = graphCat[u][j];
        if(!visCat[v]){
            dfsCat(v);
        }
    }
}

void dfsMouse(int u, int tgt){
    visMouse[u]=true;
    if(u==tgt) return;
    FOR(j, graphMouse[u].size()){
        int v = graphMouse[u][j];
        if(!visMouse[v]){
            dfsMouse(v, tgt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int tc, u, v;
    cin>>tc;
    while(tc--){
        cin>>rooms>>cat>>mouse;
        rooms++;
        //clear the graphs
        loop(i,1,rooms){
            graphCat[i].clear(); graphMouse[i].clear();
            visCat[i]=false; visMouse[i]=false;
        }

        while(cin>>u>>v, u!=-1 && v!=-1) graphCat[u].pushb(v);
        cin.ignore(); string line;
        while(getline(cin,line), line!=""){
            stringstream ss(line);
            ss>>u>>v;
            graphMouse[u].pushb(v);
        }
        dfsCat(cat); dfsMouse(mouse, rooms+1);

        bool meet=false, walkMouse=false;
        vi reachableMouse;
        loop(i,1,rooms){
            if(visCat[i] && visMouse[i]) meet=true;
            else if(!visCat[i] && visMouse[i]){
                reachableMouse.pushb(i);
            }
        }
        FOR(i,reachableMouse.size()){
            int u = reachableMouse[i];
            if(u==mouse) continue;
            memset(visMouse, false, rooms+1);
            dfsMouse(u, mouse);
            if(visMouse[mouse]){
                walkMouse=true; break;
            }
        }
        cout<<(meet ? "Y": "N")<<" "<<(walkMouse ? "Y": "N")<<endl;
        if(tc!=0) cout<<endl;
    }
    return 0;
}
