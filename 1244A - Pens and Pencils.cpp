#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x=a/c;
        if(a%c!=0) x++;
        int y=b/d;
        if(b%d!=0) y++;
        if(x+y>k) cout<<-1<<endl;
        else cout<<x<<" "<<y<<endl;
    }
    return 0;
}
