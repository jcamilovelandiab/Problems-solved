#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct car{
    int L;
    int H;
    string name;
    car() : L(0), H(0), name("") {}
    car(string _name, int _L, int _H) : name(_name), L(_L), H(_H) {}
};

bool compareCars(car a, car b){
    if(a.H==b.H){
        return a.L<b.L;
    }
    return a.H>b.H;
}

int main(){
    int tcs, D,H,L,P, Q, cnt, i, carIndex;
    string name;
    car database[10005];
    cin>>tcs;
    for(int tc=0; tc<tcs; tc++){
        cin>>D;
        for(i=0; i<D; i++){
            cin>>name>>L>>H;
            database[i]=car(name, L, H);
        }
        //sort(database, database+D, compareCars);
        cin>>Q;
        if(tc!=0) cout<<endl;
        while(Q--){
            cnt=0;
            cin>>P;
            for(i=0; i<D; i++){
                if(database[i].L<=P && P<=database[i].H){
                    carIndex=i;
                    cnt++;
                }
                if(cnt>=2) break;
            }
            if(cnt>=2 || cnt==0) cout<<"UNDETERMINED"<<endl;
            else cout<<database[carIndex].name<<endl;
        }
    }
    return 0;
}
