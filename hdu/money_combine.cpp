#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=32800;

long long sum(long long  x,long long y){

    long long ans=x+y;

    return ans;
}
long long dp[maxn];

void init(){
    dp[0]=1;
        for(int i=1;i<=3;i++){

            for(int j=i;j<maxn;j++)
            {

                dp[j]=sum(dp[j],dp[j-i]);
            }
        }
}

/*
    mother function


*/
void mf(){

   int a[maxn];
   int b[maxn];
for(int i=0;i<maxn;i++) a[i]=1,b[i]=0;
   for(int i=2;i<=3;i++){
        for(int j=0;j<maxn;j++){
            for(int k=0;j+k<maxn;k+=i){
                b[j+k]+=a[j];
            }
        }
        for(int j=0;j<maxn;j++){

            a[j]=b[j];
            b[j]=0;
        }
   }
}
int main()
{
   int n;
   init();


   while(scanf("%d",&n)!=EOF){
        printf("%d\n",dp[n]);


   }
    return 0;
}
