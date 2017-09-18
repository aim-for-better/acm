#include <iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=15;

int t;
int n;
int a[maxn];
bool visited[maxn];
int pre[maxn];

void show(int i){

    stack<int> st;
    while(!st.empty()) st.pop();

    st.push(a[i]);
    while(pre[i]!=-1){

        i=pre[i];
        st.push(i);
    }

    printf("%d",st.top());
    st.pop();
    while(!st.empty()){
        printf("+%d",st.top());
        st.pop();
    }
    printf("\n");
}

void dfs(int sum,int i){

    if(sum+a[i]==t){

        //print
        show(i);
        return;
    }

    if(sum+a[i]>t){
        return ;
    }
    for(int j=i+1;j<n;j++){

        pre[j]=i;
        dfs(sum+a[i],j);
        pre[j]=-1;
    }

    return ;
}

void Find(){

    for(int i=0;i<n;i++){
        dfs(0,i);
    }
}
int main()
{
    while(scanf("%d%d",&t,&n)!=EOF){

        if(n==0) break;

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        memset(pre,-1,sizeof(pre));
       Find();
    }
    return 0;
}
