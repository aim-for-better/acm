#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


typedef struct {

    int p;
    int r;
}Node;

#define MAXNUM 500000
Node city[MAXNUM+2];
int stack[MAXNUM+2];
int n=0;
int cmp(Node x,Node y){

    return x.p<y.p;
}

int LIS(){

    memset(stack,MAXNUM+2,sizeof(stack));

    // find the longest increment sequence ,
    // if city[i].rich >stack[top]  push
    // else replace the smallest that
    //greater than  city[i].rich with city[i].rich
     for(int i=0;i<n;i++){

        *lower_bound(stack,stack+n,city[i].r)=city[i].r;
    }

    int res=lower_bound(stack,stack+n,MAXNUM+2)-stack;
    return res;

}
int main()
{

    int t=0;


    while(scanf("%d",&n)!=EOF){

        t++;
        memset(city,0,sizeof(city));
        for(int i=0;i<n;i++){

            scanf("%d%d",&city[i].p,&city[i].r);
        }

        sort(city,city+n,cmp);
        //output
        int maxRoad=LIS();


        printf("Case %d:\n",t);
        if(maxRoad==1)
            printf("My king, at most %d road can be built.\n\n",maxRoad);
        else
            printf("My king, at most %d roads can be built.\n\n",maxRoad);

    }

    return 0;
}
