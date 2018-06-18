#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<double,double> dd;

bool operator<(dd a, dd b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}

double cross(dd o, dd a, dd b){
	return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

vector<dd> montoneChain(vector<dd> P){
	int n=P.size(), k=0; vector<dd> H(2*n);
	sort(P.begin(), P.end());
	for(int i=0; i<n; i++){
		while(k>=2 && cross(H[k-2], H[k-1], P[i]) <=0) k--;
		H[k++]=P[i];
	}
	for(int i=n-2, t=k+1; i>=0; i--){
		while(k>=t && cross(H[k-2], H[k-1], P[i]) <=0) k--;
		H[k++]=P[i];
	}
	H.resize(k);
	return H;
}

double dist(dd p1, dd p2){
    return hypot(p1.x-p2.x, p1.y-p2.y); }

double perimeter(const vector<dd> &P){
    double result=0.0;
    for(int i=0; i<(int)P.size()-1; i++){
        result+=dist(P[i], P[i+1]);
    }
    return result;
}

int main(){
    int sides, cases=1;
    double x,y;
    while(scanf("%d",&sides), sides){
        vector<dd> poly;
        while(sides--){
            scanf("%lf %lf",&x, &y); poly.push_back(dd(x,y));
        }

        vector<dd> ch = montoneChain(poly);

        if(cases>1) puts("");
        printf("Region #%d:\n", cases++);
        int n = ch.size();

        printf("(%.1lf,%.1lf)", ch[n-1].x, ch[n-1].y);
        for(int i=n-2; i>=0; i--){
            printf("-(%.1lf,%.1lf)", ch[i].x, ch[i].y);
        }
        printf("\nPerimeter length = %.2lf\n", perimeter(ch));
    }
    return 0;
}
