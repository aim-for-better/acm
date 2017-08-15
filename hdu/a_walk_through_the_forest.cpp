#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


const int maxn=1005;
const int  INF=((1<<31)-100)/2;
vector<int> g[maxn];
bool visited[maxn];
int dist[maxn][maxn];

int d[maxn];

int p[maxn];
int n;// number of intersections

int m;// number of path

int ans=0;  // the ans

int over=2;
void dijkstra(){

    int start=over;
    queue<int> q;
    q.push(start);
    for(int i=1;i<=n;i++){

        d[i]=INF;
        visited[i]=false;
    }
    d[start]=0;

    visited[start]=true;

    int now;
    int next;
    int len;

    while(!q.empty()){

        now=q.front();

        q.pop();

        len=g[now].size();


        for(int i=0;i<len;i++){

            next=g[now][i];

           if(d[next]>d[now]+dist[now][next]){


                d[next]=d[now]+dist[now][next];

                if(!visited[next]){

                    visited[next]=true;
                    q.push(next);
                }
           }

        }

        visited[now]=false;

    }

}


//need remember search

  // the array p[i] mean from node i has how many routes
int dfs(int start){


    //if has visited start and get the num of routes from node start  can get
    // then return ;
    if(p[start]) return p[start];


    //find over then find 1 route return
    if(start==over){
        return 1;
    }

     int len=g[start].size();


    int next;
    int sum=0;
    for(int i=0;i<len;i++){

        next=g[start][i];

     //   if(visited[next]) continue;

        if(d[start]>d[next]){

            if(p[next]) sum+=p[next];
            else{

                sum+=dfs(next);
            }
        }
    }

    p[start]=sum;

    return sum;
}


int main()
{

   while(scanf("%d",&n)){

        if(n==0) break;

        scanf("%d",&m);

        ans=0;

        //init
        for(int i=1;i<=n;i++){

            g[i].clear();
        }


        //init dist;
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){
                if(i==j)
                    dist[i][j]=0;
                else{

                    dist[i][j]=INF;
                    dist[j][i]=INF;
                }
            }
        }

        //input
        int a,b,d;  // a --b   is d distance
        for(int i=1;i<=m;i++){

            scanf("%d%d%d",&a,&b,&d);

            g[a].push_back(b);
            g[b].push_back(a);

            dist[a][b]=d;
            dist[b][a]=d;
        }

        //get the dijkstra distance

        dijkstra();

    // the array p[i] mean from node i has how many routes
        memset(p,0,sizeof(p));
       ans=dfs(1);

        printf("%d\n",ans);

   }


    return 0;
}
