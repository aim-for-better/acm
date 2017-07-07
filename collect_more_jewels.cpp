#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int t;
int w,h,l,m;
int sx,sy; //start x, y
int ex,ey; // end x,y
char a[52][52];
bool bfsvisit[52][52];
int jewel[60];

bool dfsvisit[60];
int dist[52][52];
int step[52][52];
int dmx=0;  // default max
int dir[4][2]={0,1,0,-1,1,0,-1,0}; //r,l,d,u

int fic=0; //final cost
int ABS(int x){
    return x>0?x:-x;
}

int manhanton(int x,int y){

     return ABS(ex-x)+ABS(ey-y);

}
//calculated from  x,y  to other point dist ,store the result in dist[pos][n]
// pos is the number of @ or A-J or <
void bfs(int x,int y,int pos){

    queue<int> q;

    memset(bfsvisit,false,sizeof(bfsvisit));
    //sequence position
    int sp=x*w+y;

    q.push(sp);

    bfsvisit[x][y]=true;
    step[x][y]=0;
    while(!q.empty()){

        int tmp=q.front();
        q.pop();


        int tx=tmp/w;
        int ty=tmp%w;


        for(int i=0;i<4;i++){

            int nx=tx+dir[i][0];
            int ny=ty+dir[i][1];

            if(nx<0||nx>=h||ny<0||ny>=w)continue;

            if(bfsvisit[nx][ny]||a[nx][ny]=='*')continue;

            bfsvisit[nx][ny]=true;
            step[nx][ny]=step[tx][ty]+1;
            if(a[nx][ny]=='@'){
                dist[pos][0]=step[nx][ny];
            }else if(a[nx][ny]=='<'){
                dist[pos][m+1]=step[nx][ny];
            }else if(a[nx][ny]>='A'&&a[nx][ny]<='J'){
                dist[pos][a[nx][ny]-'A'+1]=step[nx][ny];
            }

            q.push(nx*w+ny);

        }
    }

}

void dfs(int pos,int cost ,int rl){

    if(fic>=dmx) return ;

    if(rl<0) return ;

    if(pos==m+1){

        fic=fic<cost?cost:fic;
    }
    dfsvisit[pos]=true;
    for(int i=0;i<=m+1;i++){

        if(dist[pos][i]==0||dfsvisit[i])continue;
         dfsvisit[i]=true;
        dfs(i,cost+jewel[i],rl-dist[pos][i]);
        dfsvisit[i]=false;
    }

}


int main()
{

        int cnt=0;
        cin>>t;
        for(int k=0;k<t;k++){



            memset(dist,0,sizeof(dist));
            memset(dfsvisit,0,sizeof(dfsvisit));
            fic=0;

            char c;
            dmx=0;
            cin>>w>>h>>l>>m;

            // jewel store the value of jewel
            // 0 means @ m+1 mean <, other A-J=[1-60];
            jewel[0]=0;
            jewel[m+1]=0;
            for(int i=1;i<=m;i++){

                cin>>jewel[i];
                dmx+=jewel[i];
            }


            for(int i=0;i<h;i++){

                for(int j=0;j<w;j++){

                    cin>>c;
                    if(c=='@') sx=i,sy=j;
                    else if(c=='<') ex=i,ey=j;
                    a[i][j]=c;
                }
            }
            for(int i=0;i<h;i++){

                for(int j=0;j<w;j++){

                    c= a[i][j];
                    if(c=='@') sx=i,sy=j,bfs(i,j,0);
                    else if(c=='<') ex=i,ey=j,bfs(i,j,m+1);
                    else if(c>='A'&&c<='J') bfs(i,j,c-'A'+1);

                }
            }


            printf("Case %d:\n",k+1);

            dfs(0,0,l);
            if(fic!=0){


               printf("The best score is %d.\n",fic);
            }else{
               printf("Impossible\n");
            }
            if(k!=t-1){

                printf("\n");
            }
        }
    return 0;
}
