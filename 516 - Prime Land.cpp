#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a;  i<b; i++)

using namespace std;

typedef vector<char*> vs;
typedef vector<int> vi;
typedef long long ll;

vi splitstrip(char* s, char c){
	int i, tok=1, sp=0;
	vs l;
	for(i=0; s[i]; i++){
		if(s[i]==c) tok=1, s[sp]=0;
		else if(s[i]!=' '){
			sp=i+1;
			if(tok) l.push_back(s+i), tok=0;
		}else if(s[sp]!=' '){
			sp=i;
		}
	}
	if(i>0 && s[i-1]=='\n') s[i-1]=0;
	vi res;
	FOR(i,l.size()){
		cout<<l[i]<<endl;
		stringstream strValue; strValue<<l[i];
		int temp; strValue>>temp;
		res.push_back(temp);
	}
	return res;
}

ll _sieve_size;
bitset<33000> bs;
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

map<ll,ll> primeFactors(ll N){
	map<ll,ll> factors;
	ll PF_idx=0, PF=primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF==0){
			N/=PF; factors[PF]+=1;
		}
		PF=primes[++PF_idx];
	}
	if(N!=1) factors[N]+=1;
	return factors;
}

int main(){
	ios::sync_with_stdio(false);
	sieve(32800);
	
	char line[10000];
	int x;
	while(gets(line), line[0]!='0'){
		vi vec = splitstrip(line,' ');
		x=1;
		for(int i=0; i<vec.size(); i+=2) x*=pow(vec[i], vec[i+1]);
		x--;
		cout<<x<<endl;
		map<ll,ll> vecPF = primeFactors(x);
		
		map<ll,ll>::reverse_iterator rit=vecPF.rbegin();
		cout<<rit->first<<" "<<rit->second; rit++;
		for(; rit!=vecPF.rend(); rit++) cout<<" "<<rit->first<<" "<<rit->second;
		cout<<endl;
	}
	return 0;
}

