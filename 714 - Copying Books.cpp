#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long m, k, cont, low, high, suma;
vector<long long> books(550);

bool indices[550];

int check(long long val){
	memset(indices,0, sizeof(indices));
	int cont=0;
	for(int i=m-1; i>=0;){
		long long sum=0;
		while(i>=0 && sum + books[i]<=val){
			sum+=books[i]; i--;
		}
		if(sum==0) return k+1;
		cont++;
		indices[i]=1;
	}
	return cont;
}

long long binary(){
	low=1, high=suma; 
    while(low<high){
        int mid=(low+high)/2;
        if(check(mid)<=k){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return high;
}

int main(){
    //freopen("in.txt","r",stdin);
    int i,j, N;
    cin>>N;
    while(N--){
        cin>>m>>k;
        suma=0;
        loop(i,0,m){
            cin>>books[i];
            suma+=books[i];
        }
        int cont=check(binary());
        for(int i=0;i<m && cont<k; i++){
        	if(!indices[i]){
        		indices[i]=1, cont++;
			}
		}
		loop(i,0,m){
			if(i) printf(" %d", books[i]);
			else printf("%d",books[i]);
			if(indices[i]) printf(" /");
		}
		puts("");
    }
    return 0;
}
