#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3fffffff-1;
const int maxn=2005;
int a[maxn];
int d[maxn];
int dist[maxn];

int k;

//dp   dist[i]=min(dist[i-2]+d[i-2],dist[i-1]+a[i]) ,i=2,3,4,...k
int DP(){

    dist[0]=0;
    dist[1]=a[1];

    for(int i=2;i<=k;i++){

        dist[i]=min(dist[i-2]+d[i-2],dist[i-1]+a[i]);
    }

    return dist[k];
}

int main()
{
   int T;
   scanf("%d",&T);

   int total=0;
   int hh;
   int mm;
   int ss;
   int tmp;
   while(T--){
        hh=8;
        mm=ss=0;
        total=0;
        scanf("%d",&k);
        // build graph
        a[0]=0;
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }

       for(int i=0;i<k-1;i++){

            scanf("%d",&d[i]);
       }

       total= DP();

        hh+=total/3600;

        total=total%3600;

        mm=total/60;

        ss=total%60;

        printf("%02d:%02d:%02d ",hh,mm,ss);

        if(hh<12) printf("am\n");
        else printf("pm\n");

   }
    return 0;
}
