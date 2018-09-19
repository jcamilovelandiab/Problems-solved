#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<int> vi;

class SegmentTree{
    private:
        vi st, arr;
        int n;

    int left(int p){ return (p<<1);} //parent p
    int right(int p){ return (p<<1)+1; }

    private: void build(int p, int low, int high){
        if(low==high){ st[p]=1; return;}
        int mid=(low+high)>>1;
        build(left(p), low, mid);
        build(right(p), mid+1, high);
        st[p]=st[left(p)]+st[right(p)];
    }

    public: SegmentTree(const int _n){
        n=_n; arr.clear();
        FOR(i, n) arr.push_back(i+1);
        st.assign(3*n,0);
        build(1, 0, n-1);
        
    }

    public: void printST(){
        cout<<"ST:";
        loop(i,1,2*n) cout<<" "<<st[i];
        cout<<endl;
    }

    public: int pop(int q){
        int element=-1, ind=0, p=1, low=0, high=n-1; vi path;
        while(low<=high){
            path.push_back(p); //printf("q:%d, p:%d, low:%d, high:%d\n",q,p,low,high);
            if(low==high){
                //cout<<"ELEMENT: "<<p<<" "<<n<<endl;
                element=arr[low]; break;
            }else{
                int mid = (low+high)>>1;
                if(q<st[left(p)]){
                    high=mid; p=left(p); //cout<<"LEFT"<<endl;
                }else{
                    low=mid+1; q=q-st[left(p)]; p=right(p);//cout<<"RIGHT"<<endl;
                }
            }
        }
        FOR(i,path.size()) st[path[i]]-=1;
        return element;
    }
};

int main(){
    int tc, K, query; cin>>tc;
    while(tc--){
        cin>>K;
        SegmentTree st(K); //st.printST();
        FOR(i,K){
            cin>>query; cout<<st.pop(query);
            //st.printST();
            if(i!=K-1) cout<<" ";
            else cout<<endl;
            //st.printST();
        }
    }
    return 0;
}
/*
5
3
2 1 0
3
1 0 0
4
2 1 1 0
4
1 2 1 0
7
2 4 4 1 0 1 0
*/
