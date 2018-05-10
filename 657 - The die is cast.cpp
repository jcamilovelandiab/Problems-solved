#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int w,h, cnt;
char matrix[55][55];

int dx[]={-1, 1, 0, 0};
int dy[]={ 0, 0,-1, 1};

void imprimirMatrix(){
	puts("INICIO DE LA MATRIZ");
	FOR(i,h) cout<<matrix[i]<<endl;
	puts("FIN DE LA MATRIZ\n");
}

void floodFillX(int i, int j){
	if(i<0 || i>=h || j<0 || j>=w || matrix[i][j]!='X') return;
	matrix[i][j]='+';
	FOR(k,4){
		int x=i+dx[k], y=j+dy[k];
		floodFillX(x, y);
	}
}

void floodFill(int i, int j){
	if(i<0 || i>=h || j<0 || j>=w || matrix[i][j]=='.') return;
	string line;
	//getline(cin,line);
	//imprimirMatrix();
	if(matrix[i][j]=='X'){
		cnt++;
		floodFillX(i,j);
	}else{
		matrix[i][j]='.';
	}
	
	FOR(k,4){
		int x=i+dx[k], y=j+dy[k];
		floodFill(x,y);
	}
}

int main(){
	//freopen("in657.txt","r",stdin);
	int tc=1;
	while(cin>>w>>h){
		if(w==0 || h==0) break;
		getchar(); FOR(i,h) gets(matrix[i]);

		vector<int> answer;
		FOR(i,h){
			FOR(j,w){
				if(matrix[i][j]=='X'){
					cnt=0;
					floodFill(i,j);
					answer.push_back(cnt);
				}
			}
		}
		
		sort(answer.begin(), answer.end());
		cout<<"Throw "<<tc++<<endl;
		cout<<answer[0];
		loop(i, 1, answer.size()) cout<<" "<<answer[i];
		cout<<endl<<endl;
	}
	return 0;
}
