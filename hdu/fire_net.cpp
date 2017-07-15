#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n;

char arr[5][5];
bool visited[5][5];

int dir[][2]={0,1,0,-1,1,0,-1,0}; //r,l,d,u

int nmax;



void dfs(int pos,int num){


    int x=pos/n;
    int y=pos%n;

    if(arr[x][y]=='X'|| visited[x][y]) return ;


    int buf[4][4];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            buf[i][j]=visited[i][j];
    }

    visited[x][y]=true;

    for(int k=0;k<4;k++){

         int nx=x+dir[k][0];
         int ny=y+dir[k][1];


        for(;nx>=0&&nx<n&&ny>=0&&ny<n&&arr[nx][ny]!='X';nx+=dir[k][0],ny+=dir[k][1]){

            visited[nx][ny]=true;
        }

     }

     if(1+num>nmax) nmax=1+num;


     for(int i=0;i<n*n;i++)dfs(i,1+num);

     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=buf[i][j];

     return  ;
}

int main()
{

    while(cin>>n&&n!=0){

        memset(arr,0,sizeof(arr));

        memset(visited,false,sizeof(visited));

        nmax=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cin>>arr[i][j];
            }
        }

        for(int i=0;i<n*n;i++){
            dfs(i,0);
        }

        cout<<nmax<<endl;
    }

    return 0;
}
