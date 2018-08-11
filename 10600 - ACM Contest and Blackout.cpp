#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define f first
#define s second
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<iii> viii;

viii edges, mst;
int N, M, wMst, Parent[110], Rank[110], trees;

int findP(int x){
    if(x!=Parent[x]) Parent[x]=findP(Parent[x]);
    return Parent[x];
}

void Union(int rootX, int rootY){
    if(Rank[rootX]>Rank[rootY]){
        Rank[rootX]+=Rank[rootY];
        Parent[rootY]=rootX;
    }else{
        Rank[rootY]+=Rank[rootX];
        Parent[rootX]=rootY;
    }
    trees--;
}

void init(){
    trees=N;
    FOR(i,N+2){
        Rank[i]=0; Parent[i]=i;
    }
}

int Kruskal(bool bestMST, ii edgeOmitted){
    init();
    int wTotal=0;
    FOR(i,edges.size()){
        if(edges[i].s==edgeOmitted) continue;
        int w = edges[i].f, x=edges[i].s.f, y = edges[i].s.s;
        int rootX=findP(x), rootY=findP(y);
        if(rootX!=rootY){
            wTotal+=w;
            Union(rootX, rootY);
            if(bestMST) mst.push_back(edges[i]);
        }
    }

    // si estoy buscando el 2do MST
    //y el grafo no esta completamente conectado retorno infinito
    if(!bestMST && trees!=1) return INF;

    return wTotal;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int T, A, B, C;
    cin>>T;
    while(T--){
        cin>>N>>M;
        mst.clear(); edges.clear();
        trees=N;
        FOR(i,M){
            cin>>A>>B>>C;
            edges.push_back(iii(C, ii(A,B)));
        }
        sort(edges.begin(), edges.end());
        wMst = Kruskal(true, ii(-1,-1));
        cout<<wMst<<" ";
        int secondMST=INF;
        FOR(i,mst.size()){
            secondMST=min(secondMST, Kruskal(false,mst[i].s));
        }

        if(secondMST==INF) cout<<wMst<<endl;
        else cout<<secondMST<<endl;
    }
    return 0;
}
