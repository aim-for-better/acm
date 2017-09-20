#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=2005;

const int INF=30005;

int a[maxn];
int dp[maxn];
int main()
{
    int n;
    int ans=1;
    while(scanf("%d",&n)!=EOF){

      ans=1;
      a[0]=0;
      dp[0]=0;
      for(int i=1;i<=n;i++)   {

        dp[i]=1;
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++){

            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }

        if(dp[i]>ans) ans=dp[i];
      }
      printf("%d\n",ans);
    }
    return 0;
}
