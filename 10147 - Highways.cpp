#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 760

using namespace std;

typedef pair<int ,int> ii;
typedef vector<ii> vii;
typedef pair<double, ii> dii;
typedef vector<dii> vdii;

vdii edges;
vii MST;

int Parent[MAXN],Rank[MAXN];

int N, M;

void init(){
	FOR(i,N){
		Parent[i]=i; Rank[i]=1;
	}
}

int findP(int x){
	if(Parent[x]!=x) Parent[x]=findP(Parent[x]);
	return Parent[x];
}

void Union(int rootX, int rootY){
	if(Rank[rootX]>Rank[rootY]){
		Parent[rootY]=rootX; Rank[rootX]+=Rank[rootY];
	}else{
		Parent[rootX]=rootY; Rank[rootY]+=Rank[rootX];
	}
}

void kruskal(){
	sort(edges.begin(),edges.end());
	double length=0.0;
	int bridges=0;
	MST.clear();
	FOR(i,edges.size()){
		if(bridges==N-1) break;
		double w=edges[i].first;
		int x=edges[i].second.first, y=edges[i].second.second;
		int rootX=findP(x), rootY=findP(y);
		if(rootX!=rootY){
			Union(rootX,rootY);
			length+=w;
			bridges++;
			MST.push_back(ii(x+1,y+1));
		}
	}
}

double Distance(int x1,int y1, int x2, int y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main(){
	int a, b, tc; cin>>tc;
	FOR(t,tc){
		edges.clear();
		cin>>N;
		vii p;
		FOR(i,N){
			cin>>a>>b;
			p.push_back(ii(a,b));
		}

		init();
		cin>>M;
		FOR(i,M){
			cin>>a>>b;
			int rootA=findP(a-1), rootB=findP(b-1);
			if(rootA!=rootB) Union(rootA, rootB);
		}

		FOR(i,N){
			loop(j,i+1, N){
                double w=Distance(p[i].first,p[i].second, p[j].first,p[j].second);
                edges.push_back(dii(w,ii(i,j)));
                edges.push_back(dii(w,ii(j,i)));
			}
		}
		kruskal();
		if(t!=0) cout<<endl;
		if(MST.size()==0){
            cout<<"No new highways need"<<endl;
		}else{
            FOR(i,MST.size()){
                cout<<MST[i].first<<" "<<MST[i].second<<endl;
            }
		}
	}
	return 0;
}

