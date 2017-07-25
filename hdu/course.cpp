#include <iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

#define   MAX  105


vector<int> stu[305];
vector<int> cour[105];

bool visited[105];
int p,n;
int match[105];
bool dfs(int i){

    int n=stu[i].size();

    for(int j=0;j<n;j++){


        if(visited[stu[i][j]]) continue;
        visited[stu[i][j]]=true;
        if(match[stu[i][j]]==-1||dfs(match[stu[i][j]])){

            match[stu[i][j]]=i;
            return true;
        }
    }

    return false;

}




int hungrain(int n){

    memset(match,-1,sizeof(match));

    // how many stu

    int result=0;
    for(int i=1;i<=n;i++){

        memset(visited,false,sizeof(visited));
        if(dfs(i)) result++;
    }

    return result;

}



int main()
{
    int t;
    scanf("%d",&t);

     int cnt;
     int id;
    while(t--){

        scanf("%d%d",&p,&n);
        //p is the number of course

        //init
        for(int i=0;i<305;i++)
            stu[i].clear();


        for(int i=1;i<=p;i++){

           cnt=0;
            scanf("%d",&cnt);

            for(int j=0;j<cnt;j++){

                scanf("%d",&id);

                stu[id].push_back(i);

            }


        }


        //handle
        int total=0;
        total=hungrain(n);
        if(total==p)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }



    return 0;
}
