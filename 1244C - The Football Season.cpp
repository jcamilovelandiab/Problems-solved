#include <bits/stdc++.h>

/**
    @author Juan Camilo Velandia Botello
**/

typedef long long ll;
using namespace std;

int main(){
    ll n,p,w,d;
    while(cin>>n>>p>>w>>d){
        if(p==0){ //perdi todos los partidos
            cout<<0<<" "<<0<<" "<<n<<endl;
        }else if(w*n<p){ //no puedo obtener todos los puntos
            cout<<-1<<endl;
        }else{ //p>=w*n ,i.e n>=p/w;
            ll x,y, z=0;
            bool flag=false;
            for(ll y=0; y<=1000000; y++){ // y=0 to w-1 according to some explanation, but I don't know why. So, I put 1'000.000 => 1seg time limit
                x=(p-y*d)/w; z=n-x-y;
                //cout<<x<<" "<<y<<endl;
                if(x>=0 && y>=0 && z>=0 && x*w+y*d==p && x+y+z==n){
                    cout<<x<<" "<<y<<" "<<z<<endl;
                    flag=true;
                    break;
                }
            }
            if(!flag) cout<<-1<<endl;
        }
    }
    return 0;
}
