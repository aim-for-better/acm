#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;



int result[20];

bool visited[20];
int n;
bool isPrime(int x){

    //for x less than 40 this is enough
//    if(x==1||x==2||x==3||x==5) return true;
//
//    if(x%2!=0&&x%3!=0&&x%5!=0) return true;
//    return false;

    // common usage
    if(x==1||x==2)  return true;
    for(int i=2;i*i<=x;i++){

        if(x%i==0) return false;
    }

    return true;
}

void show(){

    printf("%d",result[0]);
    for(int i=1;i<n;i++){

       printf(" %d",result[i]);
    }
    printf("\n");
}

void dfs(int s,int time){

    if(time==n){

        if(isPrime(result[time-1]+result[0])){

            show();
        }

        return;
    }
    //
    for(int i=2;i<=n;i++){




        if(!visited[i]){


             visited[i]=true;
            if(isPrime(s+i)){

                result[time]=i;

                dfs(i,time+1);
            }

            visited[i]=false;
        }

    }

    return;

}
int main()
{

    int st=0;
    //dfs + back
    while(cin>>n){

        memset(result,0,sizeof(result));
        memset(visited,false,sizeof(visited));
        st++;
        //output
        result[0]=1;
        visited[0]=true;
        printf("Case %d:\n",st);
        dfs(1,1);
        printf("\n");

    }
}
