#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=1005;

int g[maxn][maxn];

int n,m;
int q;
int sx,sy;// start x,y
int ex,ey;//end x ,y
int dir[4][2]={0,1,0,-1,1,0,-1,0};// r,l,d,u

//
bool visited[maxn][maxn];

struct Node{
    int x;
    int y;
    int flag;
    int t;
};


bool bfs(){

    Node p;
    p.x=sx;
    p.y=sy;
    p.flag=-1;
    p.t=0;

   queue<Node> pq;
   pq.push(p);

   visited[sx][sy]=true;

   Node now;

   int xx;
   int yy;
   Node next;
   while(!pq.empty()){

        now=pq.front();
        pq.pop();


        for(int i=0;i<4;i++){

            int xx=now.x+dir[i][0];
            int yy=now.y+dir[i][1];

            next.x=xx;
            next.y=yy;
            next.flag=i;
            next.t=(i==now.flag?now.t:now.t+1);
            if(next.t>3)continue;
            if(xx==ex&&yy==ey&&next.t<=3) return true;

            if(xx>n||xx<1||yy>m||yy<1||g[xx][yy]!=0) continue;

            if(!visited[xx][yy]){
                pq.push(next);
                visited[xx][yy]=true;
            }
        }
   }

}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){

        if(n==0&&m==0) break;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                scanf("%d",&g[i][j]);
            }
        }

        scanf("%d",&q);
        // q query
        for(int i=0;i<q;i++){

            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            memset(visited,false,sizeof(visited));
            // handle

            // first judge
            if(g[sx][sy]!=g[ex][ey]||g[sx][sy]==0&&g[ex][ey]==0){

                printf("NO\n");
                continue;
            }

            if(bfs()){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }

    }
    return 0;
}
