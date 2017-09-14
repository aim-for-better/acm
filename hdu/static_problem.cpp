#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

const int R=26;

struct Node{

    int val=0;
    Node* next[R];
    Node(){
        val=0;
        memset(next,NULL,sizeof(next));
    }
};
Node* root;

int ans=0;

void put(char key[]){

    Node *x=root;
    int d=0;
    char c;
    while(d<strlen(key)){
        char c=key[d];
        if(x->next[c-'a']==NULL){
            x->next[c-'a']=new Node();
        }
        x=x->next[c-'a'];
        x->val++;
        d++;
    }
}
Node* get(char key[]){

    Node *x=root;
    int d=0;
    char c;

    while(x!=NULL){

        if(d==strlen(key)) {
            return x;
        }
        c=key[d];

        x=x->next[c-'a'];
        d++;
    }

    return NULL;
}
int collect(Node *x){

    ans=0;
    if(x==NULL) return 0;
    ans+=x->val;
}
void prefix(char key[]){

    ans=0;
    collect(get(key));
}


int main()
{
    root=new Node();

    char s[15];
    int n=0;
    while(gets(s)){
        if(strcmp(s,"")==0)break;
        n++;
        put(s);
    }

    while(gets(s)){
        prefix(s);
        printf("%d\n",ans);
    }
    return 0;
}
