#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define pushb push_back
#define popb pop_back

using namespace std;

typedef vector<string> vs;

vector<vs> game;

bool match(string card, string otherCard){
	if(card[0]==otherCard[0]) return true;
	if(card[card.size()-1] == otherCard[otherCard.size()-1]) return true;
	return false;
}

void play(){	
	int i=1;
	while(i<game.size()){
		string card = game[i][game[i].size()-1], otherCard;
		if(i>=3){
			otherCard=game[i-3][game[i-3].size()-1];
			if(match(card, otherCard)){
				game[i-3].pushb(card);
				game[i].popb();
				if(game[i].size()==0){
					game.erase(game.begin()+i);
				}
				i-=3; continue;
			}
		}
		
		if(i>=1){
			otherCard=game[i-1][game[i-1].size()-1];
			if(match(card, otherCard)){
				game[i-1].pushb(card); game[i].popb();
				if(game[i].size()==0){
					game.erase(game.begin()+i);
				}
				i-=1; continue;
			}
		}
		i++;
	}
}

int main(){
	string card;
	while(cin>>card, card!="#"){
		game.clear();
		vs vec; vec.pushb(card);
		game.pushb(vec);
		loop(i,1,52){
			cin>>card; vec.clear(); vec.pushb(card);
			game.pushb(vec);
		}
		play();
		if(game.size()==1) cout<<"1 pile remaining:";
		else cout<<game.size()<<" piles remaining:";
		FOR(i,game.size()) cout<<" "<<game[i].size();
		cout<<endl;
	}
	return 0;
}
