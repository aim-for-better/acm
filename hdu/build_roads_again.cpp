#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3fffffff;
const int maxn=105;
int d[maxn][maxn];
bool visited[maxn];

int n;

vector<int> spt;
vector<int> g[maxn];

int SPT(int start){

    spt.clear();
    spt.push_back(start);
    visited[start]=true;
    int ans=0;
    int next=0;
    while(true){

        int len=spt.size();
        if(len==n) break;

        int mm=INF;
        int index=0;

        for(int i=0;i<len;i++){

            int cnt=g[spt[i]].size();

            for(int j=0;j<cnt;j++){

                next=g[spt[i]][j];

                if(!visited[next]){

                    if(d[spt[i]][next]<mm){

                        mm=d[spt[i]][next];
                        index=next;
                    }
                }
            }
        }

        spt.push_back(index);
        ans+=mm;
        visited[index]=true;

    }
    return ans;
}

int main()
{
    int m=0;
    int f,t,w;
    while(scanf("%d",&n)!=EOF){

        if(n==0)break;

        memset(d,INF,sizeof(d));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<maxn;i++) g[i].clear();

        m=n*(n-1)/2;

        for(int i=1;i<=m;i++){

            scanf("%d%d%d",&f,&t,&w);
            d[f][t]=w;
            d[t][f]=w;
            g[f].push_back(t);
            g[t].push_back(f);

        }
        int ans=0;
        ans=SPT(1);
        printf("%d\n",ans);
    }
    return 0;
}
