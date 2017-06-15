#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int n,m;

char a[100][100];
bool visited[100][100];
int dire[4][2]={1,0,-1,0,0,1,0,-1}; //down,up,right,left
int tmin=0x7fffffff;


typedef struct node {

    int x;
    int y;

    int cost;
    int flag;
   // priority_queue low is low priority so ,convert the <
   // if cost <other.cost  then cost priority > other
   // so ,
    bool operator<(const node& other)const{

        return other.cost<cost;
    }

};
node loc[100][100];

void bfs(){

    priority_queue<node> pq;
    node start;
    start.x=0;
    start.y=0;
    start.cost=0;
    start.flag=-1;


    loc[0][0]=start;


    pq.push(start);


    node next;
    while(!pq.empty()){



        start=pq.top();
        pq.pop();
        if(start.x==n-1&&start.y==m-1){
            return ;
        }
        for(int i=0;i<4;i++){

            next.x=start.x+dire[i][0];
            next.y=start.y+dire[i][1];

            if(next.x<0||next.x>=n||next.y<0||next.y>=m||visited[next.x][next.y])continue;


            visited[next.x][next.y]=true;
            next.flag=i+1;
            next.cost=start.cost+1;
            if(a[next.x][next.y]!='.'){
                next.cost+=a[next.x][next.y]-48;
            }
            loc[next.x][next.y]=next;
            pq.push(next);
        }
    }

}

void show(node now){



    if(now.x==0&&now.y==0){

        return ;
    }


    int tmp=now.flag-1;
    int px=now.x-dire[tmp][0];
    int py=now.y-dire[tmp][1];
    node pre=loc[px][py];

    show(pre);



    printf("%ds:(%d,%d)->(%d,%d)\n",pre.cost+1,pre.x,pre.y,now.x,now.y);

    if(now.cost-pre.cost>1){

        for(int i=2;i<=now.cost-pre.cost;i++){


            printf("%ds:FIGHT AT (%d,%d)\n",pre.cost+i,now.x,now.y);
        }
    }

    return ;

}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        memset(visited,false,sizeof(visited));
        visited[0][0]=true;
        memset(loc,0,sizeof(loc));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

               cin>>a[i][j];
               loc[i][j].cost=0x7fffffff;
               if(a[i][j]=='X')
                    visited[i][j]=true;
            }

        }

        //handle

        bfs();
        if(!visited[n-1][m-1]){


            printf("God please help our poor hero.\nFINISH\n");

        continue ;
        }else{

            printf("It takes %d seconds to reach the target position, let me show you the way.\n",loc[n-1][m-1].cost);
            //print

            show(loc[n-1][m-1]);
            printf("FINISH\n");
        }

    }
    return 0;
}
