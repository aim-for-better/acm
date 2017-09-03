#include <iostream>
#include<cstdio>
#include<string>'
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=105;

string a[maxn];

bool cmp(string a,string b){
    return a.length()<b.length();
}

bool charge(string s,int n){


    string tmp=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){

        if(a[i].find(s)==-1&&a[i].find(tmp)==-1){

            return false;
        }
    }
    return true;
}
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    vector<string> substrs;
    string sstr;//shortest str
    string tmp;
    while(T--){

        scanf("%d",&n);
        tmp="";
        for(int i=0;i<n;i++){

            cin>>a[i];
        }
        sort(a,a+n,cmp);

        sstr=a[0];
        int len=sstr.length();

        for(int i=0;i<len;i++){

            for(int j=i+1;j<=len;j++){

                tmp=sstr.substr(i,j-i);
                substrs.push_back(tmp);
            }
        }
        sort(substrs.begin(),substrs.end(),cmp);
        int ans=0;
        for(int i=substrs.size()-1;i>=0;i--){

            if(charge(substrs[i],n)){

                ans=substrs[i].length();
                break;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
