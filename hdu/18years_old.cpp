#include <iostream>
#include<cstdio>
using namespace std;

bool isRunYear(int n){

    if(n%4==0&&n%100!=0||n%400==0)
        return true;
    else return false;
}

int main()
{
    int t;
    int y,m,d;
    while(scanf("%d",&t)!=EOF){

        for(int i=0;i<t;i++){

            scanf("%d-%d-%d",&y,&m,&d);

            if(m==2&&d==29&&!isRunYear(y+18)) printf("-1\n");
            else{
                    int ans=0;
                if(m>2)
                for(int k=y+1;k<=y+18;k++){

                    if(isRunYear(k)) ans+=366;
                    else ans+=365;
                }else {
                    for(int k=y;k<=y+17;k++){

                         if(isRunYear(k)) ans+=366;
                        else ans+=365;
                    }
                }

                printf("%d\n",ans);

            }
        }
    }
    return 0;
}
