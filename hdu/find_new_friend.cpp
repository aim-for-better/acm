#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int Euler(int n){

    int ans=n;

    for(int i=2;i*i<=n;i++){

        if(n%i==0){

            ans=ans/i*(i-1);
        }

        while(n%i==0) n/=i;

    }

    if(n>1) ans=ans/n*(n-1);

    return ans;
}

int main()
{
  int T;
  scanf("%d",&T);
  int n;
  while(T--){

    scanf("%d",&n);

    printf("%d\n",Euler(n));

  }
    return 0;
}
