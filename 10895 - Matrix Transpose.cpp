#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m, nr, c, r, value;
	while(cin>>n>>m){
		
		vector<vii> AdjList(10010);
		
		loop(r,1,n+1){
			cin>>nr;
			vector<int> columns;
			FOR(i,nr){
				cin>>c; columns.push_back(c);
			}
			FOR(i,nr){
				cin>>value;
				AdjList[columns[i]].push_back(ii(r,value));
			}
		}
		cout<<m<<" "<<n<<endl;
		loop(i,1,m+1){
			cout<<AdjList[i].size();
			FOR(j,AdjList[i].size()) cout<<" "<<AdjList[i][j].first;
			cout<<endl;
			if(AdjList[i].size()>0){
				cout<<AdjList[i][0].second;
				loop(j,1,AdjList[i].size()) cout<<" "<<AdjList[i][j].second;
			}
			cout<<endl;
		}
	}
	return 0;
}

