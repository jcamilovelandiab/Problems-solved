#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

struct file{
	string fullname;
	string name;
	string ext;
	bool cand;
};

int main(){
	int N, msg, tc;
	string f;
	bool first=true;
	cin>>tc;
	FOR(t,tc){
		cin>>N>>msg;
		vector<file> files(N);
		map<string,int> names, extends;
		FOR(i,N){
			cin>>files[i].fullname;
			int j=0;
			files[i].name="";
			for(;j<files[i].fullname.size() && files[i].fullname[j]!='.'; j++){
				files[i].name+=files[i].fullname[j];
			}
			if(j>=files[i].fullname.size()-1) files[i].ext=" ";
			else files[i].ext=files[i].fullname.substr(j+1);
			
			if(names.find(files[i].name)==names.end()) names[files[i].name]=1;
			else names[files[i].name]++;
			
			if(extends.find(files[i].ext)==extends.end()) extends[files[i].ext]=1;
			else extends[files[i].ext]++;
			files[i].cand=true;
			//cout<<f.fullname<<" - "<<f.name<<"|"<<f.ext<<"|"<<endl;
		}
		int count=N;
		FOR(r,msg){
			FOR(j, N){
				if(!files[j].cand) continue;
				if(r%2==0){
					//cout<<files[j].ext<<endl;
					if(extends[files[j].ext]==1){
						files[j].cand=false;
						count--;
						if(names[files[j].name]>1) names[files[j].name]--; //para no bloquear futuros fullnames que pueden bloqueados
					}
				}else{
					if(names[files[j].name]==1){
						files[j].cand=false;
						count--;
						if(extends[files[j].ext]>1) extends[files[j].ext]--; 
					}
				}
			}
		}
		if(t!=0) cout<<endl;
		cout<<count<<endl;
		if(count>0){
			FOR(i,files.size()){
				if(files[i].cand) cout<<files[i].fullname<<endl;
			}
		}
	}	
	return 0;
}

