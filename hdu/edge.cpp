#include <iostream>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
    string s;


    // flat is direction flag =1,-1, means x+10,x-10
    // flag =2,-2 menas  y+10  y-10
    int flag=1;

    while(cin>>s){

        // flag =2,-2 menas  y+10  y-10
        int flag=1;
        int n=s.length();
        int x=300;
        int y=420;
        printf("%d %d moveto\n",x,y);
        x+=10;

        printf("%d %d lineto\n",x,y);

        for(int i=0;i<n;i++){

            switch(flag){

                case 1:
                    if(s[i]=='V'){

                        y+=10;
                        flag=2;
                    }else if(s[i]=='A'){
                        y-=10;
                        flag=-2;
                    }
                    break;
                case 2:
                    if(s[i]=='V'){

                        x-=10;
                        flag=-1;
                    }else if(s[i]=='A'){
                        x+=10;
                        flag=1;
                    }
                    break;
                case -2:
                    if(s[i]=='V'){

                        x+=10;
                        flag=1;
                    }else if(s[i]=='A'){
                        x-=10;
                        flag=-1;
                    }
                    break;
                case -1:
                    if(s[i]=='V'){

                        y-=10;
                        flag=-2;
                    }else if(s[i]=='A'){
                        y+=10;
                        flag=2;
                    }
                    break;
                default:
                    break;

            }

            printf("%d %d lineto\n",x,y);
        }

        printf("stroke\nshowpage\n");
    }
    return 0;
}
