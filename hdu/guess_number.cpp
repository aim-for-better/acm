#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=105;

struct Node{

    int a;
    int b; //the number of that a has equal with the dst number
    int c;  //the number in the right position
};

Node node[maxn];
int realNum[5];

int guessNum[5];


bool judge(int real,int j){

    realNum[1]=real/1000;
    realNum[2]=(real%1000)/100;
    realNum[3]=(real%100)/10;
    realNum[4]=(real%10);

    guessNum[1]=node[j].a/1000;
    guessNum[2]=(node[j].a%1000)/100;
    guessNum[3]=(node[j].a%100)/10;
    guessNum[4]=(node[j].a%10);

    int cnt=0;
    for(int i=1;i<=4;i++){

        if(realNum[i]==guessNum[i])cnt++;
    }

    if(cnt!=node[j].c) return false;

    bool mark[5];
    for(int i=1;i<=4;i++) mark[i]=false;

    cnt=0;

    for(int i=1;i<=4;i++){

        for(int j=1;j<=4;j++){

            if(realNum[i]==guessNum[j]&&!mark[j]){

                cnt++;
                mark[j]=true;
                break;  // break to fine the next i
            }
        }
    }

    if(cnt!=node[j].b)return false;

    return true;

}


int main()
{
    int n;
    bool flag=true;
    int cnt=0;
    int ans=0;
    while(scanf("%d",&n)!=EOF){

        if(n==0)break;

        for(int i=1;i<=n;i++){

            scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
        }

        cnt=0;
        ans=0;
        // mei ju
        for(int i=1000;i<=9999;i++){
            flag=true;
            for(int j=1;j<=n;j++){

                if(!judge(i,j)){

                    flag=false;
                    break;
                }

            }
            if(flag){

              cnt++;
              ans=i;
            }

        }

        if(cnt==1){
            printf("%d\n",ans);
        }else{
            printf("Not sure\n");
        }
    }
    return 0;
}
