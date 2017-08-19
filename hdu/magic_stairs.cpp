#include <iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

const int maxn=25;

char g[maxn][maxn];

bool visited[maxn][maxn];

int dir[4][2]={0,1,0,-1,1,0,-1,0}; // r,l,d,u
int n,m;

int sx,sy;
int ex,ey;

struct status{

    int x,y;
    int step;
    status(int x,int y,int step):x(x),y(y),step(step){}
};

status change(status pre,int dir, char c,int step){

    if(step%2)
        c=(c=='|'?'-':'|');


     if(c=='|'){

       if(dir==2) return status(pre.x+1,pre.y,0);
       if(dir==3) return status(pre.x-1,pre.y,0);
       else return status(-1,-1,0);

     }else if(c=='-'){
        if(dir==0) return status(pre.x,pre.y+1,0);
        if(dir==1) return status(pre.x,pre.y-1,0);
        else return status(-1,-1,0);

     }
}
int bfs(){


    memset(visited,false,sizeof(visited));

    queue<status> q;
    while(!q.empty()) q.pop();
    q.push(status(sx,sy,0));
    visited[sx][sy]=true;

    int xx,yy;
    while(!q.empty()){

         status now=q.front();
         q.pop();

        for(int i=0;i<4;i++){
            xx=now.x+dir[i][0];
            yy=now.y+dir[i][1];

            //out of range
            if(xx>=m||xx<0||yy>=n||yy<0||visited[xx][yy]||g[xx][yy]=='*')continue;
            //if find the target
            if(xx==ex&&yy==ey){
                return now.step+1;
            }

            if(g[xx][yy]=='|'||g[xx][yy]=='-'){
                // the import is the step is now.step
               status next=change(status(xx,yy,0),i,g[xx][yy],now.step);
               xx=next.x;
               yy=next.y;
            }
             if(xx>=m||xx<0||yy>=n||yy<0||visited[xx][yy]||g[xx][yy]=='*')continue;

            if(xx==ex&&yy==ey) return now.step+1;

            q.push(status(xx,yy,now.step+1));
            visited[xx][yy]=true;
        }
        q.push(status(now.x,now.y,now.step+1));
    }
    return 0;
}


int main()
{

    string s;
    while(scanf("%d%d",&m,&n)!=EOF){

        //m rows ,n columns

        sx=sy=-1;
        ex=ey=-1;

        for(int i=0;i<m;i++){

           scanf("%s",g[i]);

         //  printf("%s\n",g[i]);
            for(int j=0;j<n;j++){
                if(g[i][j]=='S'){
                    sx=i;
                    sy=j;
                }else if(g[i][j]=='T'){
                    ex=i;
                    ey=j;
                }
            }
        }

        if(m*n<2||sx==-1||ex==-1){
            printf("0\n");
            continue;
        }
        int ans=0;
        ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
