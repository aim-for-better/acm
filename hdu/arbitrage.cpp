#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

using namespace std;

const int maxn=35;

int n,m;

double g[maxn][maxn];

//floyd  init be to 0;
void inital(){

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            g[i][j]=0;
        }
    }
}

void floyd(){

    for(int k=1;k<=n;k++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                double tmp=g[i][k]*g[k][j];
                if(g[i][j]<tmp){
                    g[i][j]=tmp;
                }
            }
        }
    }
}
int main()
{

    int cnt=0;
    while(scanf("%d",&n)!=EOF){

        if(n==0)break;
        cnt++;
        map<string,int> currency;
        string name;
        for(int i=1;i<=n;i++){

            cin>>name;

            currency[name]=i;
        }

        //convert string to int

        //init floyd
        inital();

        scanf("%d",&m);
        string from,to;
        double rate;
        for(int i=1;i<=m;i++){
            cin>>from>>rate>>to;

            g[currency[from]][currency[to]]=rate;

        }

        // floyd
        floyd();
        //charge
        bool flag=false;
        //
        for(int i=1;i<=n;i++){

            if(g[i][i]>1.0) flag=true;
        }

        printf("Case %d: ",cnt);
        if(flag){

            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
