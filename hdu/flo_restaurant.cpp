#include <iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define MAX 5000

int tm[MAX];
int p[MAX];

struct Node{

    int arrive;
    int person;

};

int a,b,c;

int two[100];
int four[100];
int six[100];
queue<Node> qa;
queue<Node> qb;
queue<Node> qc;

int handleA(){

    int n=qa.size();
    memset(two,0,sizeof(two));

    int mm=1000000;
    int total=0;
    int cnt=0;
    Node tmp;
    while(!qa.empty()){

         tmp=qa.front();
         qa.pop();
        mm=1000000;
        int index=-1;
        for(int i=0;i<a;i++){

            if(two[i]<mm){
                mm=two[i];
                index=i;
            }
        }
        if(mm==0){
            two[index]=tmp.arrive;
            total+=tmp.person;
        }else if(mm<=tmp.arrive&&mm<=22*60){
           if(mm+30<tmp.arrive)
                six[index]=tmp.arrive;
            else
                six[index]=mm+30;
            total+=tmp.person;
        }
    }
    return total;

}
int handleB(){

    int n=qb.size();
    memset(four,0,sizeof(four));

    int mm=1000000;
    int total=0;
    int cnt=0;
    Node tmp;
    while(!qb.empty()){


         tmp=qb.front();
         qb.pop();
        mm=1000000;
        int index=-1;
        for(int i=0;i<b;i++){

            if(four[i]<mm){
                mm=four[i];
                index=i;
            }
        }
        if(mm==0){
            four[index]=tmp.arrive;
            total+=tmp.person;
        }else if(mm<=tmp.arrive&&mm<=22*60){
           if(mm+30<tmp.arrive)
                six[index]=tmp.arrive;
            else
                six[index]=mm+30;
            total+=tmp.person;
        }
    }
    return total;
}

int handleC(){

    int n=qc.size();
    memset(six,0,sizeof(six));

    int mm=1000000;
    int total=0;
    int cnt=0;
    Node tmp;
    while(!qc.empty()){


         tmp=qc.front();
         qc.pop();
        mm=1000000;
        int index=-1;
        for(int i=0;i<c;i++){

            if(six[i]<mm){
                mm=six[i];
                index=i;
            }
        }
        if(mm==0){
            six[index]=tmp.arrive;
            total+=tmp.person;
        }else if(mm<=tmp.arrive&&mm<=22*60){
            if(mm+30<tmp.arrive)
                six[index]=tmp.arrive;
            else
                six[index]=mm+30;

            total+=tmp.person;
        }

    }
    return total;

}



int main()
{


    while(cin>>a>>b>>c){
        while(!qa.empty())qa.pop();
        while(!qb.empty())qb.pop();
        while(!qc.empty())qc.pop();
        if(a==0&&b==0&&c==0) break;

        char h1,h2;
        int m;
        int n;
        getchar();
        int i=0;
        while(true){
            scanf("%c",&h1);

            if(h1=='#'){
                getchar();
                break;
            }
            scanf("%c:%d%d",&h2,&m,&n);

            getchar();
           // printf("%c %c %d %d\n",h1,h2,m,n);

           int h=(int)(h1-'0')*10+(int)(h2-'0');

           int t=h*60+m;

           tm[i]=t;
           p[i]=n;
           i++;
           Node tmp;
           tmp.arrive=t;
           tmp.person=n;

           if(n<=2)qa.push(tmp);
           else if(n>2&&n<=4) qb.push(tmp);
           else if(n>4&&n<=6) qc.push(tmp);

        }
        // total i
        int total=handleA()+handleB()+handleC();
       cout<<total<<endl;



    }



    return 0;
}
