#include <bits/stdc++.h>
#define x first
#define y second
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

ii start;

int main(){
    int N;
    ii u,v;
    bool firstC=false;
    cin>>N;
    while(N--){

        cin>>start.first>>start.second;
        string line;
        cin.ignore();
        double time=0.0;

        while(getline(cin,line), line!=""){
            stringstream ss; ss.str(line);
            ss>>u.x>>u.y>>v.x>>v.y;
            //cout<<u.x<<","<<u.y<<" - "<<v.x<<","<<v.y<<endl;
            time+=sqrt(pow(u.x-v.x,2)+pow(u.y-v.y,2))*2;
        }
        if(firstC) puts("");
        if(!firstC) firstC=true;
        int t = round((time*60)/(1000*20));
        printf("%d:%02d\n", t/60, t%60);
    }
    return 0;
}
/*
2

0 0
0 0 10000 10000
5000 -10000 5000 10000
5000 10000 10000 10000

0 0
0 0 10000 10000
5000 -10000 5000 10000
5000 10000 10000 10000
*/
