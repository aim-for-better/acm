#include <iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

struct Node{

    int id;
    int sn; //solved num;

    int ct; // consume time;


};

bool cmp(Node a,Node b){


    if(a.sn>b.sn) return true;
    else if(a.sn==b.sn){

        return a.ct<b.ct;
    }else{
        return false;
    }
}


int score[105];
vector<Node> g[8];
int main()
{
    int n;
    while(cin>>n){

        if(n<0) break;

        memset(g,0,sizeof(g));
        for(int i=0;i<8;i++)
            g[i].clear();
        int p;
        int h,m,s;
        Node tmp;
        for(int i=1;i<=n;i++){

            scanf("%d %d:%d:%d",&p,&h,&m,&s);

           // printf("%d %d %d %d\n",p,h,m,s);

           int t=h*3600+m*60+s;
           tmp.id=i;
           tmp.sn=p;
           tmp.ct=t;
           g[p].push_back(tmp);

        }

        for(int i=1;i<=5;i++){
            sort(g[i].begin(),g[i].end(),cmp);


        }

        //give the score;

        for(int i=5;i>=0;i--){

            int len=g[i].size();
            int line=len/2;

            int base=100-(5-i)*10;
            for(int j=0;j<len;j++){


                if(i==5)
                    score[g[i][j].id]=100;
                else if(i==0){

                    score[g[i][j].id]=50;
                }else{
                    if(j+1<=line){
                       score[g[i][j].id]=base+5;
                    }else
                       score[g[i][j].id]=base;
                }
            }

        }

        //print

        for(int i=1;i<=n;i++){

            cout<<score[i]<<endl;
        }
        cout<<endl;


    }


    return 0;
}
