#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
bool mark[7][7];
int dpx,dpy;
int spx,spy;
int n=0,m=0,t=0;


int dix[]={-1,1,0,0};

int diy[]={0,0,-1,1};



int ABS(int x){
    return x<0?-x:x;
}

bool dfs(int i,int j,int step){

  if(step==t){

    if(mark[dpx][dpy])
        return true;
    else
        return false;
  }
  int tmp=ABS(i-dpx)+ABS(j-dpy)-ABS(step-t);
  //cut
  if(tmp>0||tmp%2!=0){
    return false;
  }
  // dfs
 for(int s=0;s<4;s++){

   int  ni=i+dix[s];
   int  nj=j+diy[s];

   if(ni<0||ni>=n||nj>=m||nj<0||mark[ni][nj]) continue;

   mark[ni][nj]=true;

    if(dfs(ni,nj,step+1)){
            return true;
    }

    mark[ni][nj]=false;

  }
    return false;
}


int main()
{
    //index of door and the start point
    string s;
    while(scanf("%d%d%d",&n,&m,&t)&&n){

        memset(mark,false,sizeof(mark));
        //input
        for(int i=0;i<n;i++){

            cin>>s;
            for(int j=0;j<m;j++){


              //record index of S and D;
                if(s[j]=='S'){
                    spx=i;
                    spy=j;
                    mark[i][j]=true;

                }else if(s[j]=='D'){
                    dpx=i;
                    dpy=j;
                }else if(s[j]=='X'){
                    mark[i][j]=true;
                }
                // TODO set mark[i][j]=true if  s[i][j]=='X'
            }
        }

        if(dfs(spx,spy,0)){
            printf("YES\n");
       }else{
       printf("NO\n");
      }

    }
    return 0;
}
