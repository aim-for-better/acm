#include <iostream>

#include<cmath>
using namespace std;

int n,m;


int level(int x){

    int i=(int)sqrt(x);

    return i*i==x?i:i+1;
}


// calculate the vertical desired n for m in levle n
int  desire(int m,int i,int j){


    int incr=(j-i)*(i+j-1);

    return m+incr;
}




int dist(int m,int n,int step){



    if(m>n){

        int t=m;
        m=n;
        n=t;
    }

    int  lm=level(m);

    int ln=level(n);



    for(int i=lm;i<ln;i++){


        if(i%2==0){

            if(m%2==0){

                    m+=2*i;
                    step++;
            }else{


                // judge left or right
                if(n>desire(m,i,ln)){

                      m+=1;
                    m+=2*i;
                    step+=2;
                }else{

                    m-=1;
                    m+=2*i;
                    step+=2;
                }

            }

        }else{
        //
            if(m%2==1){
                 m+=2*i;
                 step++;

            }else{

                // judge left or right
                if(n>desire(m,i,ln)){

                      m+=1;
                    m+=2*i;
                    step+=2;
                }else{

                    m-=1;
                    m+=2*i;
                    step+=2;
                }
            }
        }


    }

    step+=(n-m)>0?(n-m):(m-n);
    return step;

}



int main()
{

    int result=0;
    while(cin>>m>>n){


        cout<<dist(m,n,0)<<endl;

    }



    return 0;
}
