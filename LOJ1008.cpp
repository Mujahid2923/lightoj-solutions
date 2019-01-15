#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t,row,col,n;
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        ll n;
        scanf("%lld",&n);
        ll x=ceil(sqrt(n));
        ll y=n-((x-1)*(x-1));
        if(x%2!=0)
        {
            if(x>y)
            {
                row=y;
                col=x;
            }
            else
            {
                row=x;
                col=(((x*x)+1)-n);
            }
        }
        else
        {
            if(x>y)
            {
                row=x;
                col=y;
            }
            else
            {
                row=(((x*x)+1)-n);
                col=x;
            }
        }

        printf("Case %lld: %lld %lld\n",i,col,row);
    }
}
