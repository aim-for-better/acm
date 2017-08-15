#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=15;

const int INF=((1<<31)-1)/2;

int n;

int h,s,f; // hire ,salary ,fire;

int month[maxn];

int dp[maxn][200];

int  total=0;
int personMax=0;
int dfs(int index,int sum){


    if(index==n) return 0;

    //remember search  dfs+dp
    if(dp[index][sum]!=-1) return dp[index][sum];

    int ans=0;

    // need hire
    if(sum<=month[index]){

        ans=dfs(index+1,month[index])+(month[index]-sum)*h+month[index]*s;
    }else{
        //need fire some
         ans=INF;

        for(int j=month[index];j<=sum;j++){

            ans=min(ans,dfs(index+1,j)+(sum-j)*f+j*s);
        }

    }

    dp[index][sum]=ans;
    return dp[index][sum];
}

int  DP(){

    // Init

    for(int i=month[0];i<=personMax;i++){
        dp[0][i]=i*(h+s);
    }

    for(int i=1;i<n;i++){

        for(int j=month[i];j<=personMax;j++){

            int mm=INF;
            for(int k=month[i-1];k<=personMax;k++){

                int cost=0;
                if(k<=j){
                    cost=(j-k)*h+j*s;
                }else{
                    // need fire

                    cost=(k-j)*f+j*s;
                }

                mm=min(mm,dp[i-1][k]+cost);
            }

            dp[i][j]=mm;
        }
    }

    int ans=INF;
    for(int i=month[n-1];i<=personMax;i++){

        if(dp[n-1][i]<ans){

            ans=dp[n-1][i];
        }
    }

    return ans;
}

int main()
{
   while(scanf("%d",&n)!=EOF&&n!=0){

        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&h,&s,&f);
        for(int i=0;i<n;i++){

            scanf("%d",&month[i]);
            if(month[i]>personMax){
                personMax=month[i];
            }
        }

        int ans=0;
      //  ans=dfs(0,0);

      ans=DP();
        printf("%d\n",ans);
   }
    return 0;
}
