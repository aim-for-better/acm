#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const  int maxn=68;
int f[maxn];
int main()
{
    int n;
    f[1]=1;
    f[2]=3;
    int mm=0;
    double tmp=0;
    for(int i=3;i<=65;i++){

        mm=1<<30;
        for(int x=1;x<i;x++){

           tmp=2*f[x]+pow(2,i-x)-1;
           if(tmp<mm)mm=(int)tmp;;

        }
        f[i]=mm;
    }

    while(scanf("%d",&n)!=EOF){

        printf("%d\n",f[n]);
    }
    return 0;
}
