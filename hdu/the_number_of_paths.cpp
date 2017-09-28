#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1005;

int a[maxn][205];

void F(){

    memset(a,0,sizeof(a));

    a[1][0]=3;
    a[2][0]=7;

    int t=0;
    for(int i=3;i<=1000;i++){

        t=0;
        for(int j=0;j<205;j++){

            t=2*a[i-1][j]+a[i-2][j]+t;

            a[i][j]=t%10000;
            t=t/10000;
        }
    }

}
int main()
{

    F();
    int n;
    while(scanf("%d",&n)!=EOF){

        int i;
        for( i=504;i>=0;i--){

            if(a[n][i]!=0){
                break;
            }
        }

        printf("%d",a[n][i]);

        for(int j=i-1;j>=0;j--){

            printf("%04d",a[n][j]);
        }
        printf("\n");
    }
    return 0;
}
