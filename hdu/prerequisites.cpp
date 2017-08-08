#include <iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int maxn=105;

int k[maxn];
int r[maxn];
int c[maxn];

int result[maxn];

set<int> st[maxn];
int main()
{

   int K,R,C;
   bool flag=true;
   while(scanf("%d",&K)){

        if(K==0) break;

      //init
      for(int i=0;i<maxn;i++) st[i].clear();

      memset(result,0,sizeof(result));

      flag=true;

        scanf("%d",&R);

        for(int i=0;i<K;i++){

            scanf("%d",&k[i]);
        }

        int id;
        for(int i=0;i<R;i++){

            scanf("%d%d",&r[i],&c[i]);

            for(int j=0;j<r[i];j++){

                scanf("%d",&id);
                st[i].insert(id);

            }
        }

        //
        for(int i=0;i<R;i++){

            for(int j=0;j<K;j++){

                if(st[i].find(k[j])!=st[i].end()){

                    result[i]++;
                    if(result[i]>=c[i])break;
                }

            }

            if(result[i]<c[i]){

                printf("no\n");
                flag=false;
                break;
            }
        }


        if(flag){

            printf("yes\n");
        }


   }

    return 0;
}
