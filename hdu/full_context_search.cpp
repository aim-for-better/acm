#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const int maxn=10005;
const int R=10;

char  txt[maxn*6];

string key[maxn];
bool vis[maxn];
bool flag=false;
vector<int> ans;
struct Node{
    int val;
    struct Node* next[R];
    Node(){
        val=-1;
        memset(next,NULL,sizeof(next));
    }
};

void Insert(Node* x,string s,int val){

    int len=s.length();
    int i=0;
    int index;
    while(i<len){

        index=s[i]-'0';
        if(x->next[index]==NULL){

            x->next[index]=new Node();
        }

        x=x->next[index];
        i++;
    }
    x->val=val;
}

void query(Node *x,char *s){

    int i=0;
    int len=strlen(s);

    int index;
    while(i<len){
        index=s[i]-'0';
        if(x->next[index]==NULL) return ;

        x=x->next[index];
        if(x->val!=-1&&!vis[x->val]){
            ans.push_back(x->val);
            vis[x->val]=true;
            flag=true;
        }
        i++;
    }

}
int main()
{



    flag=false;
    int m,n;
    scanf("%d%d",&m,&n);

    Node *root=new Node();
    int line=0;
    char ch;
    int Index=0;
    scanf("%c",&ch);
    while(line<m){

        scanf("%c",&ch);
        if(ch=='\n'){

            line++;
            continue;
        }
        txt[Index++]=ch;
    }
    txt[Index]='\0';

    string tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>tmp;
        }
        cin>>key[i];

        Insert(root,key[i],i);
    }
    ans.clear();

    for(int j=0;j<Index;j++){
        query(root,txt+j);
    }
    if(flag){
        printf("Found key:");
        int len=ans.size();
        for(int i=0;i<len;i++){
            printf(" [Key No. %d]",ans[i]);
        }
        printf("\n");

    }else{
        printf("No key can be found !\n");
    }
    return 0;
}
