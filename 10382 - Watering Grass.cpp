#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define EPS 1e-9

using namespace std;

struct segment{
	double left, right;
	bool operator<(const segment &other) const{
		if(fabs(left-other.left)>EPS) return left < other.left;
		return right > other.right;
	}
};

double startP, endP;
vector<segment> segs;

int intervalCovering(){
	int i=0, cnt=0;
	double upto=startP; //cover- start-end
	while(upto<endP){
		double mostRight=upto;
		for(; i<segs.size(); i++){
			if(segs[i].left > upto) break; // can't cover me
			if(segs[i].right > mostRight){ // right - farther
				mostRight=segs[i].right; // update right-farther
			}
		}
		if(fabs(upto-mostRight)<EPS) break; //didn't find any interval covering
		cnt++;
		upto=mostRight; // missing to be covered upto-end	
	}
	if(upto<endP) return -1; // didn't cover the all interval
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	double dx,  pos, r, l, w;
	while(cin>>n>>l>>w){
		segs.clear();
		startP=0.0; endP=l;
		while(n--){
			cin>>pos>>r;
			dx=r*r- 0.25*w*w;
			if(dx<0) continue;
			dx=sqrt(dx);
			segment s; s.left=pos-dx; s.right=pos+dx;
			segs.push_back(s);
		}
		sort(segs.begin(), segs.end());
		//FOR(i,segs.size()) cout<<segs[i].left<<" "<<segs[i].right<<endl;
		cout<<intervalCovering()<<endl;
	}
	return 0;
}
