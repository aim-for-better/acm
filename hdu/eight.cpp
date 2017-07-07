#include <iostream>
#include<string>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;


struct State{

    char a[9];      // 1-9 mean maze 9 equal x
    int cant,pos;  // cnt the state's cantor expansion
                   // pos now the x is in where   9 means x
    string step;
};
//0-9 factorial
int fact[]={1,1,2,6,24,120,720,5040,40320,362880};

int dir[4][2]={0,1,0,-1,1,0,-1,0};  //r,l,d,u
string   rev_dir="lrud";  //reverse of dir;
//string st[362880];
bool visited[400000];

struct Node{
    char r[50];
    int len;
};
Node st[400000];
// calculate the cantor expansion of array  a
int cantorExpansion(char *a){

    int sum=0;
    //size of array a is 9
    for(int i=0;i<9;i++){

        int cnt=0;
        for(int j=i+1;j<9;j++){

            if(a[j]<a[i])cnt++;
        }
        sum+=cnt*fact[8-i];

    }

  return sum;

}


void bfs(){


    queue<State>  q;
    State now,next;

    // initial first state:now
    for(int i=0;i<9;i++){

        now.a[i]=i+'1';
    }
    now.cant=cantorExpansion(now.a);
    now.pos=8;  // the index of 9 in array a
    now.step="";

    //
//    st[now.cant]=now.step;
    visited[now.cant]=1;
    q.push(now);

    while(!q.empty()){

        now=q.front();
        q.pop();

        for(int i=0;i<4;i++){


            //the i,j index of pos
            int x=now.pos/3+dir[i][0];
            int y=(now.pos%3)%3+dir[i][1]; // 0,1,2

            if(x>2||x<0||y>2||y<0) continue;

            next=now;

            next.pos=3*x+y;
            //change
            next.a[now.pos]=next.a[next.pos];
            next.a[next.pos]='9';
            next.cant=cantorExpansion(next.a);
            //


            if(!visited[next.cant]){
                visited[next.cant]=1;
                next.step=rev_dir[i]+next.step;


             //   st[next.cant]=next.step;
                st[next.cant].len=next.step.length();

            //
                for(int j=0;j<st[next.cant].len;j++){

                    st[next.cant].r[j]=next.step[j];
                }
                q.push(next);
            }

        }

    }

}

int main()
{

    bfs();

    char s[100];
    char arr[9];
    while(gets(s)){
        int cnt=0;
        for(int i=0;i<strlen(s);i++){

            if(s[i]>='1'&&s[i]<='8'){

                arr[cnt++]=s[i];
            }else if(s[i]=='x'){

                arr[cnt++]='9';
            }
        }

        int t=cantorExpansion(arr);


       if(!visited[t]){

            cout<<"unsolvable"<<endl;

       }else{

            for(int i=0;i<st[t].len;i++){

                cout<<st[t].r[i];
            }
            cout<<endl;
       }

    }
    return 0;
}
