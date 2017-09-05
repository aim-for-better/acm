#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn=105;

char g[maxn][maxn];

int a[maxn*maxn];
int h[maxn*maxn];

int dir[4][2]={1,0,0,1,1,1,1,-1}; //d,r,rd,ld
int Find(int p){

    if(a[p]==p) return p;

    a[p]=Find(a[p]);
    return a[p];
}
void UN(int p,int q){

    p=Find(p);
    q=Find(q);

    if(p!=q){

        if(h[p]<h[q]){

            a[q]=a[p];
            h[p]+=h[q];
        }else{

            a[p]=a[q];
            h[q]+=h[p];
        }
    }
}
int main()
{
    int n,m;
    string s;
    int xx,yy;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m==0) break;


        memset(a,-1,sizeof(a));
        for(int i=0;i<m;i++){


            cin>>s;
            for(int j=0;j<n;j++){

                g[i][j]=s[j];
                if(g[i][j]=='@'){
                    a[i*n+j]=i*n+j;
                }
            }
        }

        //init
        for(int i=0;i<m*n;i++){
            h[i]=1;
        }

        //handle

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(g[i][j]=='@'){

                    for(int k=0;k<4;k++){

                       xx=i+dir[k][0];
                       yy=j+dir[k][1];

                        if(xx<0||xx>=m||yy<0||yy>=n||g[xx][yy]=='*')continue;

                        if(g[xx][yy]=='@') UN(i*n+j,xx*n+yy);
                    }
                }
            }
        }

        //get the ans

        int ans=0;
        for(int i=0;i<m*n;i++){
            if(a[i]==i)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
