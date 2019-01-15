#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(-1)

ll factorial(ll n,ll b)
{
    if(n<=1)
        return 1;
    double digit=((n+0.5)*log(n) - n + 0.5*log(2*pi))/log(b);
    return floor(digit)+1;
}

int main()
{
    ll n,b,t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&b);
        ll ans=factorial(n,b);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
