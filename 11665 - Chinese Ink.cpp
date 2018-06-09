#include <bits/stdc++.h>
#define NEXT(i) (((i)+1)%n)
#define pushb push_back
#define popb pop_back
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

/* --- DISJOINT SETS ---*/

int Parent[50], Rank[50];

void init(int nodos){
    FOR(x,nodos+1){
        Parent[x]=x;
        Rank[x]=0;
    }
}

int findParent(int x){
    if(x!=Parent[x]) Parent[x]=findParent(Parent[x]);
    return Parent[x];
}

int Union(int x,int y){
    int rootX=findParent(x), rootY=findParent(y);
    if(rootX==rootY) return 0; //same parent
    if(Rank[rootX]>Rank[rootY]){
        Rank[x]+=Rank[y];
        Parent[rootY]=rootX;
    }else{
        Rank[rootY]+=Rank[rootX];
        Parent[rootX]=rootY;
    }
    return 1;
}

/* ---- GEOMETRY ---- */

typedef complex<double> point;
typedef vector<point> polygon;

struct segment{ point p,q; };

enum {OUT, ON, IN};

double dot(point a, point b){   return real(conj(a)*b); }
double cross(point a, point b){ return imag(conj(a)*b); }

int ccw(point a, point b, point c){
    b-=a; c-=a;
    if(cross(b,c)>0) return 1; //counter clockwise
    if(cross(b,c)<0) return -1; //clockwise
    if(dot(b,c)<0) return 2; // c--a--b on line
}

int contains(const polygon &poly, const point &p){
    bool in=false; int n = poly.size();
    FOR(i,n){
        point a = poly[i]-p, b=poly[NEXT(i)]-p;
        if(imag(a)>imag(b)) swap(a,b);
        if(imag(a)<=0 && 0<imag(b))
            if(cross(a,b)<0) in=!in;
        if(cross(a,b)==0 && dot(a,b)<=0) return ON;
    }
    return in ? IN:OUT;
}

bool intersectSS(const segment &s, const segment &t){
    return ccw(s.p, s.q, t.p)*ccw(s.p, s.q, t.q)<=0
        && ccw(t.p, t.q, s.p)*ccw(t.p, t.q, s.q)<=0;
}

int main(){
    ios::sync_with_stdio(false);
    int N;
    double x, y;
    string line;

    vector<polygon> ps;
    while(cin>>N, N){
        cin.ignore();
        ps.clear();

        FOR(i,N){
            getline(cin,line);
            stringstream ss(line);
            polygon poly;
            while(ss>>x>>y) poly.pushb(point(x,y));
            Parent[i]=i; Rank[i]=0;
            ps.pushb(poly);
        }

        int ans=N;
        FOR(i,N){
            FOR(j, N){
                if(i==j || findParent(i)==findParent(j)) continue;
                // POINT INSIDE POLYGON
                FOR(k, ps[j].size()){
                    int res = contains(ps[i], ps[j][k]);
                    if(res==IN || res==ON){ // point in or on polygon
                        //cout<<"SE INTERSECARON: "<<i<<", "<<j<<endl;
                        ans-=Union(i,j); break;
                    }
                }
                bool keepOn=true;
                FOR(a,ps[i].size()) if(keepOn){
                    FOR(b, ps[j].size()) if(keepOn){
                        segment s; s.p=ps[i][a]; s.q=ps[i][(a+1)%ps[i].size()];
                        segment t; t.p=ps[j][b]; t.q=ps[j][(b+1)%ps[j].size()];
                        if(intersectSS(s,t)){
                            ans-=Union(i,j); keepOn=false; break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
