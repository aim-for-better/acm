#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=3005;

int a[maxn];
int top[maxn];

int N,M;

priority_queue<int> q;
int n=0;

void exch(int i,int j){
    int tmp=top[i];
    top[i]=top[j];
    top[j]=tmp;
}
//MinPQ
void swim(int k){

    while(k>1&&top[k/2]>top[k]){
        //
        exch(k/2,k);
        k/=2;
    }
}

void sink(int k){

    while(2*k<=n){

        int j=2*k;

        //j is the smaller between two son
        if(j<n&&top[j]>top[j+1])j++;
        //
        if(top[k]<=top[j]) break;
        exch(k,j);
        k=j;
    }
}
void delMin(){

    exch(1,n--);
    sink(1);
    top[n+1]=0;
}

void Insert(int x){

    top[++n]=x;
    swim(n);
}

int main()
{
    while(scanf("%d%d",&N,&M)!=EOF){

        n=0;
        memset(top,0,sizeof(maxn));

        for(int i=0;i<N;i++){

            scanf("%d",&a[i]);
        }

        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                Insert(a[i]+a[j]);

                if(n>M) delMin();
            }
        }

        //
        sort(top+1,top+1+M);

        printf("%d",top[M]);
        for(int i=M-1;i>=1;i--){
            printf(" %d",top[i]);
        }
        printf("\n");
    }

    return 0;
}
