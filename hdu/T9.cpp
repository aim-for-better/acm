#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn=105;

char s1[maxn];
char s2[maxn];
char ans[maxn];
char tmp[maxn];

int num[8]={3,3,3,3,3,4,3,4};

char phone[8][4]={{0,1,2},{3,4,5},{6,7,8},{9,10,11},{12,13,14},{15,16,17,18},{19,20,21},{22,23,24,25}};
int p=0;

struct Node{

    int cnt;

    Node *next[26];

    Node(){

        cnt=0;
        memset(next,0,sizeof(next));
    }
};

Node *root;

void Insert(char s[],int k){

    Node * first=root;

    int len=strlen(s);

    for(int i=0;i<len;i++){

        if(first->next[s[i]-'a']==NULL){

            first->next[s[i]-'a']=new Node();
        }
        first->next[s[i]-'a']->cnt+=k;

        first=first->next[s[i]-'a'];
    }
}

void dfs(int cur,int len,Node *first){

    if(first==NULL) return;

    if(cur==len){

        if(first->cnt>p){
            p=first->cnt;
            for(int i=0;i<len;i++){
                ans[i]=tmp[i];
            }
            ans[len]='\0';
        }

        return ;
    }

    int t=s2[cur]-'2';

    for(int i=0;i<num[t];i++){

        if(first->next[phone[t][i]]==NULL) continue;

        tmp[cur]='a'+phone[t][i];
        dfs(cur+1,len,first->next[phone[t][i]]);
    }

    return;
}

int main()
{

    int T;
    scanf("%d",&T);

    int sn,nn;
    int P; //pinlv
    for(int k=1;k<=T;k++){
        root=NULL;
        root=new Node();

        scanf("%d",&sn);

        for(int i=0;i<sn;i++){
            scanf("%s%d",s1,&P);

            Insert(s1,P);
        }

        printf("Scenario #%d:\n",k);
        scanf("%d",&nn);

        for(int i=0;i<nn;i++){
            scanf("%s",s2);

            int len=strlen(s2);

            for(int j=1;j<len;j++){
                p=0;
                dfs(0,j,root);

                if(p>0) printf("%s\n",ans);
                else printf("MANUALLY\n");
            }
            printf("\n");
        }

        printf("\n");
    }
    return 0;
}
