#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=200005;

int l[maxn],r[maxn];

struct Line{

    int x;
    int y;

};

bool cmp(Line a,Line b){
    return a.x<b.x;
}

Line line[maxn];
int y[maxn];

int n,w;
//BIT (Binary Indexed Tree)

int lowbit(int x){
    return x&(-x);
}

void update(int c[],int i,int x){

    while(i<=w){

        c[i]+=x;
        i+=lowbit(i);
    }
}
int sum(int c[],int i){

    int ans=0;
    while(i!=0){

        ans+=c[i];
        i-=lowbit(i);
    }

    return ans;
}


int main()
{

    while(scanf("%d",&n)&&n!=0){

        for(int i=0;i<n;i++){
         scanf("%d%d",&line[i].x,&line[i].y);
         y[i]=line[i].y;

        }

        //
        sort(y,y+n);

        //the number unique set

        w=unique(y,y+n)-y;

        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));

        // add all point in r at first


     //sort line by x-ray
       // sort(line,line+n,cmp);
        sort(line,line+n,cmp);

        for(int i=0;i<n;i++){
            update(r,lower_bound(y,y+w,line[i].y)+1-y,1);
        }

        int Stan=-1;
        int st=0;

        vector<int> Ollie;
        for(int i=1;i<=n;i++){

            if(i==n||line[i].x!=line[i-1].x){

                // delete element where x=line[i-1].x

                for(int j=st;j<i;j++) update(r,lower_bound(y,y+w,line[j].y)+1-y,-1);

                // search  for each y
                int stan=-1,ollie=-1;


                for(int j=st;j<i;j++){

                    int f=lower_bound(y,y+w,line[j].y)+1-y;

                    int s=sum(l,f-1)+sum(r,w)-sum(r,f);  // bottem-left +  top-right

                    int o=sum(l,w)-sum(l,f)+sum(r,f-1);

                    if(o>ollie){

                        stan=s;
                        ollie=o;
                    }else if(o==ollie){

                        stan=stan<s?stan:s;
                    }
                }

                //update Stan
                if(stan>Stan){

                    Stan=stan;
                    Ollie.clear();
                    Ollie.push_back(ollie);
                }else if(stan==Stan){

                    Ollie.push_back(ollie);
                }

                // add left of i to l
                for(int j=st;j<i;j++){

                    update(l,lower_bound(y,y+w,line[j].y)+1-y,1);
                }
                st=i;
            }
        }

        //

        sort(Ollie.begin(),Ollie.end());
        int len=unique(Ollie.begin(),Ollie.end())-Ollie.begin();

        printf("Stan: %d; Ollie:",Stan);
        for(int i=0;i<len;i++)printf(" %d",Ollie[i]);
        printf(";\n");
    }
    return 0;
}
