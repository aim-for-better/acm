#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int n,c,m;
char a[17];
bool flag=false;
bool visited[5505];

struct Node{
    string pw;
    int len;
    int mod;
};
queue<Node> q;

int char2Int(char ch){
    int ans=0;
     if(ch>='A'&&ch<='F')
        ans=(ch-'A'+10);
    else
        ans=(ch-'0');
    return ans;
}

bool bfs(){
    //the flag that whether has password or not
    flag=false;
    //has m number
    memset(visited,false,sizeof(visited));
    while(!q.empty())q.pop();
    Node tmp;
    for(int i=0;i<m;i++){
        // do not
        if(a[i]=='0') continue;
        tmp.pw=a[i];
        tmp.len=1;
        tmp.mod=char2Int(a[i])%n;

        if(tmp.mod==0){
                flag=true;
                cout<<tmp.pw<<endl;
                return true;
            }
        visited[tmp.mod]=true;
        q.push(tmp);
    }
    Node now;
    Node next;
    while(!q.empty()){

        //judge
        now=q.front();
        q.pop();

        if(now.mod==0){
            flag=true;
            cout<<now.pw<<endl;
            return true;
        }
        Node next=now;
        for(int i=0;i<m;i++){

            next.pw=now.pw+a[i];
            next.len=now.len+1;
            next.mod=(now.mod*c+char2Int(a[i]))%n;
            if(next.mod==0){
                flag=true;
                cout<<next.pw<<endl;
                return true;
            }
            if(next.len<=500&&!visited[next.mod]){
                visited[next.mod]=true;
                q.push(next);
            }
        }
    }

    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    string tmp;
    while(T--){
        scanf("%d%d",&n,&c); // c is the radix
        scanf("%d",&m); // m is the number
        for(int i=0;i<m;i++){
            cin>>tmp;
            a[i]=tmp[0];
        }
        sort(a,a+m);
        if(n==0){

            if(a[0]=='0') {
                printf("0\n");
            }else{
                printf("give me the bomb please\n");
            }
        }else{
            if(!bfs()){
                printf("give me the bomb please\n");
            }
        }
    }
    return 0;
}
