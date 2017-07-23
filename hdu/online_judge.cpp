#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>

using namespace std;

#define MAX 5005

char ip[MAX]; // input
char op[MAX]; // output
char i[MAX];
char o[MAX];
char temp[MAX];

void input(char a[] ,char b[]){

    gets(temp);

    while(strcmp(temp,"START")!=0) gets(temp);

    while(gets(temp)){

        if(strcmp(temp,"END")==0) break;

        if(strlen(temp)!=0) strcat(a,temp);

        strcat(a,"\n");
    }

    int t=0;
    int len=strlen(a);

    for(int i=0;i<len;i++){

        if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n'){

            b[t++]=a[i];
        }
    }
    b[t]='\0';

}

int main()
{
    int t;

    scanf("%d",&t);
    getchar();
    string tmp;
    string is;
    string os;
    while(t--){

       ip[0]='\0';
       op[0]='\0';

       input(ip,i);
       input(op,o);

       if(strcmp(ip,op)==0)printf("Accepted\n");
       else if(strcmp(i,o)==0){
            printf("Presentation Error\n");

       }else{
            printf("Wrong Answer\n");
       }

    }
    return 0;
}
