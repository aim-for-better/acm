#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;




/*
**  dp programing
    consider the j-th num ,there are two case ,add j to the group ,or j is a alone group

    dp[i][j]=max(dp[i][j-1]+a[j],max(dp[i-1][k])+a[j])  0<k<j;

    the  result is the max dp[i][j]   1<=i<=m ,  1<=j<=n
**
*/
int arr[1000002];
int dp[1000002];
int preMax[1000002];

int max(int x,int y){

    return x>y?x:y;
}

int main()
{
    int n,m;


    while(scanf("%d%d",&m,&n)!=EOF){

        //init
        memset(dp,0,sizeof(dp));
        memset(preMax,0,sizeof(preMax));
        int result=-0x7fffffff;

        // the 0 is keep for use
        for(int i=1;i<=n;i++){

            scanf("%d",&arr[i]);
        }

        for(int i=1;i<=m;i++){

            //
             result=-0x7fffffff;

            for(int j=i;j<=n;j++){


                dp[j]=max(dp[j-1]+arr[j],preMax[j-1]+arr[j]);

                preMax[j-1]=result;

                result=max(dp[j],result);
            }
        }

        printf("%d\n",result);

    }

    return 0;
}
