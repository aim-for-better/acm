#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=1005;

int a[maxn];
int h[maxn];
int n,m;

int Find(int p){

    if(a[p]==p) return p;

    a[p]=Find(a[p]);
}

void UN(int p,int q){

    p=Find(p);
    q=Find(q);

    if(p!=q){

        if(h[p]<h[q]){
            a[q]=a[p];
            h[p]=h[p]+h[q];
        }else{

            a[p]=a[q];
            h[q]=h[q]+h[p];
        }

    }
}
int main()
{
    int p,q;
    while(scanf("%d",&n)!=EOF){

        if(n==0) break;

        //init
        for(int i=1;i<=n;i++){

            a[i]=i;
            h[i]=1;
        }
        scanf("%d",&m);

        for(int i=1;i<=m;i++){

            scanf("%d%d",&p,&q);

            UN(p,q);
        }

        int ans=0;
        for(int i=1;i<=n;i++){

            if(a[i]==i) ans++;
        }

        printf("%d\n",ans-1);
    }

    return 0;
}
