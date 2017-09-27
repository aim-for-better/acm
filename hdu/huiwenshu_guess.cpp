#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;


string int2str(int n){

    string ans;

    while(n!=0){

        ans=char('0'+n%10)+ans;
        n/=10;
    }
    return ans;
}

int reverseInt(int n){

    string s=int2str(n);

    int ans=0;
    int len=s.length();
    for(int i=len-1;i>=0;i--){

        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
bool charge(int n){

    string s=int2str(n);
    int len=s.length();
    int i,j;
    for(i=0,j=len-1;i<=j;i++,j--){

        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    vector<int> ans;
    int org;
    while(scanf("%d",&n)!=EOF){

        ans.clear();
        org=n;
        while(!charge(n)){

            n+=reverseInt(n);
            ans.push_back(n);
        }

        int len=ans.size();
        printf("%d\n%d",len,org);


        for(int i=0;i<len;i++){
            printf("--->%d",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
