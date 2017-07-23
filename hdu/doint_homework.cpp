#include <iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 105
#define INF  1000000
typedef struct Node{

    char name[MAX];

    int cost;
    int deadline;
}Lesson;


Lesson homework[20];

#define  mx 1<<15


int dp[mx];
int p[mx];
int ti[mx];


void showTrace(int n){

    if(p[n]==-1)return;

    showTrace(n^(1<<p[n]));
    cout<<homework[p[n]].name<<endl;
}
int main()
{

   int t;
   scanf("%d",&t);

   int n=0;
   while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        scanf("%s%d%d",homework[i].name,
              &homework[i].deadline,&homework[i].cost);
    }
    memset(dp,1000000,sizeof(dp));
    memset(p,-1,sizeof(p));
    dp[0]=0;
    p[0]=-1;
    ti[0]=0;
    int m=1<<n;
    for(int i=1;i<m;i++){

        for(int j=n-1;j>=0;j--){

            int tmp=(1<<j);
            //whether is the i contains j
            if((i&tmp)==0) continue;
            // get the pre status which add j is i
            int pre=i^tmp;

            //pre is the status before j,
            // the i is the status contains j
            int reduce=ti[pre]+homework[j].cost-homework[j].deadline;

            reduce=reduce<0?0:reduce;


            // the status change function
            // dp[i]= min{dp[pre]+ cost[j]}
            // where pre is the status which add j is i
            if(dp[pre]+reduce<dp[i]){

                dp[i]=dp[pre]+reduce;
                p[i]=j;
                ti[i]=ti[pre]+homework[j].cost;
            }
        }
    }

    printf("%d\n",dp[m-1]);

    showTrace(m-1);

   }
    return 0;
}
