#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=215;
const int INF=0x3fffffff;
int dp[35][maxn];
int d[maxn];

int cost(int i,int j){
    int mid=(i+j)/2;
    int ans=0;
    for(int k=i;k<=j;k++){

        ans+=abs(d[mid]-d[k]);
    }
    return ans;
}
int main()
{
    int n,k;
    int cnt=0;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==0&&k==0) break;
        cnt++;
        for(int i=1;i<=n;i++){

            scanf("%d",&d[i]);
        }
       for(int i=1;i<=n;i++) dp[1][i]=cost(1,i);

       for(int i=2;i<=k;i++){  // the i depot
            for(int j=1;j<=n;j++){  // the j num rest
                dp[i][j]=INF;
                for(int h=i-1;h<=j-1;h++)
                    dp[i][j]=min(dp[i][j],dp[i-1][h]+cost(h+1,j));
            }
       }
        printf("Chain %d\n",cnt);
        printf("Total distance sum = %d\n",dp[k][n]);

    }
    return 0;
}
