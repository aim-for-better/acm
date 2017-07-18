#include <iostream>


#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;


#define MAX 100000
vector<int> stu[MAX];

int match[MAX];
bool visited[MAX];

int n;
bool  dfs(int i){


    for(int j=0;j<stu[i].size();j++){

        int tmp=stu[i][j];

        //not have visited
        if(!visited[tmp]){

            visited[tmp]=true;

            if(match[tmp]==-1||dfs(match[tmp])){


                match[tmp]=i;
                return true;
            }
        }

    }

    return false;
}

int hungarian(){



    memset(match,-1,sizeof(match));
    int num=0;
    for(int i=0;i<n;i++){

        memset(visited,false,sizeof(visited));

        if(dfs(i)) num++;

    }
    return num;
}

int main()
{
    while(scanf("%d",&n)!=EOF){

        int id,r; // id and the num

        for(int i=0;i<n;i++) stu[i].clear();
        for(int i=0;i<n;i++){

            scanf("%d: (%d)",&id,&r);

            for(int j=0;j<r;j++){

                int tmp;
                cin>>tmp;

                stu[id].push_back(tmp);
            }
        }

        int matchNum=hungarian()/2;
        int result=0;
        result=n-matchNum;
        cout<<result<<endl;

    }
    return 0;
}