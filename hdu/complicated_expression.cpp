#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Expre{

    string exp="";

    int p=0;
};


int priority(char c){

    if(c=='+'||c=='-') return 1;
    else if(c=='*'||c=='/') return 2;
    else if(c=='(') return 3;
}



string middle2Back(string s){

    string t;
    t="";
     char tmp;
    stack<char> op;

    int n=s.length();

    for(int i=0;i<n;i++){

        // if is the num then output
        if(s[i]>='a'&&s[i]<='z'){
                t+=s[i];

        }else if(s[i]=='('){   // if is ( then push stack op

            op.push(s[i]);
        }else if(s[i]==')'){ //  if is ) then output op until meet ( but do not output ( just pop (


            while(!op.empty()){
                tmp=op.top();
                if(tmp=='('){

                    op.pop();
                    break;
                }
                t+=tmp;
                op.pop();
            }
        }
        else {

            // else
            while(!op.empty()){

                tmp=op.top();

                int p1=priority(tmp);

                int p2=priority(s[i]);

                 // if s[i] 's priority greater than top of stack op then push s[i] or s[i] is (

                if(p2>p1||tmp=='(') break;

                // else  output the stack op unitl meet a greater or (
                t+=tmp;
                op.pop();

            }

            op.push(s[i]);
        }
    }

    // add the remain of stack op
    while(!op.empty()){

        t+=op.top();
        op.pop();
    }
    return t;
}

string back2Middle(string t){


    stack<Expre> st;

    string a="";
    string b="";

    string x;
    Expre tmp;

    Expre ta,tb;



    int n=t.length();

    int p1;
    for(int i=0;i<n;i++){



        if(t[i]>='a'&&t[i]<='z'){


            tmp.exp=t[i];

            tmp.p=3;
            st.push(tmp);

        }else if(t[i]=='+'){  //if op is + then just concate

            b=st.top().exp;
            st.pop();
            a=st.top().exp;
            st.pop();

            tmp.exp=a+'+'+b;

            tmp.p=1;
            st.push(tmp);

        }else if(t[i]=='-'){

            tb=st.top();
            st.pop();
            ta=st.top();
            st.pop();
            p1=priority('-');

            // + - is the smallest so, no one lower than p1
            // if the op is - then the second need add () if its priority <=  -
            if(tb.p<=p1){

                b='('+tb.exp+')';
            }else b=tb.exp;

            // no need charge because not less than -
            a=ta.exp;

            tmp.exp=a+'-'+b;

            tmp.p=1;

            st.push(tmp);

        }else if(t[i]=='*'){

            //only the priority less than *  need add ()
            tb=st.top();
            st.pop();
            ta=st.top();
            st.pop();
            p1=priority('*');
            if(tb.p<p1){
                b='('+tb.exp+')';
            }else b=tb.exp;

            if(ta.p<p1){
                a='('+ta.exp+')';
            }else a=ta.exp;

            tmp.exp=a+'*'+b;

            tmp.p=2;

            st.push(tmp);

        }else if(t[i]=='/'){
            tb=st.top();
            st.pop();
            ta=st.top();
            st.pop();
            p1=priority('*');
            // like -   if the op is / then the second less or equal p1 need add ()
            if(tb.p<=p1){
                b='('+tb.exp+')';
            }else b=tb.exp;
            //but the first is less need add (0
            if(ta.p<p1){
                a='('+ta.exp+')';
            }else a=ta.exp;

            tmp.exp=a+'/'+b;
            tmp.p=2;

            st.push(tmp);

        }

    }

    return st.top().exp;
}

int main()
{


    int n;
    scanf("%d",&n);
    string s;
    string t;
    string result;



    while(n--){
        cin>>s;

        t=middle2Back(s);
       result=back2Middle(t);
       cout<<result<<endl;
    }
    return 0;
}
