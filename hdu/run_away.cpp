#include <iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;


const int INF =1<<31-1;
const int maxn=1005;

const double eps=1e-3;

const double pi=acos(-1.0);

int X,Y,m;
double x[maxn];
double y[maxn];

double a[maxn];
double b[maxn];
double best[maxn];

double Rand(double l,double r){

    return (rand()%10000)/10000.0*(r-l)+l;

}
double dist(double x1,double y1,double x2,double y2){

    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}
int main()
{
    int t;
    cin>>t;
    while(t--){

        cin>>X>>Y>>m;

        for(int i=0;i<m;i++){

            cin>>x[i]>>y[i];
        }
        srand(time(0));

        for(int i=0;i<30;i++){

            a[i]=Rand(1,X);
            b[i]=Rand(1,Y);
            best[i]=INF;

            for(int j=0;j<m;j++){

                best[i]=min(best[i],dist(a[i],b[i],x[j],y[j]));
            }
        }

        double step=max(X,Y);

        while(step>eps){

            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++){

                    double angle=Rand(0,2*pi);
                    double x1=a[i]+cos(angle)*step;
                    double y1=b[i]+sin(angle)*step;
                    if(x1<0||y1<0||x1>X||y1>Y)continue;

                    double dis=INF;

                    for(int k=0;k<m;k++){
                        dis=min(dis,dist(x1,y1,x[k],y[k]));

                    }
                    if(dis>best[i]){
                        best[i]=dis;
                        a[i]=x1;
                        b[i]=y1;
                    }

                }
            }
        step*=0.85;
        }

        int t=1;
        for(int i=1;i<30;i++){

            if(best[i]>best[t]){
                t=i;
            }
        }

        printf("The safest point is (%.1lf, %.1lf).\n", a[t], b[t]);
    }



    return 0;
}
