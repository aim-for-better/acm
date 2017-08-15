#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn=105;

bool visited[maxn];

int matched[maxn];

vector<int> g[maxn];
int n,m,k;


bool dfs(int v){

    for(vector<int>::iterator it=g[v].begin();it!=g[v].end();it++){


        if(!visited[*it]){

            visited[*it]=true;

            if(matched[*it]==-1||dfs(matched[*it])){


                matched[*it]=v;
                return true;
            }
        }
    }
    return false;

}


int hungarian(){

    int num=0;
    for(int i=1;i<=m;i++){

        matched[i]=-1;
    }
    for(int i=1;i<=n;i++){

        memset(visited,false,sizeof(visited));

        if(dfs(i))num++;

    }

    return num;

}


int main()
{

    int tmp;
    int ans;
    while(scanf("%d",&n)){
        if(n==0)break;

        scanf("%d%d",&m,&k);
        int a,b;

        for(int i=1;i<=n;i++) g[i].clear();

        for(int i=0;i<k;i++){

            scanf("%d",&tmp);//useless
            scanf("%d%d",&a,&b);
            if(a==0&&b==0) continue;
            g[a].push_back(b);


        }


        ans=hungarian();

        printf("%d\n",ans);;
    }
    return 0;
}
