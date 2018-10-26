#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09

using namespace std;


typedef pair<int,int> ii;
typedef long long large;

map<ii,int> dp;

int P,V,E;

struct power{
    string name;
    int attack, energy;
    power(string n, int a, int e): name(n),attack(a), energy(e) {}
};

struct villain{
    int id;
    int defense;
    set<string> weakness;
    villain(int _id, int _defense): id(_id), defense(_defense){}
};

vector<power> pwrs;
vector<villain> vls;

void readln(int id){
    string line, v, weak, token; int defense;
    getline(cin,line);
    stringstream ss(line); ss>>v>>defense>>weak;
    stringstream split(weak);
    villain vl = villain(id, defense);
    while(getline(split,token,',')){
        vl.weakness.insert(token);
    }
    vls.push_back(vl);
}

large f(int pr, int vl){
    if(dp.find(ii(pr,vl))!=dp.end()) return dp[ii(pr,vl)];
    if(pr>=P && vl<V) return dp[ii(pr,vl)]=INF;
    if(vl>=V) return dp[ii(pr,vl)]=0;
    else{
        if(vls[vl].weakness.find(pwrs[pr].name)!=vls[vl].weakness.end()){
            if(pwrs[pr].attack >= vls[vl].defense){
                return dp[ii(pr,vl)]=min(pwrs[pr].energy+f(pr+1, vl+1), f(pr+1, vl));
            }
        }
        return dp[ii(pr,vl)]=f(pr+1, vl);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    string pwr;
    int e, a;
    while(cin>>P>>V>>E,P){
        pwrs.clear(); vls.clear(); dp.clear();
        FOR(i,P){
            cin>>pwr>>a>>e;
            pwrs.push_back(power(pwr,a,e));
        }
        cin.ignore();
        FOR(i,V) readln(i);
        large ans=f(0,0);
        if(E>=ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
