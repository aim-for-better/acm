#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=205;
const int INF=0x3fffffff;
char g[maxn][maxn];

//bool visited[maxn][maxn];

int dir[4][2]={1,0,-1,0,0,1,0,-1} ; // d,u,r,l
int n,m;
int sx,sy,ex,ey;
int dis[maxn][maxn];
struct Node{

    int x,y;
    int step;
    Node(){}

    Node(int xx,int yy){
        x=xx;
        y=yy;
        step=0;
    }
};


int bfs(int ssx,int ssy){

    Node tmp=Node(ssx,ssy);

    queue<Node>q ;
    while(!q.empty()) q.pop();

   for(int i=0;i<n;i++)for(int j=0;j<m;j++) dis[i][j]=INF;

    q.push(tmp);
    dis[ssx][ssy]=0;

    if(ssx==ex&&ssy==ey) return 0;

    Node now;
    Node next;
    int xx,yy;
    int x,y;
    while(!q.empty()){

        now=q.front();
        q.pop();
        x=now.x;
        y=now.y;
        for(int i=0;i<4;i++){

            xx=x+dir[i][0];
            yy=y+dir[i][1];
            if(xx>=n||xx<0||yy>=m||yy<0||g[xx][yy]=='#') continue;
            if(xx==ex&&yy==ey){
                if(g[x][y]=='x') dis[xx][yy]=2+now.step;
                else dis[xx][yy]= 1+now.step;
                continue;
            }

            next.x=xx;
            next.y=yy;
            if(g[x][y]=='x') next.step=2+now.step;
            else next.step=1+now.step;

            if(next.step<dis[xx][yy]){

                dis[xx][yy]=next.step;
                q.push(next);
            }
        }
    }

    return dis[ex][ey];
}


int main()
{
    string s;
    while(scanf("%d%d",&n,&m)!=EOF){


        for(int i=0;i<n;i++ ){

            cin>>s;
            for(int j=0;j<m;j++){
                g[i][j]=s[j];
                if(g[i][j]=='r') sx=i,sy=j;
                if(g[i][j]=='a') ex=i,ey=j;
            }
        }
       // dfs(sx,sy);
       // printf("%d\n",dp[sx][sy]);
        int ans=0;
        ans=bfs(sx,sy);
        if(ans==INF) printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
