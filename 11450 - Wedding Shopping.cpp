#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)



using namespace std;



int M,C, K,memo[205][25], prices[25][25];

int shop(int money, int garment){
	if(money<0) return INT_MIN; // no tengo dinero
	if(garment==C) return M-money; // ya compre las prendas que necesitaba
	if(memo[money][garment]!=-1) return memo[money][garment];
	
	int ans=INT_MIN;
	loop(model, 1, prices[garment][0]+1){
		ans=max(ans,shop(money-prices[garment][model],garment+1)); // compro el producto
	}
	return memo[money][garment]=ans;
}

int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&M, &C);
		
		loop(i,0,205) loop(j,0,25) memo[i][j]=-1;
		
		loop(i,0,C){
			scanf("%d",&prices[i][0]);
			loop(j,1,prices[i][0]+1) scanf("%d",&prices[i][j]);	
		}
		int ans=shop(M,0);
		if(ans<0) printf("no solution\n");
		else printf("%d\n",ans);
		
	}
	return 0;
}
