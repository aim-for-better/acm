#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn=7100;
const int LEN=510;


int f[maxn][LEN];

void init(){

    memset(f,0,sizeof(f));
    f[1][LEN-1]=1;
    f[2][LEN-1]=1;
    f[3][LEN-1]=1;
    f[4][LEN-1]=1;

    int a=0;
    int carry=0;
    for(int i=5;i<maxn;i++){
        for(int j=LEN-1;j>=0;j--){
            a+=f[i-1][j]+f[i-2][j]+f[i-3][j]+f[i-4][j];
            f[i][j]=a%10000;
            a/=10000;
        }
    }
}
int main()
{
    int n;

    init();
    while(scanf("%d",&n)!=EOF){

        int i=0;
        while(f[n][i]==0){

            i++;
        }

        printf("%d",f[n][i++]);
        for(int j=i;j<LEN;j++){
            printf("%04d",f[n][j]);
        }
        printf("\n");
    }
    return 0;
}
