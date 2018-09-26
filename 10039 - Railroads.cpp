#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXC 110
#define MAXT 1010
#define minPerDay 1441
#define x first
#define y second
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int nCities, nTrains, srcCity, tgtCity, startTime, dp[MAXC][minPerDay];

vector<vii> graph(MAXC);
vector<vii> train(MAXT);

map<string,int> mpCity;

int hourToMin(int hours){ return (int)(hours/100)*60+hours%100; }
int minToHour(int mins){ return (mins/60)*100+mins%60; }


int f(int city, int time){

    if(city==srcCity){
        if(time>=startTime) return dp[city][time]=time;
        return -1;
    }

    if(dp[city][time]!=-1) return dp[city][time];

    FOR(i, graph[city].size()){
        int trn=graph[city][i].x, stop=graph[city][i].y;
        int t=train[trn][stop].x;
        if(t>time) continue;
        FOR(j, stop){
            ii v = train[trn][j];
            int nextTime=v.x, nextCity=v.y;
            /*cout<<"Time:"<<nextTime<<", City:"<<nextCity<<endl;
            string line; getline(cin,line);*/
            dp[city][t]=max(dp[city][t], f(nextCity, nextTime));
            //cout<<"CITY:"<<city<<", t:"<<minToHour(t)<<" - nextCity:"<<nextCity<<", nextTime:"<<minToHour(nextTime)<<" DP:"<<minToHour(dp[city][t])<<endl;
            //string line; getline(cin,line);
        }
        dp[city][time]=max(dp[city][time], dp[city][t]);
    }
    return dp[city][time];
}

int main(){
    string city, src, tgt;
    int cases, nStops; cin>>cases;
    FOR(tc,cases){
        cin>>nCities;
        mpCity.clear();
        FOR(i,nCities){
            cin>>city; mpCity[city]=i;
            graph[i].clear();
        }

        cin>>nTrains; FOR(i, nTrains) train[i].clear();
        FOR(i,nTrains){
            cin>>nStops;
            FOR(j,nStops){
                int hour, iCity; cin>>hour>>city;
                iCity=mpCity[city];
                train[i].push_back(ii(hourToMin(hour), iCity));
                graph[iCity].push_back(ii(i,j)); //tren y numero de parada
            }
        }

        cin>>startTime; startTime=hourToMin(startTime);
        cin>>src>>tgt;
        srcCity=mpCity[src]; tgtCity=mpCity[tgt];

        //cout<<"HEY"<<endl;
        memset(dp, -1, sizeof dp);
        //cout<<hourToMin(2400)<<endl;
        //cout<<srcCity<<" -> "<<tgtCity<<endl;
        f(tgtCity, hourToMin(2400));
        //cout<<"HEY F"<<endl;
        //cout<<minToHour(dp[2][hourToMin(1411)])<<endl;
        int bestStart=-1, bestEnd=INF;
        FOR(i, graph[tgtCity].size()){
            int trn=graph[tgtCity][i].x, stop=graph[tgtCity][i].y;
            int t=train[trn][stop].x;
            if(dp[tgtCity][t]==-1) continue;

            if(t<bestEnd){
                bestEnd=t; bestStart=dp[tgtCity][t];
            }else if(t==bestEnd && bestStart<dp[tgtCity][t]){
                bestStart=dp[tgtCity][t]; bestEnd=t;
            }
        }
        cout<<"Scenario "<<tc+1<<endl;
        if(bestEnd!=INF){
            cout<<"Departure "<<setfill('0')<<setw(4)<<minToHour(bestStart)<<" "<<src<<endl;
            cout<<"Arrival   "<<setfill('0')<<setw(4)<<minToHour(bestEnd)<<" "<<tgt<<endl;
        }else{
            cout<<"No connection"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
