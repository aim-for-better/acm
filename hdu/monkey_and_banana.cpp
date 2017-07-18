#include <iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 5000
int n;

int dp[MAX];

struct Node{

    int x,y,z;

    bool operator<(Node b){

        return x<b.x&&y<b.y;
    }
};

vector<Node> box;


bool cmp(Node a,Node b){


    if(a.x<b.x) return true;
    else if(a.x==b.x){
        return a.y<=b.y;
    }
    return false;

}


void threeSort(int &x,int &y,int &z){
    // first set x<=y
    if(x>y) {x=x+y; y=x-y;x=x-y;}


    if(x>z) {x=x+z;z=x-z;x=x-z;}

    if(y>z) {y=y+z; z=y-z;y=y-z;}

}


void permutation(int *a,int n){


    while(true){

        int flag=-1;
        int k=-1;
        for(int i=0;i<n-1;i++){

            if(a[i]<a[i+1]) flag=i;
        }

        if(flag!=-1){

            for(int j=flag+1;j<n;j++){

                if(a[j]>a[flag]) k=j;
            }
            swap(a[flag],a[k]);

            for(int i=flag+1,j=n-1;i<j;i++,j--){

                swap(a[i],a[j]);
            }
        }

        //once end
        Node tmp;
        tmp.x=a[0],tmp.y=a[1],tmp.z=a[2];

        box.push_back(tmp);
        if(flag==-1) break;
    }

}


void handle(){

    //sort box
    sort(box.begin(),box.end(),cmp);

    //init dp
    dp[0]=box[0].z;

    int n=box.size();
    for(int i=1;i<n;i++){

        int tmax=0;
        dp[i]=box[i].z;

        //find the max
        for(int j=i-1;j>=0;j--){

            if(box[j]<box[i]){

                if(dp[j]>tmax){
                    tmax=dp[j];
                }
            }
        }
        dp[i]+=tmax;
    }

}

int main()
{

    int cnt=0;
    while(cin>>n){

        if(n==0) break;
        // init
        box.clear();
        memset(dp,0,sizeof(dp));

        int a[3];

        int x,y,z;
        for(int i=0;i<n;i++){
            memset(a,0,sizeof(a));
            cin>>x>>y>>z;

            threeSort(x,y,z);

             a[0]=x,a[1]=y,a[2]=z;
             Node tmp;
             for(int i=0;i<3;i++){

                if(i==1) tmp.z=a[i],tmp.x=a[i-1],tmp.y=a[i+1];
                else{

                    tmp.z=a[i];
                    tmp.x=a[(i+1)%3];
                    tmp.y=a[(i+2)%3];
                }

                box.push_back(tmp);
             }
        }

        //handle
        handle();
        cnt++;
        int tmp=box.size();
        int tmax=0;

        // this step is important because, the max value may not be the last value
        // the max value is the max among all dp[i]
        for(int i=0;i<tmp;i++){

            if(dp[i]>tmax) tmax=dp[i];
        }
        printf("Case %d: maximum height = %d\n",cnt,tmax);

    }
    return 0;
}
