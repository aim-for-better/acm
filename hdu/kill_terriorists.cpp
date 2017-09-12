#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<char,int> score;
const int maxn=3000;
int dp[maxn][maxn];


int LCS(char s[],char t[]){

    int n=strlen(s);

    int m=strlen(t);

    for(int i=1;i<=m;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    dp[0][0]=0;

    int ans=0;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+score[s[i-1]];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{

    int n;
    string s;
    int tmp;
    char b[maxn];//bullet
    char t[maxn]; //terroists;
    while(scanf("%d",&n)!=EOF){
        cin>>s;
        for(int i=0;i<n;i++){
           scanf("%d",&tmp) ;
            score[s[i]]=tmp;
        }
        scanf("%s%s",b,t);
        int ans=0;
        ans=LCS(b,t);
        printf("%d\n",ans);
    }
    return 0;
}
