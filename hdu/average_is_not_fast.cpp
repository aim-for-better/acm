#include <iostream>
#include<cstdio>
#
using namespace std;

int main()
{
    int n;
    double dist;

    cin>>n>>dist;


    int t=0;
    char h,m1,m2,s1,s2;
    bool flag=false;
    int total_time=0;
    while(cin>>t){


       printf("%3d: ",t);
        flag=false;
        total_time=0;
        for(int i=0;i<n;i++){

            getchar();  //read from input bufffer
           scanf("%c:%c%c:%c%c",&h,&m1,&m2,&s1,&s2);

            if(h=='-') flag=true;
            if(flag)continue;


            total_time+=(h-'0')*3600+((m1-'0')*10+(m2-'0'))*60+((s1-'0')*10+(s2-'0'));
        }

        if(flag){
            cout<<"-"<<endl;
            continue;
        }else{
            double t1=total_time/dist;

            int t2=(int)(t1+0.5);
            printf("%d:%02d min/km\n",t2/60,t2%60);

        }
    }
    return 0;
}
