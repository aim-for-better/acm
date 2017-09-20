#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;


bool isPrime(int n){

    if(n==2||n==3||n==5||n==7) return true;

    if(n%2==0||n%3==0||n%5==0||n%7==0) return false;

    int len=sqrt(n);
    for(int i=2;i<=len;i++){

        if(n%i==0) return false;
    }

    return true;

}
int main()
{
    int n=10000;
    int cnt=0;
    int m;
    int a,b;
    // n is even ,
    while(scanf("%d",&n)!=EOF){

        int m=n/2;
        if(isPrime(m)){

            printf("%d %d\n",m,m);
            continue;
        }

        a=m;
        b=m;
        while(true){


            if(isPrime(a)&&isPrime(b)){
                printf("%d %d\n",a,b);
                break;
            }
            if(a%2==0)a=a-1;
            else a=a-2;
            if(b%2==0) b=b+1;
            else b=b+2;
        }
    }
}
