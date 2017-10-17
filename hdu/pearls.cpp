#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=110;
const int INF=0x3fffffff;

int a[maxn];
int p[maxn];

int sum[maxn];
int dp[maxn];  //dp[i] means buy all buy i category
int main()
{
    int T;
    scanf("%d",&T);

    int c;
    while(T--){

        scanf("%d",&c);

        sum[0]=0;
        dp[0]=0;
        //usually the in dp ,the index is start from 1
        for(int i=1;i<=c;i++){
            scanf("%d%d",&a[i],&p[i]);


            sum[i]=sum[i-1]+a[i];

            dp[i]=(sum[i]+10)*p[i];
        }


        for(int i=1;i<=c;i++){

            for(int j=1;j<=i;j++){

                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j]+10)*p[i]);
            }
        }


        printf("%d\n",dp[c]);



    }
    return 0;
}
