/**
	UVa Online Judge - Problem 11514-Batman
	TIME LIMIT
	@Author JCamiloVB
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e11

using namespace std;

typedef vector<string> vs;
typedef long long large;
typedef pair<large,large> ii;

large P,V,E, currentVID;

map<string,large> powers; //identificador del poder
large damageP[1005]; //daño de cada poder
large energyP[1005]; //energia que se gasta usando cada poder

int defVillain[1005]; //defensa de villano
vector<vs> weakness(1005); //poderes que afectan al villano
map<ii,large> dp;

//retorna la maxima energia que le queda al vencer a un villano

large f(large i, large defV){
    //cout<<"i->"<<i<<" ,defV ->"<<defV<<endl;
    if(defV<=0) return dp[ii(i,defV)]=0;
    if(i<0) return INF;
    if(dp.find(ii(i, defV))!=dp.end()) return dp[ii(i, defV)];
    else{
        large wk=powers[weakness[currentVID][i]];
        large f1=f(i-1, defV-damageP[wk]), f2=f(i-1, defV);
        if(f1==INF) dp[ii(i,defV)]=f2;
        else dp[ii(i,defV)]=min(energyP[wk]+f1, f2);
        return dp[ii(i,defV)];
    }
}

void readln(int id){
	string line; getline(cin,line);
	stringstream ss(line);
	string v; ss>>v;//cout<<"v -> "<<v<<endl;
	large defense; ss>>defense; //cout<<"d -> "<<defense<<endl;
	defVillain[id]=defense;
	string str; ss>>str; //cout<<"weaknesses -> "<<str<<endl;
	stringstream wks(str);
	string w;
	while(getline(wks,w,',')){
		weakness[id].push_back(w);
	}
}

bool solve(){
    FOR(id, V){
        currentVID=id;
        dp.clear();
        E-=f(weakness[id].size()-1, defVillain[id]);
        if(E<0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
	large a,e;
	string power;
	while(cin>>P>>V>>E, P!=0 && V!=0 && E!=0){
		powers.clear();
		FOR(i,P){
			cin>>power>>a>>e;
			powers[power]=i;
			damageP[i]=a;
			energyP[i]=e;
		}
		cin.ignore();
		FOR(i,V){
			weakness[i].clear();
			readln(i);
		}
		cout<<(solve()?"Yes":"No")<<endl;
	}
	return 0;
}
