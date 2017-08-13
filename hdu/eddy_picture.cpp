#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
const int maxn=105;

const double eps=1e-8;

const double INF=1<<30-1;
using namespace std;

struct Point{

    double x;
    double y;

};
Point point[maxn];
double Distance(Point a,Point b){
    double dist;

    dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return dist;
}
int n;

double dist[maxn][maxn];
bool visited[maxn];


double  prim(){
    vector<int> v;

    double ans=0;
    memset(visited,false,sizeof(visited));

    v.push_back(0);
    visited[0]=true;
    while(true){

        if(v.size()==n)break;

        int len=v.size();

        double mm=INF;
        int pre=0;
        int index=-1;
        for(int i=0;i<len;i++){
            for(int j=0;j<n;j++){

                if(j!=v[i]&&!visited[j]){

                    if(dist[v[i]][j]<mm){

                        mm=dist[v[i]][j];
                        pre=v[i];
                        index=j;

                    }
                }
            }
        }
        v.push_back(index);
        visited[index]=true;
        ans+=dist[pre][index];
    }

    return ans;

}
int main()
{

    while(scanf("%d",&n)!=EOF){

        for(int i=0;i<n;i++){

            scanf("%lf%lf",&point[i].x,&point[i].y);

            dist[i][i]=0;
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                dist[i][j]=Distance(point[i],point[j]);
                dist[j][i]=dist[i][j];
            }
        }

        //prim

        double ans=prim();
        printf("%.2lf\n",ans);
    }

    return 0;
}
