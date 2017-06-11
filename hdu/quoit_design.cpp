#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;



struct Node{
  double x,y;
};


Node ar[100001];

bool cmpx(Node a,Node b){return a.x<b.x;}

bool cmpy(Node a,Node b){return a.y<b.y;}


int main()
{

    int n;
    while(cin>>n){

        if(n==0)break;

        for(int i=0;i<n;i++){

            scanf("%lf%lf",&ar[i].x,&ar[i].y);

        }

        sort(ar,ar+n,cmpx);


        double d=1<<30;
        for(int i=1;i<n;i++){

        double temp=(ar[i].x-ar[i-1].x)*(ar[i].x-ar[i-1].x)+(ar[i].y-ar[i-1].y)*(ar[i].y-ar[i-1].y);

        if(d>temp){

            d=temp;
        }
    }
        sort(ar,ar+n,cmpy);

        for(int i=1;i<n;i++){

        double temp=(ar[i].x-ar[i-1].x)*(ar[i].x-ar[i-1].x)+(ar[i].y-ar[i-1].y)*(ar[i].y-ar[i-1].y);

        if(d>temp){

            d=temp;
        }
    }

        printf("%.2lf\n",sqrt(d)/2);
    }

    return 0;
}
