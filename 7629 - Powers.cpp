#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

typedef long long ll;

void solve(ll n){
	ll limit = ceil(sqrt(n));
	for(ll a=2; a<=limit; a++){
		float tempB;
		tempB = log(n)/log(a);
		
		ll b;
		b=floor(tempB);
		
		//cout<<"a: "<<a<<" "<<tempB<<" -- "<<b<<endl;
		if(fabs(tempB-(double)b)<=EPS){ // check if b is an integer
			if(pow(a,b)==n){
				cout<<a<<"^"<<b<<endl; return;
			}	
		}
	}
	cout<<n<<"^1"<<endl;
}

int main(){
	//freopen("in7629.txt","r",stdin);
	ll N;
	while(cin>>N, N!=-1){
		solve(N);
	}
	return 0;
}
