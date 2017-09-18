#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int map[15],v[15],ans[15];
int sum,n,flag;
void dfs(int x,int num,int cur)
{
    int i;
    if(num == sum)
    {
        printf("%d",map[ ans[0] ]);
        for(i = 1 ; i < cur ; i ++)
        printf("+%d",map[ ans[i] ]);
        printf("\n");
        flag = 1;
        return ;
    }
    int temp = -1;
    for(i = x ; i < n ; i ++)
    if(!v[i] && map[i] != temp)
    {
        if(num + map[i] > sum) continue;
        v[i] = 1;
        temp = map[i];
        ans[cur] = i;
        dfs(i,num + map[i],cur + 1);
        v[i] = 0;
    }
}
int main()
{
    int i;
    while(scanf("%d%d",&sum,&n) && n)
    {
        int t = 0 ;
        for(i = 0 ; i < n ; i ++)
        {
            scanf("%d",&map[i]);
            t += map[i];
        }
        printf("Sums of %d:\n",sum);
        if(t < sum){printf("NONE\n");continue;}
        memset(v,0,sizeof(v));
        flag = 0;
        dfs(0,0,0);
        if(!flag) printf("NONE\n");
    }
    return 0;
}
