#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a;  i<b; i++)

using namespace std;

typedef vector<char*> vs;
typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<48000> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(ll i=2; i<= _sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<= _sieve_size; j+= i) bs[j]=0;
		primes.push_back((int)i);
	}
}

vi primeFactors(ll N){
	vi factors;
	ll PF_idx=0, PF=primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF==0){
			N/=PF; factors.push_back(PF);
		}
		PF=primes[++PF_idx];
	}
	if(N!=1) factors.push_back(N);
	return factors;
}

int main(){
	ios::sync_with_stdio(false);
	sieve(47000);
	int n;
	while(cin>>n, n){
		cout<<n<<" = ";
		if(n<0){
			cout<<"-1 x "; n*=-1;
		}
		vi vecPF = primeFactors(n);
		cout<<vecPF[0]; loop(i,1,vecPF.size()) cout<<" x "<<vecPF[i];
		cout<<endl;
	}
	return 0;
}

