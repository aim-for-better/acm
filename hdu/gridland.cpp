#include <iostream>
#include<cstdio>
#include<cmath>


using namespace std;




double  handle(int r,int c){

    if(r%2&&c%2){

        return r*c-1+sqrt(2);
    }else{
        return r*c;

    }


}
int main()
{

    int t;
    cin>>t;
    int m,n;
    double result=0;
    for(int i=0;i<t;i++){


        cin>>m>>n;

        result=handle(m,n);
        printf("Scenario #%d:\n",i+1);
        printf("%.2lf\n\n",result);

    }
    return 0;

}
