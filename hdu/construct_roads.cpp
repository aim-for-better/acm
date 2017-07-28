#include <iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;


#define MAX   105
#define INF   100000000
int g[MAX][MAX];

bool visited[MAX];
int n;
int q;

void handle(){

    vector<int> mst;

    memset(visited,false,sizeof(visited));
    mst.clear();
    int minimum=0;
    int start=1;

    mst.push_back(start);
    visited[start]=true;
    int len=mst.size();

    int ans=INF;
    int index=0;
    while(mst.size()!=n){

        ans=INF;
        index=0;
        for(int i=0;i<mst.size();i++){

            // find the minimum dist j
            for(int j=1;j<=n;j++){

                int v=g[mst[i]][j];
                if(!visited[j]&&v<ans){

                    ans=v;
                    index=j;
                }

            }
        }

        mst.push_back(index);
       // cout<<"the index is: "<<index<<endl;
        visited[index]=true;
        minimum+=ans;
    }


    cout<<minimum<<endl;

}


int main()
{
    while(cin>>n){



        memset(g,INF,sizeof(g));
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){
                cin>>g[i][j];
            }
        }

        cin>>q;
        int a,b;

        // a,b is connect no need road
        for(int k=1;k<=q;k++){

            cin>>a>>b;

            g[a][b]=0;
            g[b][a]=0;
        }

        //
        handle();
    }



    return 0;
}
