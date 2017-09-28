#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=30;

typedef long long LL;

LL f[maxn][maxn]; // f[i][j] means the i persons make up of  j groups  then f[i][j]=f[i-1][j-1]+f[i-1][j]*j


void DP(){

    memset(f,0,sizeof(f));

    f[1][1]=1;

    for(int i=2;i<=26;i++){

        for(int j=1;j<=26;j++){

            f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
        }
    }

}
int main()
{
    DP();
    int n;

    long long ans=0;
    int T;
    scanf("%d",&T);
    while(T--){

        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++){

            ans+=f[n][i];
        }

        printf("%I64d\n",ans);
    }
    return 0;
}
