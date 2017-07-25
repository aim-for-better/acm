#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 1005

int a1[MAX];
int a2[MAX];
int a3[MAX];
int r[8005];
int main()
{
   int n1,n2,n3;


    while(cin>>n1>>n2>>n3){


        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(r,0,sizeof(r));

        if(n1==0&&n2==0&&n3==0) break;
        a1[0]=a2[0]=a3[0];
        for(int i=1;i<=n1;i++){

            a1[i]=i;
        }
        for(int i=1;i<=n2;i++) a2[i]=2*i;
        for(int i=1;i<=n3;i++) a3[i]=5*i;

        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){

                r[a1[i]+a2[j]]=a1[i]+a2[j];

             }
        }
        int tmp=n1+n2*2;
        for(int i=0;i<=tmp;i++){

            for(int j=0;j<=n3;j++){
              //  cout<<r[i]<<endl;

                r[r[i]+a3[j]]=r[i]+a3[j];
            }
        }

        for(int i=1;i<=n1+2*n2+n3*5+1;i++){


            if(r[i]==0)
            {
                cout<<i<<endl;

                break;
            }
        }


    }
    return 0;
}
