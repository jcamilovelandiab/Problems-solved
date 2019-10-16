#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int N;
        cin>>N;
        string s; cin>>s;
        int l=-1,r=-1;
        for(int i=0; i<N; i++){
            if(s[i]=='1'){
                l=i+1; break;
            }
        }
        for(int i=N-1; i>=0; i--){
            if(s[i]=='1'){
                r=i+1; break;
            }
        }
        if(l==-1 && r==-1) cout<<N<<endl;
        else if(l==1 && r==N) cout<<2*N<<endl;
        else if(l==r){
            cout<<max(l*2,max(N+1,(N-l+1)*2))<<endl;
        }else{
            int leftStart = max(l*2,max(N+1, r*2));
            int rightStart = max((N-l+1)*2, (N-r+1)*2);
            cout<<max(leftStart, rightStart)<<endl;
        }
    }
    return 0;
}
