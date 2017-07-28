#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>

using namespace std;


#define MAX 100
string str;

int main()
{

    int cnt=0;
    int len=0;
    int lnt=0;// line count the flag to decide whether output space or not
    while(cin>>str){


        // space tab \n will be continue
        if(strcmp(str.c_str(),"")==0)continue;


        len=str.length();

        if(strcmp(str.c_str(),"<br>")==0){
            cout<<endl;
            cnt=0;

        }else if(strcmp(str.c_str(),"<hr>")==0){

            if(cnt!=0){cout<<endl;}
            for(int i=0;i<80;i++){
                cout<<"-";
            }
            cout<<endl;
            cnt=0;

        }else{

            if(cnt+len+1<=80){

                if(cnt!=0){
                    cout<<" ";
                    cnt++;
                }

                cout<<str;
                cnt+=len;

            }else{
                cout<<endl;

                cout<<str;
                cnt=len;
            }
        }

    }
    cout<<endl;
    return 0;
}
