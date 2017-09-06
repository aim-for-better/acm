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

int dp[maxn][maxn];

bool visited[maxn][maxn];

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

    memset(dis,INF,sizeof(dis));

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

        printf("the x is: %d  the y is %d\n",x,y);
        for(int i=0;i<4;i++){

            xx=x+dir[i][0];
            yy=y+dir[i][1];

            if(xx>=n||xx<0||yy>=m||yy<0||g[xx][yy]=='#') continue;

            if(xx==ex&&yy==ey){
                if(g[x][y]=='x') dis[xx][yy]=2+now.step;
                else dis[x][yy]= 1+now.step;
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

int dfs(int x,int y){

    if(x==ex&&y==ey) {
        dp[x][y]=0;
        return dp[x][y];
    }

   // if(dp[x][y]>-1) return dp[x][y]; // if have visited

    printf("the x is : %d  the y is: %d\n ",x,y);
    int ans=0;
    int mm=INF;
    for(int i=0;i<4;i++){

        int xx=x+dir[i][0];
        int yy=y+dir[i][1];

        if(xx>=n||xx<0||yy>=m||yy<0||g[xx][yy]=='#'||visited[xx][yy]) continue;

        //

        printf("the xx is : %d  the yy is: %d\n",xx,yy);

        if(xx==ex&&yy==ey) ans=0;
        else{
            visited[xx][yy]=true;
           ans=dfs(xx,yy);
        }

        visited[xx][yy]=false;
        if(ans<mm) mm=ans;
    }
    if(dp[x][y]=='x') dp[x][y]=2+mm;
    else dp[x][y]=1+mm;

    printf("the  dp[%d][%d] is  %d\n",x,y,dp[x][y]);
    return dp[x][y];

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
        memset(visited,false,sizeof(visited));
        memset(dp,-1,sizeof(dp));
        //dfs
        visited[sx][sy]=true;

       // dfs(sx,sy);
       // printf("%d\n",dp[sx][sy]);
        int ans=0;
        ans=bfs(sx,sy);
        printf("%d\n",ans);
    }
    return 0;
}
