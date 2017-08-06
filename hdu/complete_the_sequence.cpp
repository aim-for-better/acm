#include <iostream>
#include<cstdio>

using namespace std;
const int MAX=100+5;

int s[MAX][MAX];
int main()
{
   int t;
   scanf("%d",&t);
   int n,m; // n is the s , m is the c

   while(t--){

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){

        scanf("%d",&s[0][i]);
    }
    // calculate the cha  fen
    for(int i=1;i<n;i++){

        for(int j=0;j<n-i;j++){

            s[i][j]=s[i-1][j+1]-s[i-1][j];
        }
    }

    // make the same length of n-1
    for(int i=1;i<=m;i++){
        s[n-1][i]=s[n-1][0];
    }

    // back up
    // because the i-th chafen has have n-i elements.so the start is n-i
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            s[i][n-i+j]=s[i][n-i+j-1]+s[i+1][n-i+j-1];
        }
    }
    //output
    for(int i=0;i<m-1;i++){
        printf("%d ",s[0][n+i]);
    }

    printf("%d\n",s[0][n+m-1]);


   }
    return 0;
}
