#include <bits/stdc++.h>

using namespace std;

typedef vector<char*> vs;
typedef vector<double> vd;

vd splitstrip(char* s, char c1, char c2){
	int i, tok=1, sp=0;
	vs l;
	for(i=0; s[i]; i++){
		if(s[i]==c1 || s[i]==c2) tok=1, s[sp]=0;
		else if(s[i]!=' '){
			sp=i+1;
			if(tok) l.push_back(s+i), tok=0;
		}
		else if(s[sp]!=' ') sp=i;
	}
	if(i>0 && s[i-1]=='\n') s[i-1]=0;
	vd vec;
	for(int i=0; i<l.size(); i++){
		stringstream strValue; strValue << l[i];
		double temp; strValue>>temp;
		vec.push_back(temp);
	}
	return vec;
}

int main(){
	double time, timeQ, distance=0.0,h,m,s,speed, answer=0.0;
	h=m=s=speed=timeQ=0.0;
	
	char line[100], temp[100];
	while(gets(line)){
		strcpy(temp, line);
		vd vec = splitstrip(line,':', ' ');
		h=vec[0], m=vec[1], s=vec[2];
		time=h; time+= m/60.0; time+= s/3600.0;
		//cout<<(time-timeQ)*speed<<endl;
		distance+=(time-timeQ)*speed;
		if(vec.size()==4){
			speed=vec[3];
		}else{
			printf("%s %.2lf km\n", temp, distance);
		}
		timeQ=h; timeQ+= m/60.0; timeQ+= s/3600.0;
	}
	return 0;
}
