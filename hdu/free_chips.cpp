#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn=100005;

int dp[12][maxn];



int main()
{
    int x,t;
    int n;
    int mxt; //max time;
    while(scanf("%d",&n)!=EOF){

        if(n==0) break;
        mxt=0;
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&t);
            dp[x][t]++;
            if(t>mxt)mxt=t;
        }

        //dp

        for(int i=mxt;i>=0;i--){

            for(int j=0;j<11;j++){

                if(j==0){
                    dp[j][i]+=max(dp[j+1][i+1],dp[j][i+1]);
                }else{

                    dp[j][i]+=max(max(dp[j-1][i+1],dp[j+1][i+1]),dp[j][i+1]);
                }
            }
        }

        printf("%d\n",dp[5][0]);

    }
    return 0;
}
