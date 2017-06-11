#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;


int arr[13];
int result[5];
bool visited[13];
int t;
int n;


//回溯(back)就是把一个变量搜索后，重置成未搜索。
// dsf +back
bool isEqual(){

    int v=result[0];
    int w=result[1];
    int x=result[2];
    int y=result[3];
    int z=result[4];

    return (v-w*w+x*x*x-y*y*y*y+z*z*z*z*z)==t;

}

bool dfs(int time){


    if(time==5){

        return isEqual();
    }

    for(int i=n-1;i>=0;i--){


        if(!visited[i]){

            visited[i]=true;
            result[time]=arr[i];
            if(dfs(time+1)){

                return true;;
            }
            visited[i]=false;
        }

    }

    return false;
}
int main()
{

//v - w^2 + x^3 - y^4 + z^5 = target
    string s;
    bool flag;
    int v,w,x,y,z;

    while(cin>>t>>s){

        if(t==0&&s=="END"){
            break;
        }
        flag=false;
        memset(arr,0,sizeof(arr));
        memset(result,0,sizeof(result));
        memset(visited,false,sizeof(visited));
        int tmin=0;
        int tmax=0;
        n=s.size();

        for(int i=0;i<n;i++){

            arr[i]=(int)(s[i]-64);
            //cout<<arr[i]<<endl;
        }
        sort(arr,arr+n);

        flag=dfs(0);
        if(flag){

            for(int i=0;i<5;i++){
                cout<<(char)(result[i]+64);

            }
            cout<<endl;
        }else{
            cout<<"no solution"<<endl;
        }
    }
    return 0;
}

