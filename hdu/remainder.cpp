#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

#define   MAX 3005


struct Node{

    int n;

    string step;

};



bool visited[MAX];

int n,k,m;

char op[]={'+','-','*','%'};

Node  bfs(){

int r=(((n+1)%k)+k)%k;

int km=k*m;
queue<Node> q;

Node tmp;
tmp.n=n;
tmp.step="";

q.push(tmp);

visited[((tmp.n%k)+k)%k]=true;


while(!q.empty()){

    Node t=q.front();
    q.pop();

    if((((t.n%k)+k)%k)==r){
        return t;
    }

    Node temp;
    int next;
    string step;
    for(int i=0;i<4;i++){

        if(op[i]=='+'){

            next=(t.n+m)%km;   //important
            step=t.step+"+";

        }else if(op[i]=='-'){
            next=(t.n-m)%km;  //important
            step=t.step+"-";
        }else if(op[i]=='*'){

            next=(t.n*m)%km;//important
            step=t.step+"*";
        }else if(op[i]=='%'){
            next=(t.n%m+m)%m%km;   //important
            step=t.step+"%";
        }
        if(visited[((next%k)+k)%k])continue;

        visited[((next%k)+k)%k]=true;
        temp.n=next;
        temp.step=step;

        q.push(temp);
    }

}
  return tmp;
}
int main()
{


    while(cin>>n>>k>>m){

        if(n==0&&k==0&&m==0) break;
        memset(visited,false,sizeof(visited));
        Node result;
        result=bfs();
        if(result.step=="")cout<<"0"<<endl;
        else {
            cout<<result.step.length()<<endl;
            cout<<result.step<<endl;
        }

    }


    return 0;
}
