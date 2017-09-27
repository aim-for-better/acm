#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=505;

vector<int> g[maxn];

int indegree[maxn];
int mark[maxn][maxn];
vector<int> ans;
void TopSort(int n){

    ans.clear();
    while(ans.size()<n){

        for(int j=1;j<=n;j++){

            if(indegree[j]==0){

                ans.push_back(j);
                if(ans.size()==n) break;
                indegree[j]=-100;
                int len=g[j].size();
                for(int k=0;k<len;k++){

                    indegree[g[j][k]]--;
                }
                //here is important  because need ensure that the index is smaller is at front
                break;
            }
        }
    }
}

int main()
{
    int n,m;
    int a,b;

    //init
    while(scanf("%d%d",&n,&m)!=EOF){

        memset(mark,0,sizeof(mark));
        for(int i=0;i<maxn;i++)g[i].clear();
        memset(indegree,0,sizeof(indegree));

        for(int i=0;i<m;i++){

            scanf("%d%d",&a,&b);
            if(!mark[a][b]){
                mark[a][b]=1;
                g[a].push_back(b);
                indegree[b]++;
            }
        }

       TopSort(n);

        printf("%d",ans[0]);
        int len=ans.size();
        for(int i=1;i<len;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
