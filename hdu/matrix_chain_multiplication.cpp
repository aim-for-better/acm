#include <iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAX   27
struct Node{
    int x;
    int y;
};

Node matrix[MAX];

char s[200];
int main()
{
    int n;

    scanf("%d",&n);
    getchar();
    char c;
    int x=0;
    int y=0;
    int tmp=-1;
    for(int i=0;i<n;i++){

        scanf("%c",&c);
        getchar();
        scanf("%d%d",&x,&y);
        getchar();
        tmp=(int)(c-'A');
        matrix[tmp].x=x;
        matrix[tmp].y=y;
    }

    stack<Node> q;
    stack<char> op;
    Node m1,m2;

    while(gets(s)){
        if(s[0]==EOF) break;
        bool flag=false;
        int len=strlen(s);
        while(!q.empty())q.pop();
        while(!op.empty())op.pop();
        int num=0;
        for(int i=0;i<len;i++){

            if(s[i]>='A'&&s[i]<='Z')
                q.push(matrix[s[i]-'A']);
            else if(s[i]=='('){

               op.push(s[i]);
            }else if(s[i]==')'){

                if(op.top()=='(') op.pop();

                m2=q.top();
                q.pop();
                m1=q.top();
                q.pop();

                if(m1.y!=m2.x){
                    cout<<"error"<<endl;
                    flag=true;
                    break;
                }else{

                    num+=m1.x*m1.y*m2.y;
                    Node tmp;
                    tmp.x=m1.x;
                    tmp.y=m2.y;
                    q.push(tmp);

                }
            }
        }
        if(!flag)
        cout<<num<<endl;


    }

    return 0;
}
