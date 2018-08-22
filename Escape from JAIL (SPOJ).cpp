#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXV 100005
#define MAXK 50005

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> graph(MAXV);
int doorIsOpenedBy[MAXV];
bool visited[MAXV];

int N, K, M;

void printQueue(queue<int> q){
	cout<<"BEGIN QUEUE:\n";
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"END QUEUE"<<endl;
}

bool bfs(){
    queue<int> q; q.push(1); visited[1]=true;
    queue<int> time; time.push(0);
    while(!q.empty()){
        int u = q.front(), c = time.front(); q.pop(); time.pop();		
        
        if(u==N) return true;
		
		if(c>4*N) return false;
		
		if(doorIsOpenedBy[u]!=-1){
			if(!visited[doorIsOpenedBy[u]]){
				time.push(c+1);
				q.push(u); continue;
			}
		}
        
        FOR(j, graph[u].size()){
            int v = graph[u][j];
            if(!visited[v]){
            	visited[v]=true; q.push(v);
            	time.push(c+1);
			}
        }
        
    }
    return false;
}

int main(){
    int A,B, u, v;
    while(cin>>N>>K>>M, N!=-1 && K!=-1 && M!=-1){
    	FOR(i,N+1){
    		visited[i]=0; doorIsOpenedBy[i]=-1;
    		graph[i].clear();
		}

        FOR(i,K){
            cin>>A>>B;
            doorIsOpenedBy[B]=A; //la puerta de la sala B es abierta por la puerta de la sala A
        }

        FOR(i,M){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(bfs()) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		
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


