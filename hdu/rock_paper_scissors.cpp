#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


const int maxn=105;
const double eps=1e-8;
int w[maxn];
int l[maxn];

int  charge(string s1,string s2){


     if(s1==s2) return 0;


     if(s1=="rock"){
        if(s2=="paper")return -1;
        else return 1;
     }else if(s1=="paper"){
        if(s2=="scissors") return -1;
        else return 1;
     }else if(s1=="scissors"){
        if(s2=="rock") return -1;
        else return 1;
     }
}
int main()
{
    int n,k;

    int p1,p2;
    string s1,s2;
     int result=-2;
    n=-1;
    while(true){
        if(n==0) break;
        if(n==-1)
            scanf("%d",&n);

        scanf("%d",&k);

        memset(w,0,sizeof(w));
        memset(l,0,sizeof(l));

        for(int i=0;i<k;i++){

            scanf("%d",&p1);
            cin>>s1;
            scanf("%d",&p2);
            cin>>s2;
            result=charge(s1,s2);

            if(result==0){
                continue;
            }else if(result==1){  // p1 win p2

              w[p1]++;
              l[p2]++;
            }else if(result==-1){  //p1 lose p2

                l[p1]++;
                w[p2]++;
            }
        }
        double ans=0.0;
        for(int i=1;i<=n;i++){

            if(w[i]-0<eps&&l[i]-0<eps){

               printf("-\n");
            }else{

                ans=1.0*w[i]/(1.0*(w[i]+l[i]));
                printf("%.3lf\n",ans);
            }

        }


        scanf("%d",&n);

        if(n!=0) printf("\n");

    }


    return 0;
}
