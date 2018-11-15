#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef pair<int,string> is;

map<string,is> path;
map<string,bool> vis;

string src;

void bfs(){
    src = "123456789"; vis[src]=true;
	path[src]=is(0,"");
    queue<string> q; q.push(src);
    while(!q.empty()){
        string u = q.front(), v; q.pop();
        is infoU = path[u];
        //cout<<"vertical down move"<<endl;
        FOR(i,3){
            v="";
            FOR(j,3){
                FOR(k,3){
                    if(i==k) v+=u[(j*3+k+6)%9];
                    else v+=u[j*3+k];
                }
            }
            if(!vis[v]){
                vis[v]=true; q.push(v);
                stringstream st; st<<i+1; string step = "V"+st.str();
                path[v]=is(infoU.first+1,step+infoU.second);
            }
        }
        //cout<<"horizontal left move"<<endl;
        FOR(i,3){
            v = u.substr(0,i*3)+u.substr(i*3+1,2)+u[i*3]+u.substr(i*3+3,9-i*3+1);
            if(!vis[v]){
                vis[v]=true; q.push(v);
                stringstream st; st<<i+1; string step = "H"+st.str();
                path[v]=is(infoU.first+1,step+infoU.second);
            }
        }
    }
}

int main(){
	bfs();
    string target;
    int n;
    while(cin>>n, n){
        target="";
        string temp; stringstream ss; ss<<n;
        ss>>temp; target+=temp;
        loop(i,1,9){
            cin>>n; ss.clear(); ss<<n; temp="";
            ss>>temp; target+=temp;
        }
        //cout<<target<<endl;
        if(path.find(target)==path.end()){
            cout<<"Not solvable"<<endl;
        }else{
            is answer = path[target];
            cout<<answer.first<<" "<<answer.second<<endl;
        }
    }
    return 0;
}
