#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn=1005;

int a[maxn];
int b[maxn];

int Find(int i){

    if(a[i]==i){
        return a[i];
    }

    a[i]=Find(a[i]);

    return a[i];
}

void UN(int p,int q){

     p=Find(p);
     q=Find(q);

    if(p!=q){

        //num of p less num of q
        if(b[p]<b[q]){
            a[q]=a[p];
            b[p]=b[p]+b[q];
        }else{

            a[p]=a[q];
            b[q]+=b[p];
        }
    }
    return ;
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    int p,q;
    while(T--){

        scanf("%d%d",&n,&m);
        //init
        for(int i=1;i<=n;i++){
            a[i]=i;
            b[i]=1;
        }

        for(int i=0;i<m;i++){

            scanf("%d%d",&p,&q);

            UN(p,q);
        }

        int ans=0;
        for(int i=1;i<=n;i++){

            if(a[i]==i) ans++;
        }

        printf("%d\n",ans);
    }
    return 0;
}
