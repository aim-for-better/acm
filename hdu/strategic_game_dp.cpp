#include <iostream>

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1505
bool visited[MAX];

int match[MAX];

int dp[MAX][2];
//int  tree[MAX][MAX];

int n;
int soldier=0;
vector<int> tree[MAX];


int MIN(int a,int b){

    return a>b?b:a;
}
//
//bool dfs(int v){
//
//
//    for(vector<int>::iterator it=tree[v].begin();it!=tree[v].end();it++){
//
//        int w=*it;
//
//        //for
//        if(!visited[w]){
//
//            visited[w]=true;
//
//
//            if(match[w]==-1||dfs(match[w])){
//
//
//                //  the import is only set match[w]=v
//                // don't seet match[v]=w
//                match[w]=v;
//
//                return true;
//            }
//
//        }
//    }
//    return false;
//}
//int hungarian(){
//
//    int ans=0;
//
//
//     memset(match,-1,sizeof(match));
//
//    for(int v=0;v<n;v++){
//
//
//            //reset visited
//            memset(visited,false,sizeof(visited));
//            if(dfs(v)){
//
//                ans++;
//            }
//    }
//
//    return ans;
//
//}


void dfs(int i){


    if(visited[i]) return ;

    visited[i]=true;

    dp[i][0]=0;
    dp[i][1]=1;



    for(vector<int>::iterator iter=tree[i].begin();iter!=tree[i].end();iter++){



        if(visited[*iter])continue;
        dfs(*iter);


        dp[i][0]+=dp[*iter][1];

        dp[i][1]+=MIN(dp[*iter][0],dp[*iter][1]);


      //  cout<<"the i is: "<<i<<"  "<<" true is: "<<dp[i][1]<<" false is  "<<dp[i][0]<<endl;

    }

    return ;

}



int main()
{
    while(cin>>n){
      int t=n;
      soldier=0;

       for(int i=0;i<n;i++){
         tree[i].clear();
       }

       memset(visited,false,sizeof(visited));

       memset(dp,0,sizeof(dp));
       while(t--){

            int v;
            int r;

            scanf("%d:(%d)",&v,&r);
            int tmp=0;
            for(int i=0;i<r;i++){
                cin>>tmp;

                tree[v].push_back(tmp);
                tree[tmp].push_back(v);
            }
       }



      dfs(0);

      cout<<MIN(dp[0][0],dp[0][1])<<endl;
    }

    return 0;
}
