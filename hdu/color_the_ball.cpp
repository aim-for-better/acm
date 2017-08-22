#include <iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=40000;
/**
  做题思路，由于线段接近于无限长度，所以，进行离散化
   离散化就是把输入的数据，有可能很大，进行排序后从1开始
   进行重新标号，这样有可能就得到一个长度很小的线段，就可以进行线段树的构建了
   具体举例：
   比如输入线段  4-7     100-300
   如果不离散化线段长度最少是300,
   或者还有更大的  100000-100001
   但是总共其实也就3条线段。
   进行离散化，把线段的各个端点进行排序，
   4,7,100,300,100000,100001. 分别对应下边0,1,2,3,4,5

    如果有线段重复比如  又有线段 7-100

   排完序就变成了，
   4,7,7,100,100,300,100000,100001.经过去重，还是变成了6个数，那么就可以转变成长度为6的线段。
   所以说离散化后的线段为1-m，m为有多少个不同的数。

   离散化后，再把原来的线段更新为，离散化后的线段表示

   那么原线段就可以转化为  1-2,3-4,5-6.就变成了连续线段1-6（下标从1开始）
   进行操作了这样线段长度大大缩短了。满足了构建线段树的空间要求了。


*/


/**

    先是记录输入的数据结构，
    mark  用来记录需要进行的操作，，l,r ,op；  l-r区间内，变成op的颜色。

    其中l,r 是离散化后的对应的区间
*/

struct Mark{
    int l,r;
    int op; // the flag white or black
};

/**
*  离散化所需数据结构，

    b 记录单个数字是第几条线段，并且是线段左端还是右端。

    int id,x,dir;  表示端点坐标
    dir =-1  表示是线段左端，
    否则表示线段右端。
    dir=0或者（非-1） 表示是线段右端。
*/

struct B{

    int id,x;

    int dir;
};

// sort need
bool cmp(B a,B b){

    return a.x<b.x
}

/**
*   线段树数据结构，
     int l,r。 表示线段的端点

     int flag.表示整个线段区间的颜色
    0表示balck  1表示white
*/
struct SegmentTree{

        int l,r;
        int flag;
};

Mark mark[maxn];

B b[maxn];

SegmentTree segTree[maxn];

int color[maxn];

/**
*   线段树操作。
*/

void build(int l,int r,int k){




    if(l>=r) return ;

    segTree[k].l=l;
    segTree[k].r=r;
    segTree[k].flag=0;  // default is black

    if(l+1==r){
        return ;
    }

    //else recursive  build

    int mid=l+(r-l)/2;

    build(l,mid,2*k);
    build(mid,r,2*k+1);


}



//下沉
void sink(int i){

    //flag down
    if(segTree[i].flag!=-1){

        segTree[2*i].flag=segTree[2*i+1].flag=segTree[i].flag;

        segTree[i].flag=-1;
    }
}

// update first k is root =1
void update(int l,int r,int k,int op){

        //
        if(l>=r) return ;

        if(segTree[k].l==l&&segTree[k].r==r){

            segTree[k].flag=op;  // range L-R  flag=op;
            return;
        }

        //need to change
        if(segTree[i].flag!=op){

            sink(k); //
        }

        int mid=l+(r-l)/2;

        if(r<=mid){

            update(l,r,2*k,op);

        }else if(l>=mid){

            update(l,r,2*k+1,op);
        }else{

            update(l,mid,2*k,op);

            update(mid,r,2*k+1,op);
        }

        //sometimes need update segTree[i] ,this is called swap  operation
}

void query(int k){

    if(segTree[k].l>=segTree[k].r) return ;

    //means no need to query child node
    if(segTree[k].flag!=-1){

        for(int i=segTree[k].l;i<segTree[k].r;i++){

            color[i]=segTree[k].flag;
        }
        return ;
    }

    query(2*k);
    query(2*k+1);
}

int main()
{
    int n;
    int l,r;
     char ch;
     int cnt;
     int a[maxn];
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        for(int i=0;i<n;i++){

            scanf("%d%d %c",&l,&r,&ch);
//            if(l>r){
//                l=l+r;
//                r=l-r;
//                l=l-r;
//            }
//

            if(ch=='w') mark[i].op=1;
            else if(ch=='b') mark[i].op=0;

            b[cnt].x=l;
            b[cnt].id=i;
            b[cnt++].dir=-1;
            b[cnt].x=r;
            b[cnt].id=i;
            b[cnt++].dir=1;
        }
        //
        sort(b,b+cnt,cmp);

        if(b[0].dir==-1) mark[b[0].id].l=b[0].x;
        else if(b[0].dir==1) mark[b[0].id].r=b[0].x;

        a[1]=b[0].x;
        m=1;

        for(int i=1;i<cnt;i++){

            if(b[i].x!=b[i-1].x){

                m++;
                a[m]
            }
        }

    }
    return 0;
}
