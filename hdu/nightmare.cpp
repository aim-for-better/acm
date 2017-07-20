#include <iostream>
#include<queue>
#include<cstdio>
#include<cstring>


using namespace std;

#define MAX 10

int g[MAX][MAX];

bool visited[MAX*MAX][MAX];

int t;
int n,m;

int dir[4][2]={0,1,0,-1,1,0,-1,0}; //r,l,d,u

struct Node{

    int pos;

    int step,time;

    Node(int p,int st,int t){

        pos=p;
        step=st;
        time=t;
    }
};

bool  bfs(int pos){

    queue<Node> q;

    //pos step time
    Node start=Node(pos,0,6);
    q.push(start);

    visited[pos][6]=true;
    while(!q.empty()){

        Node node=q.front();

        q.pop();

        int p=node.pos;

        int x=p/m;
        int y=p%m;

        for(int i=0;i<4;i++){


            int xx=x+dir[i][0];
            int yy=y+dir[i][1];

            if(xx<0||xx>=n||yy<0||yy>=m||g[xx][yy]==0)continue;

            int np=xx*m+yy; //next p
            int tt=0; //tmp time
            int tsp=0;

            if(node.time<=1)continue; // if node time <=1 then can not get out of of reset time

            if(g[xx][yy]==4){

                tt=6;
            }else{
                tt=node.time-1;
            }
            if(visited[np][tt])continue;

            visited[np][tt]=true;

            tsp=node.step+1;

            if(g[xx][yy]==3){
                cout<<tsp<<endl;
                return true;
            }


            q.push(Node(np,tsp,tt));

        }
    }
    return false;
}


int main()
{
    scanf("%d",&t);
    while(t--){

        memset(g,-1,sizeof(g));

        memset(visited,false,sizeof(visited));

        scanf("%d%d",&n,&m);

        int sx,sy;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%d",&g[i][j]);
                if(g[i][j]==2) sx=i,sy=j;

            }
        }
        //
        bool flag=bfs(sx*m+sy);
        if(!flag){

            cout<<-1<<endl;
        }
    }
    return 0;
}
