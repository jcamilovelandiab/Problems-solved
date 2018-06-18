#include <bits/stdc++.h>
#define EPS 1e-09

using namespace std;

struct point{ double x,y;
    point(){ x=y=0.0; }
    point(double _x, double _y) : x(_x),y(_y){}
    bool operator == (point other)const{
        return (fabs(x-other.x)<EPS && (fabs(y-other.y)<EPS));
    }
};

double dist(point p1, point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y); }

struct vec{ double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}  };

vec toVec(point a, point b){
    return vec(b.x-a.x, b.y-a.y); }

double cross(vec a, vec b){ return a.x*b.y - a.y*b.x; }

double ccw(point p, point q, point r){
    return cross(toVec(p,q), toVec(q,r)) >0; }

bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p,q), toVec(p,r)))<EPS;
}


// ------------ INTERSECT   -----------

// ------------ CONVEX HULL ------------
point pivot(0,0);

bool angleCmp(point a, point b){
    if(collinear(pivot, a, b)){
        return dist(pivot,a)<dist(pivot,b);
    }
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x)-atan2(d2y,d2x))<0;
}

vector<point> CH(vector<point> P){
    int i,j,n=(int)P.size();
    if(n<=3){
        if(!(P[0]==P[n-1])) P.push_back(P[0]);
        return P;
    }
    int PO=0;
    for(i=1; i<n; i++){
        if(P[i].y<P[PO].y || (P[i].y==P[PO].y && P[i].x>P[PO].x))
            PO=i;
    }
    swap(P[0], P[PO]);
    pivot=P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i=2;
    while(i<n){
        j=(int)S.size()-1;
        if(ccw(S[j-1], S[j], P[i]))S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}

double perimeter(const vector<point> &P){
    double result=0.0;
    for(int i=0; i<(int)P.size()-1; i++){
        result+=dist(P[i], P[i+1]);
    }
    return result;
}

int main(){
	//freopen("in218.txt","r",stdin);
    int sides, cases=1;
    double x,y;
    while(scanf("%d",&sides), sides){
        vector<point> poly;
        while(sides--){
            scanf("%lf %lf",&x, &y); poly.push_back(point(x,y));
        }
        pivot = poly[0]; sort(++poly.begin(), poly.end(), angleCmp); // sort by counter-clockwise, this is important
        vector<point> ch = CH(poly);

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
