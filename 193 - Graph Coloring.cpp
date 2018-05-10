#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<vector<int> > listAdy(120);

int n;
vector<int> maxColored;
string line;

bool mayColoring(int node, vector<int> colored){
	int neighbor;
	loop(i,0,listAdy[node].size()){
		neighbor=listAdy[node][i];
		loop(j,0,colored.size()){
			if(neighbor == colored[j]) return false; // esta coloreado
		}
	}
	return true;
}

void imprimir(vector<int> vec){
	loop(i,0,vec.size()) cout<<vec[i]<<" ";
	puts("");
}

void solve(int node,vector<int> colored){
	if(node==n+1){
		if(colored.size()>maxColored.size()){
			maxColored=colored;
		}
	}else{
		//getline(cin,line);
		//cout<<"node: "<<node<<" colored: "; imprimir(colored);
		if(mayColoring(node, colored)){
			
			colored.push_back(node);
			solve(node+1, colored); // ya lo coloree
			
			colored.pop_back(); // no lo coloreo
			solve(node+1, colored);
		}else{
			solve(node+1, colored);
		}
	}
}

int main(){
	int cases,m, x,y;
	cin>>cases;
	while(cases--){
		cin>>n>>m;

		maxColored.clear(); loop(i,0,n+2) listAdy[i].clear(); // voy limpiando la listAdy
		
		// CREO LA LISTA DE ADYACENCIA
		loop(i,0,m){
			cin>>x>>y;
			listAdy[x].push_back(y);
			listAdy[y].push_back(x);
		}
		vector<int> colored;
		solve(1,colored);
		
		cout<<maxColored.size()<<endl;
		loop(i,0,maxColored.size()-1) cout<<maxColored[i]<<" ";
		cout<<maxColored[maxColored.size()-1]<<endl;
		/*
		loop(i,1,n+1){
			cout<<i<<": ";
			loop(j,0,listAdy[i].size()) cout<<listAdy[i][j]<<" ";
			cout<<coloring[i];
			puts("");
		}*/
	}
	return 0;
}
