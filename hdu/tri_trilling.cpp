#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;

    int dp[31];
    //dp[0]=1;
    // dp[1]=0;  // if i%2==1  0
    // dp[2]=3;


    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(int i=4;i<31;i++){

        dp[i]=4*dp[i-2]-dp[i-4];

    }

    int ans=0;
    while(scanf("%d",&n)){
        if(n==-1) break;

        printf("%d\n",dp[n]);

    }
    return 0;
}
