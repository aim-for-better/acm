#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    int ans;
    while(scanf("%d",&n)!=EOF){

        ans=(n*n*n+5*n+6)/6;
        printf("%d\n",ans);

    }
    return 0;
}
