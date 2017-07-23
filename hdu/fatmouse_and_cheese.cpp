#include <iostream>
#include<cstdio>

#include<cstring>
using namespace std;

#define MAX 105
int n,k;


int g[MAX][MAX];


int dp[MAX][MAX]; //dp[i][j] stands for in (i,j) the num of mouse get


int dir[4][2]={0,1,0,-1,1,0,-1,0};// r,l,d,u

int total=0;
int dfs(int x,int y){

    int mx=0;

    int temp=0;
    // dp[x][y] >0 means the x,y has been visited and the result has
    // store in dp[x][y]
    if(dp[x][y]>0)return dp[x][y];

    for(int i=0;i<4;i++){

        for(int j=1;j<=k;j++){

            int xx=x+dir[i][0]*j;
            int yy=y+dir[i][1]*j;


            if(xx<0||xx>=n||yy<0||yy>=n||g[xx][yy]<=g[x][y]) continue;

            temp=dfs(xx,yy);

            if(mx<temp){
                mx=temp;
            }
        }
    }

    dp[x][y]=mx+g[x][y];
    return dp[x][y];
}


int main()
{
    while(cin>>n>>k){


        if(n==-1&&k==-1) break;
        memset(g,0,sizeof(g));

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

        total=dfs(0,0);

        cout<<total<<endl;
    }

    return 0;
}
