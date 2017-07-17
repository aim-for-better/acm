#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n;

char arr[5][5];
bool visited[5][5];

int dir[][2]={0,1,0,-1,1,0,-1,0}; //r,l,d,u

int nmax;



vo

bool dfs(int x,int y,int num){


    if(arr[x][y]=='X') return ;


     for(int k=0;k<4;k++){

         int nx=x+dir[k][0];
         int ny=y+dir[k][1];

         if(nx<0||nx>=n||ny<0||ny>=n)continue;


         if(arr[nx][ny]=='X')continue ;

        if(!visited[nx][ny]){

            visited[nx][ny]=true;


            dfs(nx,ny,num);

        }




     }


     return true ;
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
        init();
        cout<<nmax<<endl;
    }

    return 0;
}
