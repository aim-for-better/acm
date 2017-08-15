#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=1024;

int dp[maxn][maxn];

int LCS(string a,string b){

    memset(dp,0,sizeof(dp));
    a=" "+a;
    b=" "+b;
    int n1=a.length();
    int n2=b.length();
    dp[0][0]=0;
    for(int i=1;i<n1;i++){


        for(int j=1;j<n2;j++){

            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{

                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

            }
        }
    }

    return dp[n1-1][n2-1];
}

int main()
{
    string a,b;

    while(cin>>a>>b){

        int ans=LCS(a,b);

        printf("%d\n",ans);
    }
    return 0;
}
