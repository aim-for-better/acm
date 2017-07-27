#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

#define MAX 105

double nodex1[MAX],nodey1[MAX];
double nodex2[MAX],nodey2[MAX];


int main()
{
    int n;
    int ans;
    double x1,x2,y1,y2;
    while(cin>>n){

        if(n==0)break;

        ans=0;
        for(int i=0;i<n;i++){

            scanf("%lf%lf%lf%lf",&nodex1[i],&nodey1[i],&nodex2[i],&nodey2[i]);

        }
        // serach
        for(int i=0;i<n-1;i++){

            for(int j=i+1;j<n;j++){

                //rectangel charge

                if(!(max(nodex1[i],nodex2[i])>=min(nodex1[j],nodex2[j])&&
                     min(nodex1[i],nodex2[i])<=max(nodex1[j],nodex2[j])&&
                     max(nodey1[i],nodey2[i])>=min(nodey1[j],nodey2[j])&&
                     min(nodey1[i],nodey2[i])<=max(nodey1[j],nodey2[j])
                     ))
                   continue;

                x1=nodex2[i]-nodex1[i];
                y1=nodey2[i]-nodey1[i];

                x2=nodex2[j]-nodex1[i];
                y2=nodey2[j]-nodey1[i];

                double tem1=x2*y1-x1*y2;

                x2=nodex1[j]-nodex1[i];
                y2=nodey1[j]-nodey1[i];
                double tem2=x2*y1-x1*y2;

                //

                x1=nodex2[j]-nodex1[j];
                y1=nodey2[j]-nodey1[j];

                x2=nodex2[i]-nodex1[j];
                y2=nodey2[i]-nodey1[j];
                double tem3=x2*y1-x1*y2;

                x2=nodex1[i]-nodex1[j];
                y2=nodey1[i]-nodey1[j];
                double tem4=x2*y1-x1*y2;

                if(tem1*tem2<=0&&tem3*tem4<=0)ans++;
            }
        }

        cout<<ans<<endl;

    }



    return 0;
}
