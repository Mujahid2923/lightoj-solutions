#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
bool a[60005];
vector<ll>v;
void seive()
{
    ll n=60000;
    memset(a,false,sizeof a);
    for(ll i=4; i<=n; i=i+2)
    {
        a[i]=true;
    }
    for(ll i=3; i<=sqrt(n); i++)
    {
        if(a[i]==0)
        {
            for(ll j=i*i; j<=n; j+=i*2)
            {
                a[j]=true;
            }
        }
    }
    v.push_back(2);
    for(ll i=3; i<=n; i=i+2)
    {
        if(a[i]==false)
        {
            v.push_back(i);
        }
    }
}

ll power(ll N, ll P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ll divisor=power(N,P/2);
        return ((divisor%MOD)*(divisor%MOD))%MOD;
    }
    else
    {
        return ((N%MOD)*power(N,P-1)%MOD)%MOD;
    }
}

ll Find(ll n, ll m)
{
    ll i, l=0, divisor=1;
    for(i=0; v[i]<=sqrt(n); i++)
    {
        l=0;
        if(n%v[i]==0)
        {
            while(n%v[i]==0)
            {
                n=n/v[i];
                l++;
            }
        l=(l*m)+1;
        divisor=(divisor*(power(v[i],l)-1))%MOD;
        divisor=(divisor*(power(v[i]-1,MOD-2)))%MOD;
        }
    }
    if(n>1)
    {
        divisor=(divisor*(power(n,m+1)-1))%MOD;
        divisor=(divisor*(power(n-1,MOD-2)))%MOD;
    }
    return divisor;
}

int main()
{
    ll t, n, m, i, ans;
    seive();
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        if(n%MOD==0)
        {
            ans=1;
        }
        else
        {
            ans=Find(n,m);
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}

///same solution:
///https://paste.ubuntu.com/p/dgFwJkGrV8/
