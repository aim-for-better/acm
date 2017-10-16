#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int INF=40000;

const int maxn=40000;
int prim[maxn];

bool isPrime(int n){

    if(n==2||n==3||n==5||n==7) return true;

    if(n%2==0||n%3==0||n%5==0||n%7==0) return false;


    for(int i=2;i*i<=n;i++){

        if(n%i==0) return false;
    }

    return true;
}

int Index=0;
void init(){

    for(int i=2;i<=INF;i++){

        if(isPrime(i)) prim[Index++]=i;
    }

}

int main()
{
   init();

   int T;
   scanf("%d",&T);
   int t=T;
   int n;
   while(T--){


    scanf("%d",&n);

    int ans=1;

    for(int i=0;i<Index&&n>1;i++){

        int tmp=0;
        while(n%prim[i]==0){
            tmp++;
            n/=prim[i];
        }
        ans*=(1+2*tmp);
    }

    if(n>1) ans*=3;

    printf("Scenario #%d:\n",t-T);
    printf("%d\n\n",(ans+1)/2);
   }
    return 0;
}
