#include <iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct{


int enemy;
int prop;
}Node;


Node room[103];

vector<int> conn[103];
int dp[103][103];// dp[i][j] store in the room i  ,cost  j soldiers  then get the prop
bool visited[103];
int n,m;

int max(int x,int y){

    return x>y?x:y;
}
void dfs(int start){



    int tmp=(room[start].enemy+19)/20;

    // notice if here m=0 and tmp=0,  for example room=(0,20) but m=0 the result is 0 not 20
    for(int i=tmp;i<=m;i++){

        //under room start  ,cost soldier that greater than tmp, will get the prop of room start
        dp[start][i]=room[start].prop;
    }
    visited[start]=true;

    for(int i=0;i<conn[start].size();i++){

        int next=conn[start][i];
        if(visited[next]){

            continue;
        }

        dfs(next);


        // dp box algorithm (bei bao)

        for(int j=m;j>=tmp;j--){

            //has cost tmp soldier
            for(int k=1;k<=(j-tmp);k++){

                dp[start][j]=max(dp[start][j-k]+dp[next][k],dp[start][j]);

            }
        }
    }


}

int main()
{



    while(scanf("%d%d",&n,&m)){


        if(n==m&&n==-1)
            break;

        for(int i=0;i<=n;i++){

            conn[i].clear();
        }
        memset(dp,0,sizeof(dp));
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++){

            scanf("%d%d",&room[i].enemy,&room[i].prop);

        }
        int j=0,k=0;
        for(int i=0;i<n-1;i++){


            scanf("%d%d",&j,&k);
            conn[j].push_back(k);
            conn[k].push_back(j);
        }

        // handle input

        // here is import if m==0, then althrough a room has 0 bug ,but 20 prop  but should 0
        if(m==0){

            cout<<0<<endl;
            continue;
        }

        dfs(1);


        cout<<dp[1][m]<<endl;
    }
    return 0;
}
