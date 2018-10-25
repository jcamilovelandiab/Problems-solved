/**
	UVa Online Judge - Problem 11514-Batman
	TIME LIMIT
	@Author JCamiloVB
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define x first
#define y second
#define INF 1e09

using namespace std;

typedef vector<string> vs;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int P,V,E, currentVID;

map<string,int> powers; //identificador del poder
int damageP[1005]; //daño de cada poder
int energyP[1005]; //energia que se gasta usando cada poder

vs villains(1005); //arreglo de villanos
int defVillain[1005]; //defensa de villano
vector<vs> weakness(1005); //poderes que afectan al villano

map<ii,int> dp;

bool answer;

//retorna la maxima energia que le queda al vencer a un villano
int f(int i, int eB, int dV){ //indice que itera los poderes que afectan al villano, energia de batman, defensa del Villano
	//cout<<"eB->"<<eB<<", dV->"<<dV<<" - i->"<<i<<endl;
	if(eB<0) return -INF;
	if(dV<=0) return dp[ii(i, dV)]=eB;
	if(i<0) return -INF;
	if(dp.find(ii(i, dV))!=dp.end()) return dp[ii(i, dV)];
	else{
		int wk = powers[weakness[currentVID][i]];
		return dp[ii(i, dV)]=max(f(i-1, eB-energyP[wk], dV-damageP[wk]), f(i-1, eB, dV));
	}
}

void readln(int id){
	//split de la cadena
	string line; getline(cin,line);
	string v, d;
	int i=0;
	for(;line[i]!=' '; i++) v+=line[i];
	villains.push_back(v);
	//cout<<"v -> "<<v<<endl;
	
	for(i=i+1;line[i]!=' '; i++) d+=line[i];
	int defense;
	stringstream ss(d); ss>>defense;
	defVillain[id]=defense;
	
	//cout<<"d -> "<<defense<<endl;
	//cout<<"weakness ->";
	for(i=i+1; i<line.size(); i++){
		string w;
		for(; i<line.size() && line[i]!=','; i++) w+=line[i];
		//cout<<" "<<w;
		weakness[id].push_back(w);
	}
	//cout<<endl;
	currentVID=id;
	if(answer){
		int newE=f(weakness[id].size()-1, E, defVillain[id]);
		//cout<<newE<<endl;
		if(newE==-INF) answer=false;
		else E=newE;
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	int a,e;
	string power;
	while(cin>>P>>V>>E, P && V && E){
		powers.clear(); dp.clear();
		FOR(i,P){
			cin>>power>>a>>e;
			powers[power]=i;
			damageP[i]=a;
			energyP[i]=e;
		}
		cin.ignore();
		
		answer=true;
		FOR(i,V){
			readln(i);
		}
		
		cout<<(answer?"Yes":"No")<<endl;
	}
	return 0;
}

