#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=200000;

int a[maxn*3];


void pushup(int i){

    a[i]=max(a[i<<1],a[i<<1|1]);
}

void build(int l,int r,int i){

    if(l==r){

        scanf("%d",&a[i]);
        return ;
    }

    int mid=l+(r-l)/2;

    build(l,mid,i<<1);
    build(mid+1,r,i<<1|1);
    pushup(i);
}

int query(int ql,int qr,int l,int r,int i){

    if(ql<=l&&r<=qr){

        return a[i];
    }
    int ans=0;

    int mid=l+(r-l)/2;

    if(qr<=mid) ans=query(ql,qr,l,mid,i<<1);
    else if(ql>mid) ans=query(ql,qr,mid+1,r,i<<1|1);
    else{

        ans=max(query(ql,qr,l,mid,i<<1),query(ql,qr,mid+1,r,i<<1|1));
    }
    return ans;
}

void update(int p,int num,int l,int r,int i){
    if(l==r){

        a[i]=num;
        return ;
    }
    int mid=l+(r-l)/2;
    if(p<=mid) update(p,num,l,mid,i<<1);
    else update(p,num,mid+1,r,i<<1|1);

    pushup(i);
}


int main()
{
    int n,m;
    int A,B;
    string op;
    while(scanf("%d%d",&n,&m)!=EOF){

        build(1,n,1);

        for(int i=0;i<m;i++){

            cin>>op;
            scanf("%d%d",&A,&B);

            if(op=="Q"){

                printf("%d\n",query(A,B,1,n,1));
            }else if(op=="U"){
                update(A,B,1,n,1);
            }
        }


    }
    return 0;
}
