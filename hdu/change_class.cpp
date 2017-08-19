#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int maxn=27;

vector<int> g[maxn];
bool visited[maxn];

// start is b =1
bool bfs(int start){

    queue<int> q;
    while(!q.empty()) q.pop();

    q.push(start);

    int now;
    int next;
    while(!q.empty()){
        now=q.front();
        q.pop();

        if(now=='m'-'a') return true;
        int len=g[now].size();
        for(int i=0;i<len;i++){

            int w=g[now][i];

            //
            if(w=='m'-'a') return true;

            if(!visited[w]){

                visited[w]=true;
                q.push(w);
            }

        }
    }
    return false;
}
int main()
{
    string s;
    int n;
    int start;
    int en;

    for(int i=0;i<maxn;i++){
        g[i].clear();
    }
    while(cin>>s){


        if(s=="0"){


            memset(visited,false,sizeof(visited));
            visited[1]=false;
            if(bfs(1)){
                printf("Yes.\n");
            }else printf("No.\n");

            for(int i=0;i<maxn;i++){
                g[i].clear();
            }
            continue;
        }

        n=s.length();
        int start=s[0]-'a';
        int en=s[n-1]-'a';

        g[start].push_back(en);
    }


    return 0;
}
