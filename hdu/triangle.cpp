#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    int n;

    int ans=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);

        ans=3*(n-1)*n+2;
        printf("%d\n",ans);

    }
    return 0;
}
