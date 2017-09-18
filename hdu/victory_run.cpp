#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=55;
int dir[6][3]={
1,0,0,
-1,0,0,
0,1,0,
0,-1,0,
0 ,0,1,
0,0,-1
};

struct Node{
    int x,y,z;
    int step=0;
    Node(){}
    Node(int xx,int yy,int zz){
        x=xx;
        y=yy;
        z=zz;
        step=0;
    }
};
int g[maxn][maxn][maxn];
bool visited[maxn][maxn][maxn];
int sx,sy,sz;
int ex,ey,ez;
queue<Node> q;
 int A,B,C;
int  bfs(){


    memset(visited,false,sizeof(visited));
    while(!q.empty()) q.pop();
   Node now=Node(sx,sy,sz);
   q.push(now);
   visited[sx][sy][sz]=true;
   Node next;
   int x,y,z;
   int xx,yy,zz;
   while(!q.empty()){

        now=q.front();
        q.pop();

        if(now.x==ex&&now.y==ey&&now.z==ez){

            return now.step;
        }

        for(int i=0;i<6;i++){

            xx=now.x+dir[i][0];
            yy=now.y+dir[i][1];
            zz=now.z+dir[i][2];

            if(xx>=A||xx<0||yy>=B||yy<0||zz>=C||zz<0||visited[xx][yy][zz]||g[xx][yy][zz]==1) continue;

            if(xx==ex&&yy==ey&&zz==ez) { return now.step+1;}

            next=Node(xx,yy,zz);

            next.step=now.step+1;
            visited[xx][yy][zz]=true;
            q.push(next);
        }
   }

   return -1;
}

int main()
{
    int K,T;

    scanf("%d",&K);
    while(K--){

        scanf("%d%d%d%d",&A,&B,&C,&T);

        memset(g,-1,sizeof(g));

        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                for(int k=0;k<C;k++){

                   scanf("%d",&g[i][j][k]) ;
                }
            }
        }

        int ans=0;
        sx=sy=sz=0;
        ex=A-1;
        ey=B-1;
        ez=C-1;
        ans=bfs();

        if(ans!=-1&&ans<=T) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
