#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

int N, cntB, cntP, cntFP, S, tempB, tempP;
char mat[100][100];

int dx[]={-1, 1, 0, 0};
int dy[]={ 0, 0,-1, 1};


void printMat(){
    puts("\n-- INICIO DE LA MATRIZ --");
    FOR(i,N) puts(mat[i]);
    puts("-- FIN DE LA MATRIZ --\n");
}

void ffB(int i, int j){
    mat[i][j]='+';
    FOR(k,4){
        int x=i+dx[k], y=j+dy[k];
        if(x<0 || x>=N || y<0 || y>=N || mat[x][y]!='B') continue;
        ffB(x, y);
    }
}

void ffP(int i, int j){
    mat[i][j]='+';
    FOR(k,4){
        int x=i+dx[k], y=j+dy[k];
        if(x<0 || x>=N || y<0 || y>=N || mat[x][y]!='P') continue;
        ffP(x, y);
    }
}

void ffBP(int i, int j){

    if(mat[i][j]=='B'){
        tempB+=1; ffB(i,j);
    }else if(mat[i][j]=='P'){
        tempP+=1; ffP(i,j);
    }else{ //mat[i][j]='+'
        mat[i][j]='*';
    }

    FOR(k,4){
        int x=i+dx[k], y=j+dy[k];
        if(x<0 || x>=N || y<0 || y>=N || mat[x][y]=='.' || mat[x][y]=='*') continue;
        ffBP(x, y);
    }
}


void ffS(int i,int j){

    if(mat[i][j]=='B' || mat[i][j]=='P'){
        tempP=0; tempB=0;
        ffBP(i, j);
        cntP+=tempP; cntB+=tempB;
        if(tempP>0 && tempB>0){
            cntFP+=tempP+tempB;
        }
    }else{
        mat[i][j]='.';
    }

    FOR(k,4){
        int x=i+dx[k], y=j+dy[k];
        if(x<0 || x>=N || y<0 || y>=N || mat[x][y]=='.') continue;
        ffS(x, y);
    }
}

int main(){
    while(scanf("%d",&N), N){
        getchar();
        FOR(i,N) gets(mat[i]);
        S=0; cntFP=0;
        FOR(i,N){
            FOR(j,N){
                if(mat[i][j]=='B' || mat[i][j]=='P' || mat[i][j]=='*'){
                    cntB=0; cntP=0; S+=1;
                    ffS(i, j);
                    printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", S, cntB, cntP);
                }
            }
        }
        printf("Total %d group(s) are in fighting position.\n\n", cntFP);
    }
    return 0;
}

/*
16
................
................
.******.........
.**PP**....***..
.******....*B*..
.******....***..
.**BB**.........
.******.........
................
.....*******....
....*BB**BB**...
....*BB**PP**...
....*********...
....****PP***...
.....*******....
................
5
BB*..
....*
*BPP.
.*PBB
..***
0
*/
