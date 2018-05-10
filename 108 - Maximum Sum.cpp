#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b;i++)

using namespace std;

int matrix[105][105];

int main(){
	int n;
	while(scanf("%d",&n)==1){
		loop(i,0,n){
			loop(j,0,n){
				scanf("%d",&matrix[i][j]);
				/* MAX 2D RANGE SUM */
				if(i>0) matrix[i][j]+=matrix[i-1][j]; // add from top
				if(j>0) matrix[i][j]+=matrix[i][j-1]; // add from left
				if(i>0 && j>0) matrix[i][j]-=matrix[i-1][j-1];
			}
		}
		int maxSubRect=-1270000, subRect;
		loop(i,0,n){
			loop(j,0,n){
				loop(k,i,n){
					loop(l,j,n){
						subRect=matrix[k][l];
						if(i>0) subRect-=matrix[i-1][l]; // subtract cumulate from top
						if(j>0) subRect-=matrix[k][j-1]; // subtract cumulate from left
						if(i>0 && j>0) subRect+=matrix[i-1][j-1]; //inclusion-exclusion
						maxSubRect=max(maxSubRect,subRect);
					}
				}
			}
		}
		printf("%d\n",maxSubRect);		
	}
	return 0;
}
