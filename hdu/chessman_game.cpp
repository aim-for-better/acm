#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=10005;
int x[maxn];
int y[maxn];
int N,M,K;
int g[105][105];
bool visited[105];
int mark[105];

bool dfs(int u){

    for(int v=1;v<=M;v++){

        if(g[u][v]==1&&!visited[v]){

            visited[v]=true;

            if(mark[v]==-1||dfs(mark[v])){

                mark[v]=u;
                return true;
            }
        }
    }

    return false;
}
int hungary(){

    memset(mark,-1,sizeof(mark));
    int ans=0;
    for(int u=1;u<=N;u++){
        memset(visited,false,sizeof(visited));
        if(dfs(u))  ans++;
    }

    return ans;
}

int main()
{

    int cnt=0;
    while(scanf("%d%d%d",&N,&M,&K)!=EOF){

        cnt++;
        memset(g,0,sizeof(g));

        for(int i=0;i<K;i++){

            scanf("%d%d",&x[i],&y[i]);
            g[x[i]][y[i]]=1;
        }

        int total=hungary();

        int ans=0;
        int tmp;
        for(int i=0;i<K;i++){

            g[x[i]][y[i]]=0;
            tmp=hungary();
            g[x[i]][y[i]]=1;
            if(tmp<total) ans++;
        }

        printf("Board %d have %d important blanks for %d chessmen.\n",cnt,ans,total);
    }
    return 0;
}
