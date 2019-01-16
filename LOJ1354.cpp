#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll toDecimal(ll num)
{
    ll temp=num;
    ll dec=0;
    ll b=1;
    while(num>0)
    {
        ll rem=num%10;
        dec=dec+rem*b;
        b=b*2;
        num=num/10;
    }
    return dec;
}

int main()
{
    ll t,d1,d2,d3,d4;
    char p1,p2,p3,p4,p5,p6,p7,p8;
    ll b1,b2,b3,b4;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>d1>>p1>>d2>>p2>>d3>>p3>>d4;
        cin>>b1>>p5>>b2>>p6>>b3>>p7>>b4;
        ll r1=toDecimal(b1);
        ll r2=toDecimal(b2);
        ll r3=toDecimal(b3);
        ll r4=toDecimal(b4);
        if(d1==r1 && d2==r2 && d3==r3 && d4==r4)
        {
            printf("Case %lld: Yes\n",i);
        }
        else
        {
            printf("Case %lld: No\n",i);
        }
    }
    return 0;
}

