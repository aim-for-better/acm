#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
bool g[maxn][maxn];

int main()
{

    //
    int x1,y1,x2,y2;

    int ans=0;
    memset(g,false,sizeof(g));
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)){

        if(x1==-1&&x1==y1&&x2==x1&&y2==x1){

            //output
            ans=0;
            for(int i=0;i<maxn;i++){

                for(int j=0;j<maxn;j++){
                    if(g[i][j])ans++;
                }
            }

             memset(g,false,sizeof(g));
            printf("%d\n",ans);
        }

        if(x1==-2&&y1==x1&&x2==x1&&y2==x1){

            ans=0;
            for(int i=0;i<maxn;i++){

                for(int j=0;j<maxn;j++){
                    if(g[i][j])ans++;
                }
            }
            break;
        }

        //flag the graph
        //make sure that x1<=x2,y1<=y2
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);

        for(int x=x1;x<x2;x++){

            for(int y=y1;y<y2;y++){

                g[x][y]=true;
            }
        }
    }

    return 0;
}
