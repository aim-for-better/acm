#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

const int maxn=400;
char a[maxn];

int str2int(string s){

    int ans=0;
    int len=s.length();
    for(int i=0;i<len;i++){

        ans=ans*10+(s[i]-'0');

    }
    return ans;
}

bool isOP(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')return true;
    else return false;
}
int level(char ch){

    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 2;
    else return 0;
}
double calcluate(double a,double b,char ch){
    if(ch=='+') return a+b;
    else if(ch=='-') return a-b;
    else if(ch=='*') return a*b;
    else if(ch=='/') return 1.0*a/b;
}
int main()
{
   stack<double> num;
   stack<char> op;

   string tmp;
   int n;
   while(gets(a)){

        if(strcmp(a,"0")==0) break;
        while(!num.empty()) num.pop();
        while(!op.empty()) op.pop();
       int len=strlen(a);
       tmp="";
       n=0;
       double e,f;
      double ans=0;
       for(int i=0;i<len;i++){

         if(a[i]==' '){
            if(tmp!=""){

                n=str2int(tmp)*1.0;
                num.push(n);
                n=0;
                tmp="";

            }
         }else if(isOP(a[i])){

            while(!op.empty()){
                char c=op.top();
                if(level(a[i])>level(c)){
                    break;
                }
                else{
                    op.pop();
                    e=num.top();
                    num.pop();
                    f=num.top();
                    num.pop();

                    num.push(calcluate(f,e,c));
                }

            }
            op.push(a[i]);

         }else{

            tmp+=a[i];
         }
       }
       if(tmp!=""){
            n=str2int(tmp);
            num.push(n);
            n=0;
            tmp="";
       }

       // calculate remain

       while(!op.empty()){
            char c=op.top();
            op.pop();
            e=num.top();
            num.pop();
            f=num.top();
            num.pop();

            num.push(calcluate(f,e,c));
       }
       ans=num.top();
       num.pop();
       printf("%.2lf\n",ans);

   }
   return 0;
}
