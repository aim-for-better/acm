#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int ans;
    while(t--){

        ans=0;
        scanf("%d",&n);
        while(n){

            ans+=n/5;
            n/=5;

        }
        printf("%d\n",ans);
    }
    return 0;
}
