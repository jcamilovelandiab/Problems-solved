#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<string> vs;

map<int,int> boards;
typedef pair<int,int> ii;

int boardToInt(vs board){
    int k, n=0;
    for(int i=4; i>=0; i--){
        for(int j=4; j>=0; j--){
            n = (n<<1);
            if(board[i][j]==' '){
                k = i*5 + j;
            }else{
                n|=((board[i][j]=='1')? 1: 0);
            }
        }
    }
    // 1bit->signo_1bit->sobrante_5bits->posicion de casilla vacia_ 25bits->matriz
    // matriz -> r4__r3_ r2_r1
    n|= (k<<25);
    return n;
}

int dx[]={-1,-2,-2,-1, 1, 2, 2, 1};
int dy[]={-2,-1, 1, 2, 2, 1,-1,-2};

void printNumber(int n){
    bitset<32> bs(n);
    cout<<bs<<endl;
}

void solve(){
    vs board(5);
    board[0]="11111";
    board[1]="01111";
    board[2]="00 11";
    board[3]="00001";
    board[4]="00000"; //tablero inicial
    int root = boardToInt(board); boards[root]=0; //printNumber(root);

    queue<ii> q; q.push(ii(root,0)); boards[root]=0;
    while(!q.empty()){
        int u = q.front().first, level = q.front().second; q.pop();
        //cout<<"LEVEL: "<<level<<endl;
        loop(k,0,8){
            int pos = (u>>25);
            int i = pos/5, j = pos%5;
            int x = i+dx[k], y = j+dy[k];
            if(x<0 || x>=5 || y<0 || y>=5) continue;
            int v = ~(31<<25) & u; //printNumber(v);
            int bxy = (v>>(x*5+y)) &1; //printNumber(bxy);
            int temp = (bxy<<(i*5+j)) ^ v; //printNumber(temp);
            pos = (x*5+y)<<25; //printNumber(pos);
            v = temp | pos; //printNumber(v);
            v = (~(1<<(x*5+y))&v); //printNumber(v);

            if(boards.find(v)!=boards.end()) continue;

            boards[v]=level+1;

            if(level+1<=9) q.push(ii(v,level+1));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int tc;
    solve();
    cin>>tc; cin.ignore();
    while(tc--){
        vs board(5); FOR(i,5) getline(cin,board[i]);
        int u = boardToInt(board);
        if(boards.find(u)==boards.end()) cout<<"Unsolvable in less than 11 move(s)."<<endl;
        else cout<<"Solvable in "<<boards[u]<<" move(s)."<<endl;
    }
    return 0;
}
/*
5
01011
110 1
01110
01010
00100
10110
01 11
10111
01001
00000
111 1
01111
00111
00001
00000
11111
0 111
00111
00001
00000
11111
00111
00111
 0001
00000
*/

