/**
    10511 - Councilling, UVa online judge
    time: 1.7s
    EdmondsKarp - Maxflow
    @author JCamiloVB
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a; i++)
#define loop(i,a,b) for(int i=a;i<b; i++)
#define MAXN 2080
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef vector<string> vs;
typedef vector<int> vi;

map<string,vs> clubs;
map<string,ii> resid;
map<string,int> parties;
map<int,string> idClubs, idResids;

int V, mf, f, src, tgt, res[MAXN][MAXN], nc, nr, np;
vi p;

void augment(int v, int minEdge){
	if(v==src){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(res[p[v]][v], minEdge));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

void bfs(){
	p.assign(V, -1);
	bitset<MAXN> vis; vis.set(src);
	queue<int> q; q.push(src);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==tgt) break;
		FOR(v, V){
			if(res[u][v]>0 && !vis[v]){
				vis.set(v); q.push(v); p[v]=u;
			}
		}
	}
}

int edmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(tgt,INF);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(); //faster
	int tc;
	cin>>tc;
	string line, r,p,c;
	cin.ignore(); cin.ignore();
	FOR(t, tc){
		clubs.clear(); resid.clear(); parties.clear();
		idClubs.clear(); idResids.clear();
		memset(res, 0, sizeof res);

		nr=1, np=1;
		while(getline(cin,line), !line.empty()){
			stringstream ss(line);
			ss>>r>>p;
			if(parties.find(p)==parties.end()) parties[p]=np++;
			resid[r]=ii(nr++,parties[p]);
			while(ss>>c){
				clubs[c].push_back(r);
			}
		}
		src=0; nr--; np--; nc=clubs.size();
		int idClub=1;
		for(map<string,vs>::iterator it=clubs.begin(); it!=clubs.end(); it++){
			string c = it->first; vs residents=it->second;
			//cout<<"CLUB "<<c<<" ->";
			res[src][idClub]=1;
			FOR(j, residents.size()){
				int idResid = resid[residents[j]].first+nc;
				res[idClub][idResid]=1;
				//cout<<" "<<residentes[j];
			}
            //cout<<"CLUB: "<<idClub<<" -> "<<c<<endl;
			idClubs[idClub++]=c;
			//cout<<endl;
		}
		for(map<string,ii>::iterator it=resid.begin(); it!=resid.end(); it++){
			string r = it->first;
			int idR=(it->second).first+nc, idP=(it->second).second+nc+nr;
			idResids[idR]=r;
			//cout<<"RESIDENT: "<<idR<<" -> "<<r<<endl;
			res[idR][idP]=1;
		}
		V=nc+nr+np+2; tgt=V-1;
		//cout<<"nClubs:"<<nc<<", nResidents:"<<nr<<", nParties:"<<np<<endl;
		for(map<string,int>::iterator it=parties.begin(); it!=parties.end(); it++){
			string p = it->first; int idP=(it->second)+nc+nr;
			res[idP][tgt]=(nc+1)/2-1;
            //cout<<"PARTIE: "<<idP<<" -> "<<p<<endl;
		}
		/*FOR(i,V){
			cout<<i<<" ->";
			FOR(j,V){
				cout<<" "<<res[i][j];
			}
			cout<<endl;
		}*/
		if(t!=0) cout<<endl;
		if(edmondsKarp()!=nc) cout<<"Impossible."<<endl; //the council couldn't be formed
		else{
			loop(i,1,nc+1){
				loop(j,nc+1,nc+nr+1){
					if(res[i][j]<=0 && res[j][i]>0) cout<<idResids[j]<<" "<<idClubs[i]<<endl;
				}
			}
		}
	}
	return 0;
}
/*
2

fred dinosaur jets jetsons
john rhinocerous jets rockets
mary rhinocerous jetsons rockets
ruth platypus rockets

fred dinosaur jets jetsons
john rhinocerous jets rockets
mary rhinocerous jetsons rockets
ruth dinosaur rockets
*/
