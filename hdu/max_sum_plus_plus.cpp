#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=1005;
int a[maxn];
int b[25];
int dp[25][maxn];
int n,m;

int seg(int s,int e){

    int ans=0;
    for(int i=s;i<=e;i++) ans+=a[i];
    return ans;
}

int lowbit(int n){
    return n&(-n);
}

int c[maxn];

void init(){

    int k=0;
    c[0]=0;
    for(int i=1;i<=n;i++){
        c[i]=0;
        if(i%2==1)c[i]=a[i];
        else{
            k=lowbit(i);
            for(int j=i-k+1;j<=i;j++)c[i]+=a[j];
        }
    }
}

int sum(int n){

    int ans=0;
    while(n>0){

        ans+=c[n];
        n-=lowbit(n);
    }
    return ans;
}
void change(int i,int x){
    while(i<=n){

        c[i]+=x;
        i+=lowbit(i);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){

        if(n==0)break;

        scanf("%d",&m);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);

        init();
        //init
        for(int i=0;i<=n;i++)
            dp[0][i]=0;

        //dp[i][j] stands for  the i-th segment end with j
        int d=0;
        for(int i=1;i<=m;i++){
            d+=b[i];
            for(int j=d-b[i];j<=n;j++){


                for(int k=j-b[i];k>=1;k--){

                    dp[i][j]=max(dp[i-1][j],dp[i-1][k]+(sum(j)-sum(j-b[i])));
                }

            }
        }

        printf("%d\n",dp[m][n]);
    }
    return 0;
}
