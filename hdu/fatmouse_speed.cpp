#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn=1005;

struct Mouse{

    int w;
    int speed;
    int id;

    bool operator<(Mouse b){
        //sort by w asc and speed des
        if(w<b.w)return true;
        else if(w==b.w){
            return speed>b.speed;
        }else{
            return false;
        }
    }
};

Mouse mice[maxn];
int dp[maxn];// dp[i] means the max num if mice[i] is add in the sequence after

int cnt=0;

int pre[maxn];

int res[maxn];

void DP(){

    int mm=0;
    int maxleni=1;  // default is 1 the start
    for(int i=1;i<=cnt;i++){

        //j  must start from 1
        for(int j=1;j<i;j++){

            if(mice[i].w>mice[j].w&&mice[i].speed<mice[j].speed&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                pre[i]=j;
                if(dp[i]>mm){

                    mm=dp[i];
                    maxleni=i;
                }
            }
        }
    }
    //

    int i=0;
    int t=maxleni;
    while(t!=0){

        res[i++]=t;
        t=pre[t];
    }

    printf("%d\n",i);

    while(i>0){

        i--;

        printf("%d\n",mice[res[i]].id);

    }
}



int main()
{
    int a,b;
    cnt=0;
    while(scanf("%d%d",&a,&b)!=EOF){
        cnt++;
        mice[cnt].w=a;
        mice[cnt].speed=b;
        mice[cnt].id=cnt;
        dp[cnt]=1;
        pre[cnt]=0;

    }
    sort(mice+1,mice+cnt+1);


    DP();
    return 0;
}
