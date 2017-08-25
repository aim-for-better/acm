#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    long long sum;
    int maxn=0;
    while(T--){

        maxn=0;
        sum=0;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%d",&m);

            if(m>maxn) maxn=m;

            sum+=m;
        }

        if(sum-maxn+1>=maxn) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
