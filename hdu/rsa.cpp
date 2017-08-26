#include <iostream>
#include<cstdio>

using namespace std;

typedef long long   LL;


LL  extentGcd(LL a, LL b,LL &x,LL & y){

    if(b==0){

        x=1;
        y=0;
        return a;
    }
    LL gcd=extentGcd(b,a%b,x,y);

    LL t=x;
    x=y;
    y=t-a/b*y;
    return gcd;

}

LL quickMulti(LL c,LL d,LL mod){

    LL ans=1;
    while(d){

        if(d%2==1)  ans=ans*c%mod;
        c=c*c%mod;
        d/=2;
    }

    return ans;

}



LL p,q,e,l,c,M;
LL n,f,pd;
int main ()
{
	LL x, y, d, a, b ;
	while (scanf ("%I64d%I64d%I64d%I64d", &p, &q, &e, &l) != EOF)
	{
		n = p * q ;
		f = (p-1) * (q-1) ;
		extentGcd(e, f, x, y) ;
		pd = (x % f + f) % f ;
		for (int i = 0; i < l; i ++)
		{
			scanf ("%I64d", &c) ;
			M = quickMulti(c, pd, n) ;
			printf ("%c", char(M)) ;
		}

		printf ("\n") ;
	}
	return 0 ;
}
