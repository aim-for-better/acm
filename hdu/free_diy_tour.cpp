#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=105;
vector<int> g[maxn];  //the graph
int p[maxn];          // the points
int n;
int route[maxn];     //remember the route
int a[maxn];  // remember search


void showRoute(){

    int v=1;
    while(v!=route[v]){

        printf("%d->",v);
        v=route[v];
    }
}

int  dfs(int v){

    if(v==n+1){
        a[v]=0;
        route[v]=v;
        return 0;
    }

    if(a[v]>-1) return a[v];
    int mindex=-10000;
    int len=g[v].size();
    int next;
    int mx=-1000000;
    for(int i=0;i<len;i++){

        next=g[v][i];

        if(a[next]>-1){
          if(p[v]+a[next]>mx){

            mx=p[v]+a[next];
            mindex=next;
          }
        }
        else{
            if(p[v]+dfs(next)>mx){

                mx=p[v]+a[next];
               mindex=next;
            }
        }
    }
    a[v]=mx;
    route[v]=mindex;
    return a[v];
}


int main()
{
    int T;
    scanf("%d",&T);
    int m;
    int from,to;
    int t=T;
    while(T--){

        scanf("%d",&n);

        for(int i=1;i<=n;i++){

            scanf("%d",&p[i]);

            g[i].clear();
        }
        g[n+1].clear();
        p[n+1]=0;

        scanf("%d",&m);
        for(int i=0;i<m;i++){

            scanf("%d%d",&from,&to);

            g[from].push_back(to);
        }

        memset(a,-1,sizeof(a));
        memset(route,-1,sizeof(route));
        //dfs
        int ans=0;
        ans=dfs(1);

        printf("CASE %d#\n",t-T);
        printf("points : %d\n",ans);
        printf("circuit : ");
        showRoute();
        printf("1\n");
        if(T>0)printf("\n");
    }
    return 0;
}
