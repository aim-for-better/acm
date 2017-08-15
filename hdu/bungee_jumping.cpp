#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double g=9.81;
double k,l,s,w;
double v;
int main()
{

    //case1   if l>=s  fall freely
    while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w)){

        if(k==0&&l==0&&s==0&&w==0)break;

        if(l>=s)
            v=sqrt(2*g*s);
        else{

            //calculate the l1 if l1<s then hang

            double l1=sqrt(2.0*w*g*s/k);
            if(l1+l<s){
                printf("Stuck in the air.\n");
                continue;
            }else{
                v=sqrt((w*g*s-1.0/2.0*k*(s-l)*(s-l))*2/w);
            }

        }
        if(v>10){

            printf("Killed by the impact.\n");
        }else{
            printf("James Bond survives.\n");
        }
    }

    return 0;
}
