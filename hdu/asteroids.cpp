#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=15;
bool visited[maxn][maxn][maxn];
char g[maxn][maxn][maxn];

int dir[6][3]{
  1,0,0,
  -1,0,0,
  0,1,0,
  0,-1,0,
  0,0,1,
  0,0,-1
};
int n;
struct Point{
    int x,y,z;

    int step;
    Point(){
    }
    Point(int xx,int yy,int zz){
        x=xx;y=yy;z=zz;
        step=0;
    }

};
bool eq(Point a,Point b){

    if(a.x==b.x&&a.y==b.y&&a.z==b.z) return true;
    else return false;
}
int  BFS(int sx,int sy,int sz,int ex,int ey,int ez){

    Point start=Point(sx,sy,sz);
    start.step=0;
    Point ep=Point(ex,ey,ez);
    ep.step=0;
    int ans=0;

    if(eq(start,ep))return 0;

    queue<Point> q;
    while(!q.empty())q.pop();
    memset(visited,false,sizeof(visited));
    q.push(start);
    visited[sx][sy][sz]=true;
    Point now;
    Point next;
    int xx,yy,zz;
    while(!q.empty()){

        now=q.front();
        q.pop();
        for(int i=0;i<6;i++){

            xx=now.x+dir[i][0];
            yy=now.y+dir[i][1];
            zz=now.z+dir[i][2];

            if(xx==ex&&yy==ey&&ez==zz){
                return now.step+1;
            }
            if(visited[xx][yy][zz]||xx>=n||xx<0||yy>=n||yy<0||zz>=n||zz<0||g[zz][xx][yy]=='X')continue;

            next=Point(xx,yy,zz);
            visited[xx][yy][zz]=true;
            next.step=now.step+1;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    string s;
    int sx,sy,sz;
    int ex,ey,ez;
    while(cin>>s){

        if(s=="START"){


        }
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cin>>s;
                for(int k=0;k<n;k++){
                    g[i][j][k]=s[k];
                }
            }
        }
        scanf("%d%d%d",&sx,&sy,&sz);
        scanf("%d%d%d",&ex,&ey,&ez);
        cin>>s;
        int ans=0;
        ans=BFS(sx,sy,sz,ex,ey,ez);
        if(ans==-1)printf("NO ROUTE\n");
        else
            printf("%d %d\n",n,ans);


    }

    return 0;
}
