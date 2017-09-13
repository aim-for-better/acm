#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

const int maxn=50005;

vector<string> str[26];

string a[maxn];
const int R=26;
struct Node{

    int val=-1;
    struct Node* next[R];
    Node(){
        val=-1;
        memset(next,NULL,sizeof(next));
    }
};

Node* root;

int get(string key){
    int d=0;
    char c;
    Node* x =root;

    while(x!=NULL){
        if(d==key.length()){ return x->val; }
        c=key[d];
        x=x->next[c-'a'];
        d++;
    }
    return -1;
}
void put(string key,int val){

    Node* x=root;
    int d=0;
    char c;
    while(d<key.length()){

        c=key[d];
        if(x->next[c-'a']==NULL)
            x->next[c-'a']=new Node();
        d++;
        x=x->next[c-'a'];
    }
    x->val=val;
}

int main()
{
    string s;
    int n=0;
    root=new Node();
    while(cin>>s){

        a[n]=s;
        n++;
        put(s,n);
    }


    for(int i=0;i<n;i++){

        int len=a[i].length();
        for(int j=1;j<len;j++){

            if(get(a[i].substr(0,j))!=-1&&get(a[i].substr(j))!=-1){

                cout<<a[i]<<endl;
                break;
            }
        }
    }

    return 0;
}
