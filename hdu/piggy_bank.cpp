#include <iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>


#define MAX 505
using namespace std;
const int INF=5000000;

int T;
int E,F;
int N;

int p[MAX];
int w[MAX];
int ans=0;
int dp[10005];

int MIN(int a,int b){

    return a<b?a:b;
}
int main()
{

    scanf("%d",&T);

    while(T--){

        scanf("%d%d",&E,&F);


        scanf("%d",&N);

        for(int i=0;i<N;i++){

            scanf("%d%d",&p[i],&w[i]);
        }
        //

        int v=F-E;
        for(int i=1;i<=v;i++){
            dp[i]=INF;
        }


        dp[0]=0;

        for(int i=0;i<N;i++){

            for(int j=w[i];j<=v;j++){
                dp[j]=MIN(dp[j-w[i]]+p[i],dp[j]);
            }

        }

        if(dp[v]==INF){
            printf("This is impossible.\n");

        }else{
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
        }


    }

    return 0;
}
