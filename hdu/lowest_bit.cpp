#include <iostream>
#include<cstdio>
using namespace std;


int lowestbit(int x){

    return x&(-x);
}
int main()
{
  int n;
  while(scanf("%d",&n)!=EOF){

    if(n==0)break;

    printf("%d\n",lowestbit(n));
  }
    return 0;
}
