#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

int r,c,n;

char grid[13][13];
bool visited[13][13];


vector<char> route;

vector<char> ring;

void dfs2(int i,int j,int ex,int ey){

   if(i==ex&&j==ey){
    return ;
   }
   ring.push_back(grid[i][j]);
   switch(grid[i][j]){

            case 'N':

                dfs2(i-1,j,ex,ey);
                break;
            case 'S':
                dfs2(i+1,j,ex,ey);
                break;
            case 'W':
                dfs2(i,j-1,ex,ey);
                break;

            case 'E':
                dfs2(i,j+1,ex,ey);
                break;
        }

}
bool dfs(int i,int j){


   if(i<0||i>=r||j<0||j>=c){

        return false;
   }
   if(!visited[i][j]){

        visited[i][j]=true;
        route.push_back(grid[i][j]);
        switch(grid[i][j]){

            case 'N':

                dfs(i-1,j);
                break;
            case 'S':
                dfs(i+1,j);
                break;
            case 'W':
                dfs(i,j-1);
                break;

            case 'E':
                dfs(i,j+1);
                break;
        }

   }else{

        dfs2(0,n-1,i,j);
        return true;
   }

}
int main()
{


   while(cin>>r>>c>>n){

        bool loop=false;
        route.clear();
        ring.clear();
        memset(grid,0,sizeof(grid));
        memset(visited,false,sizeof(visited));
        if(r==0&&c==0&&n==0){

            break;
        }

        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                cin>>grid[i][j];
            }

        }

        loop=dfs(0,n-1);

        if(loop){

            printf("%d step(s) before a loop of %d step(s)\n",
                   ring.size(),route.size()-ring.size());

        }else{

            printf("%d step(s) to exit\n",route.size());
        }



   }
    return 0;
}
