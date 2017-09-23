#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;


int str2int(string s){

    int ans=0;
    int len=s.length();
    for(int i=0;i<len;i++){

        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);

    stack<string> ss;// stack string
    stack<char> sn;// stack number
    string ts; // temp string
    string tn;// temp number
    string s;
    int len;
    string tmp;
    int tmpn;
    if(T<=0) return 0;
    while(T--){
        while(!ss.empty()) ss.pop();
        while(!sn.empty()) sn.pop();
        ts="";
        tn="";
        cin>>s;
        len=s.length();
        tmp="";
        for(int i=0;i<len;i++){

            if(s[i]>='0'&&s[i]<='9'){
               sn.push(s[i]);
            }else if(s[i]=='('){
                sn.push(s[i]);
                ts=s[i];
                ss.push(ts);
                ts="";
            }else if(s[i]>='a'&&s[i]<='z'){
                if(sn.empty()||sn.top()=='('){
                    ts=s[i];
                    ss.push(ts);
                    ts="";
                }
                else{
                    tn="";
                    while(!sn.empty()&&sn.top()!='('){
                        tn=sn.top()+tn;
                        sn.pop();
                    }
                    tmpn=str2int(tn);
                    ts=s[i];
                    tmp="";
                    for(int j=0;j<tmpn;j++){
                        tmp=tmp+ts;
                    }
                    ss.push(tmp);
                    //reset;
                    ts="";
                    tmp="";

                }

            }else if(s[i]==')'){
                tn="";
                if(sn.top()=='(') sn.pop();
                while(!sn.empty()&&sn.top()!='('){

                      tn=sn.top()+tn;
                      sn.pop();
                }
                tmpn=str2int(tn);
                tn="";
                ts="";
                while(!ss.empty()&&ss.top()!="("){
                    ts=ss.top()+ts;
                    ss.pop();
                }
                tmp=ts;
                for(int k=1;k<tmpn;k++){
                    tmp+=ts;
                }

                if(ss.top()=="(") ss.pop();
                ss.push(tmp);

                ts="";
            }
        }
        tmp="";
        while(!ss.empty()&&ss.top()!="("){

            tmp=ss.top()+tmp;
            ss.pop();
        }
        cout<<tmp<<endl;
    }
    return 0;
}
