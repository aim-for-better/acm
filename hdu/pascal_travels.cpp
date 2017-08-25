#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn=40;

int n;
int sx,sy;
int ex,ey;

int g[maxn][maxn];
LL num[maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};//d,u,r,l;
bool visited[maxn][maxn];
LL total=0;
int   dfs(int x, int y){

    if(num[x][y]) return num[x][y];


    if(x==ex&&y==ey) return 1;

    LL sum=0;
    for(int i=0;i<4;i++){

        int xx=x+dir[i][0]*g[x][y];
        int yy=y+dir[i][1]*g[x][y];

        if(xx>=n||xx<0||yy>=n||yy<0) continue;

        //

        //
        if(num[xx][yy]) sum+=num[xx][yy];
        else{



            return sum+dfs(xx,yy);
        }

    }

    return sum;
}

int main()
{
    string s;
    while(scanf("%d",&n)!=EOF){

        if(n==-1)break;
        total=0;

        for(int i=0;i<n;i++){

            cin>>s;
            for(int j=0;j<n;j++){

                g[i][j]=s[j]-'0';
            }
        }
        //
        memset(visited,false,sizeof(visited));
        visited[0][0]=true;
        sx=sy=0;
        ex=ey=n-1;
        LL ans=0;
        memset(num,0,num);
        total=dfs(sx,sy);

        printf("%lld\n",total);

    }
    return 0;
}
