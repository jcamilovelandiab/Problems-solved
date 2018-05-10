#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define inf 1e9

using namespace std;
typedef pair<int,int> ii;

vector<int> cuts;
string line;
int memo[55][55];

int f(int low, int high){
	//getline(cin,line);
	//printf("low: %d  high: %d\n", low, high);
	if(low+1==high){
		return 0;
	}else if(memo[low][high]!=-1){
		return memo[low][high];
	}
	
	int cut=inf;
	loop(i,low+1,high){
		//cout<<low<<" "<<i<<" "<<high<<endl;
		cut=min(cut, f(low,i)+f(i,high)+(cuts[high]-cuts[low]) );
	}
	memo[low][high]=cut;
	return cut;
}

int main(){
	int l,n, c;
	while(cin>>l, l){
		cin>>n;
		cuts.clear();
		loop(i,0,55) loop(j,0,55) memo[i][j]=-1;
		
		cuts.push_back(0);
		loop(i,0,n){
			cin>> c; 
			cuts.push_back(c);
		}
		cuts.push_back(l);
		
		printf("The minimum cutting is %d.\n", f(0,n+1));
	}
	return 0;
}
