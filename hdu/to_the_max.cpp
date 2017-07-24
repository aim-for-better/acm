#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 105

int dp[MAX];

int a[MAX][MAX];


int main()
{

    int n;
    int mx;
    int sum;
    while(scanf("%d",&n)!=EOF){


        sum=0;
        mx=-100000;

        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }

        //handle

        for(int i=0;i<n;i++){

            memset(dp,0,sizeof(dp));

            for(int j=i;j<n;j++){


                //
                for(int k=0;k<n;k++){

                    dp[k]+=a[j][k];
                }
                // find the largest max sequence sum

                // init
                sum=0;

                for(int k=0;k<n;k++){

                    if(sum<0){

                        sum=dp[k];
                    }else{
                        sum+=dp[k];
                    }
                    //sum=sum<0?dp[k]:sum+dp[k];
                    if(sum>mx)mx=sum;
                }

            }
        }

        cout<<mx<<endl;
    }
    return 0;
}
