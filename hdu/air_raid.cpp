#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;


const int maxn=125;

vector<int> g[maxn];

int n,k;

bool visited[maxn];

int matched[maxn];

bool dfs(int v){

    for(vector<int>::iterator it=g[v].begin();it!=g[v].end();it++){
        int w=*it;
        if(!visited[w]){

            visited[w]=true;

            if(matched[w]==-1||dfs(matched[w])){

                matched[w]=v;
                return true;
            }
        }
    }
    return false;
}


int hungarian(){

    // only 0 ,-1 can use memset
    // if the array is not char array(single byte)
    memset(matched,-1,sizeof(matched));
    int total=0;
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        if(dfs(i)) total++;
    }
    return total;
}



int main()
{
   int T;
   scanf("%d",&T);
   int ans=0;
   while(T--){

        scanf("%d%d",&n,&k);
        //init
        for(int i=1;i<=n;i++)g[i].clear();
        int s,e;
        for(int i=0;i<k;i++){

            scanf("%d%d",&s,&e);
            g[s].push_back(e);
        }
        ans=n-hungarian();

        printf("%d\n",ans);

   }


    return 0;
}
