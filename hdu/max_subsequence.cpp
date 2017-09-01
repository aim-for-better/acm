#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=10005;

int dp[maxn];  //dp[i] menas the max sum of sequence end with i

int s[maxn];  // s[i] remember the start index i of the sequence stands by  dp[i]


int a[maxn];
int main()
{
   int k;
   while(scanf("%d",&k)!=EOF){

        if(k==0) break;
        int m=0;
        for(int i=1;i<=k;i++){

            scanf("%d",&a[i]);
            if(a[i]<0)m++;
        }

        if(m==k){

            printf("0 %d %d\n",a[1],a[k]);
            continue;
        }

        dp[1]=a[1];
        int mx=dp[1];
        for(int i=2;i<=k;i++){

            if(dp[i-1]>0){
                dp[i]=dp[i-1]+a[i];
                s[i]=s[i-1];
            }else{
                dp[i]=a[i];
                s[i]=i;
            }
        }
        int start=1,e=1;
        for(int i=2;i<=k;i++){

            if(dp[i]>mx){
                mx=dp[i];
                e=i;
                start=s[i];
            }
        }

        printf("%d %d %d\n",mx,a[start],a[e]);
   }
    return 0;
}
