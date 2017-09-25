#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;


const int maxn=100005;
int a[maxn];
bool hascycle=false;
int visited[maxn];
int en; //edge num;
int vn;
int Find(int x){
    if(a[x]==x)
        return a[x];
    else a[x]=Find(a[x]);
    return a[x];
}
void UN(int p,int q){
    p=Find(p);
    q=Find(q);
    if(p==q){
        hascycle=true;
    }else{
        a[p]=q;
        en++;
    }
    return ;
}

void init(){
    en=0;
    vn=0;
    for(int i=0;i<maxn;i++){
        a[i]=i;
        visited[i]=false;
        hascycle=false;
    }

}
int main(){
    int c,d;
    init();
    bool flag=false;

    while(true){

        init();
        scanf("%d%d",&c,&d);
        if(c==-1&&d==-1) break;
        if(c==0&&d==0){
            printf("Yes\n");
            continue;
        }
        visited[c]=true;
        visited[d]=true;
        UN(c,d);
        while(true){
            scanf("%d%d",&c,&d);
            if(c==0&&d==0) break;
            visited[c]=true;
            visited[d]=true;
            UN(c,d);
        }
        for(int i=0;i<maxn;i++){
            if(visited[i]) vn++;
        }
        if(!hascycle&&en+1==vn)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
