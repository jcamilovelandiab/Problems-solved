#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

typedef pair<char,char> pcc;

int main(){
	string line;
	vector<vector<pcc> > cities(105);
	vector<pcc> city;
	
	int j,k;
	
	getline(cin,line);
	while(line!="#"){
		int changes=INT_MAX, city=0;
		
		while(line[0]!='e'){
			cities[city].clear();
			j=0; k=0;
			char bins[5],rec[5];
			loop(i,0,line.size()){
				if(line[i]=='r' || line[i]=='o' || line[i]=='y' || line[i]=='g' || line[i]=='b') bins[j++]=line[i];
				else if(line[i]=='P'|| line[i]=='G' || line[i]=='S' || line[i]=='A' || line[i]=='N') rec[k++]=line[i];
			}
			loop(i,0,5) cities[city].push_back(pcc(bins[i],rec[i]));
			sort(cities[city].begin(),cities[city].end());
			city++;	
			getline(cin,line);
		}
		
		int minCity=1000000,minChanges=1000000;
		loop(i,0,city){
			int changes=0;
			loop(j,0,city){
				if(i==j) continue;
				loop(k,0,5){
					if(cities[i][k]!=cities[j][k]) changes++;
				}
			}
			if(changes<minChanges){
				minCity=i; minChanges=changes;
			} 
		}
		cout<<minCity+1<<endl;		
		getline(cin,line);
	}
	return 0;
}
