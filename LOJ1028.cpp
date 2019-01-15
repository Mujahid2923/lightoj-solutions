#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll>v;
bool prime[1000005];

void findPrime()
{
    ll n=1000000;
    memset(prime,false,sizeof prime);

    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }

    prime[1]=true;

    for(ll i=3; i*i<=n; i+=2)
    {
        if(prime[i]==false)
        {
            for(ll j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(ll i=1; i<=n; i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}

ll div(ll n)
{
    ll sum=1;
    for(int i=0; v[i]*v[i]<=n; i++)
    {
        ll k=0;
        while(n%v[i]==0)
        {
            n=n/v[i];
            k++;
        }
        sum=sum*(k+1);
    }
    if(n>1)
    {
        sum=sum*2;
    }
    return sum-1;
}

int main()
{
    //freopen("in.txt","w",stdout);
    findPrime();
    ll t,n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        ll ans=div(n);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
