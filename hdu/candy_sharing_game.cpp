#include <iostream>
#include<cstdio>
using namespace std;



int arr[1005];
int n;
bool isEqual(){

    for(int i=1;i<n;i++){

        if(arr[i]!=arr[i-1]){

            return false;

        }
    }
    return true;
}

int  handle(){



    int num=0;



    while(!isEqual()){


        int pre=0;// tmp candy
        int now=0;
        for(int i=0;i<n;i++){

            if(i==0){

                pre=arr[i];

                arr[i]=arr[n-1]/2+arr[i]/2;

            }else{


                now=arr[i];

                arr[i]=pre/2+arr[i]/2;
                pre=now;
            }

             if(arr[i]%2==1){

                arr[i]+=1;
            }
        }

        num+=1;
        //cout<<"the num is:"<<num<<endl;

    }


    return num;
}



int main()
{
    int tmp;


    int num,candy;


    while(cin>>n&&n!=0){
        num=0;

        for(int i=0;i<n;i++){

            cin>>arr[i];
        }


        num=handle();

        printf("%d %d\n",num,arr[0]);
    }
    return 0;
}
