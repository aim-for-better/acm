#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;


struct Node{

    map<string,int> fruit;

};
int main()
{
    map<string,map<string,int> > m;

    int  T;
    scanf("%d",&T);
    int n;
    string from;
    string name;
    int num;
    while(T--){
        m.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            cin>>name>>from>>num;

            m[from][name]+=num;
        }

        for(map<string,map<string,int> >::iterator it=m.begin();it!=m.end();it++){

            cout<<it->first<<endl;
            for(map<string,int>::iterator itt=it->second.begin();itt!=it->second.end();itt++){
                cout<<"   |----";
                cout<<itt->first<<"("<<itt->second<<")"<<endl;
            }
        }
        if(T>0) printf("\n");
    }


    return 0;
}
