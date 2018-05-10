#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

char matrix[11][11];
int ans;

string line;

void press(int i, int j){
	loop(p,max(0,j-1),min(10,j+2)){
		matrix[i][p] = (matrix[i][p]=='#') ? 'O' : '#';
	}
	if(i>0) matrix[i-1][j] = (matrix[i-1][j]=='#') ? 'O' : '#';
	if(i<9) matrix[i+1][j] = (matrix[i+1][j]=='#') ? 'O' : '#';
}

void solve(int i, int j, int p){
	//imprimir(mat);
	//getline(cin,line);
	if(j==10){ i+=1; j=0; }
	if(i==0){
		press(i,j); // presiono el interruptor
		solve(i,j+1, p+1);
		
		press(i,j); // vuelvo a la anterior matriz
		solve(i,j+1,p); // no presiono ningun interruptor
		
	}else if(i>0 && i<10){
		//imprimir();
		//getline(cin,line);
		if(matrix[i-1][j]=='O'){
			press(i,j); // lo presiono
			solve(i,j+1,p+1);
			// vuelvo a la anterior matriz
			press(i,j);
		}else{
			solve(i,j+1,p);
		}
		
	}else if(i==10){
		loop(k,0,10){ if(matrix[9][k]=='O') return; } // no apagó todos los bombillos
		if(p<ans) ans=p;
	}
}

int main(){
	string ins;
	while(cin>>ins, ins!="end"){
		ans=INT_MAX;
		loop(i,0,10) cin>>matrix[i];
		solve(0,0,0);
		cout<<ins<<" "<<ans<<endl;
	}	
	return 0;
}
