#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

const int maxn=10000;
string s;
string e;
bool visited[maxn];


struct Node{

    string s;
    int step;

    Node(string s,int step):s(s),step(step){}
};
int Hash(string s){
        int ans=0;
        ans=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
        return ans;
}
int bfs(){

    memset(visited,false,sizeof(visited));

    queue<Node> q;
    while(!q.empty()) q.pop();
    Node start=Node(s,0);
    visited[Hash(start.s)]=true;
    q.push(start);

    while(!q.empty()){

        Node now=q.front();
        q.pop();

        //exchange
        if(now.s==e) return now.step;
        for(int i=0;i<3;i++){
            string tmp=now.s;
            char c=tmp[i];
            tmp[i]=tmp[i+1];
            tmp[i+1]=c;

            if(tmp==e){
                return now.step+1;
            }

            Node next=Node(tmp,now.step+1);
            if(!visited[Hash(tmp)]){

                visited[Hash(tmp)]=true;

                q.push(next);
            }
        }

        for(int i=0;i<4;i++){

             // add
            string tmp=now.s;
            if(tmp[i]=='9') tmp[i]='1';
            else tmp[i]=tmp[i]+1;

            if(tmp==e){
                return now.step+1;
            }

            Node next=Node(tmp,now.step+1);
            if(!visited[Hash(tmp)]){
                visited[Hash(tmp)]=true;
                q.push(next);
            }
            // minus
            tmp=now.s;
            if(tmp[i]=='1') tmp[i]='9';

            else tmp[i]=tmp[i]-1;

            if(tmp==e) return now.step+1;

            next=Node(tmp,now.step+1);
            if(!visited[Hash(tmp)]){
                visited[Hash(tmp)]=true;
                q.push(next);
            }
        }
    }

    return -1;

}
int main()
{
    int T;
    scanf("%d",&T);
    int ans;
    while(T--){

        cin>>s;
        cin>>e;

        ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
