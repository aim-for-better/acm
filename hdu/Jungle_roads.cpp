#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
struct Edge{
    int w;
    int v;
    int cost;
    Edge(){}

    Edge(int from,int to ,int weight){

        w=from;
        v=to;
        cost=weight;
    }

};

int id[30];
int Find(int p){
    if( id[p]==p) return p;

    id[p]=Find(id[p]);
    return id[p];
}
void UN(int p,int q){

    int pRoot=Find(p);
    int qRoot=Find(q);
    if(pRoot==qRoot) return ;

    id[pRoot]=qRoot;
}
bool hasConnect(int p,int q){
    return Find(p)==Find(q);
}

struct cmp{

    bool operator ()(Edge a ,Edge b){

        return a.cost>b.cost;
    }
};
int main()
{
    priority_queue< Edge,vector<Edge>,cmp> q;


    int n;
    char from;
    char to;
    int weight;
    int m;
    while(scanf("%d",&n)!=EOF){

        if(n==0)break;
        //init
        while(!q.empty())q.pop();

        memset(id,0,sizeof(id));
        for(int i=0;i<n-1;i++){
            cin>>from>>m;

            for(int j=0;j<m;j++){

                cin>>to>>weight;
                q.push(Edge(from-'A',to-'A',weight));
                id[from-'A']=from-'A';
                id[to-'A']=to-'A';
            }
        }

    //prim
        Edge tmp;
        int sum=0;
        while(!q.empty()){
            tmp=q.top();
            q.pop();

            if(hasConnect(tmp.w,tmp.v)) continue;
            UN(tmp.w,tmp.v);
            sum+=tmp.cost;
        }

        printf("%d\n",sum);

    }
    return 0;
}
