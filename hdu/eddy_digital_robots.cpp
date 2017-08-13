#include <iostream>
#include<cstdio>
using namespace std;

//usually nod is 10 but this problem mod is 9;
int quickMod(int a,int b,int mod){

    int ans=1;
    while(b){

        if(b%2==1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans%mod;
}

int main()
{
   int n;
   int ans=0;
   while(scanf("%d",&n)!=EOF&&n!=0){

        ans=quickMod(n,n,9);
        ans=ans==0?9:ans;
        printf("%d\n",ans);
   }
    return 0;
}
