#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;


#define mm 105

char s1[mm];

char s2[mm];
int dp[mm][mm];
int score[5][5]={
5,-1,-2,-1,-3,
-1,5,-3,-2,-4,
-2,-3,5,-2,-2,
-1,-2,-2,5,-1,
-3,-4,-2,-1,-10000
};



int getIndex(char c){

    if(c=='A')return 0;
    else if(c=='C') return 1;
    else if(c=='G') return 2;
    else if(c=='T') return 3;
    else if(c=='-') return 4;

}

int val(char c,char d){

    int i1=getIndex(c);
    int i2=getIndex(d);

    return score[i1][i2];
}

int MAX(int a,int b){


    return b>a?b:a;
}
int main()
{
    int t;
    cin>>t;

    int len1,len2;

    while(t--){

        memset(dp,0,sizeof(dp));

        scanf("%d%s",&len1,s1+1); //if index start from 0,then will need index -1
                                   // so index start from 1
        scanf("%d%s",&len2,s2+1);


        for(int i=1;i<=len1;i++){

            dp[i][0]=dp[i-1][0]+val(s1[i],'-'); // s1[i] math -
        }
        for(int j=1;j<=len2;j++){
            dp[0][j]=dp[0][j-1]+val('-',s2[j]);
        }

        for(int i=1;i<=len1;i++){

            for(int j=1;j<=len2;j++){

                dp[i][j]=MAX(dp[i-1][j]+val(s1[i],'-'),dp[i][j-1]+val('-',s2[j]));

                dp[i][j]=MAX(dp[i-1][j-1]+val(s1[i],s2[j]),dp[i][j]);
            }


        }


        cout<<dp[len1][len2]<<endl;
    }


    return 0;
}
