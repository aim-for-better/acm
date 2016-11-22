//#include<iostream>
#include<stdio.h>
#include<math.h>
//#include<cmath>
//using namespace std;

double factorial(int n){
 if(n==0){
	return 1.0;
}
return n*factorial(n-1);
}

double exponentiation(double x,int n){

	return (double)pow(x,n*1.0);
}
int main(){
int n=0;
while(scanf("%d",&n)!=EOF){
for(int i=0;i<n;i++){
	double x=0;
	//cin>>x;
	scanf("%lf",&x);
	int n=1;
	double result=0;
	while(exponentiation(x,2*n-1)/factorial(2*n-1)>=0.0000001){
		if(n%2==1){
			result+=exponentiation(x,2*n-1)/factorial(2*n-1);
			
		}else{
			
			result-=exponentiation(x,2*n-1)/factorial(2*n-1);
			
		}
		n++;
	}
	//cout<<result<<endl;
	printf("%.6lf\n",result);
}
}
}
