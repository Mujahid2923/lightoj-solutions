#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[10002];
ll a, b, c, d, e, f;

ll fn( ll n )
{
    for(ll i=0; i<=n; i++)
    {
        if( i == 0 )
        {
            arr[i]=a;
            continue;
        }

        if( i == 1 )
        {
            arr[i]=b;
            continue;
        }
        if( i == 2 )
        {
            arr[i]=c;
            continue;
        }
        if( i == 3 )
        {
            arr[i]=d;
            continue;
        }
        if( i == 4 )
        {
            arr[i]=e;
            continue;
        }
        if( i == 5 )
        {
            arr[i]=f;
            continue;
        }
        else
        {
            arr[i]=arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6];
            arr[i]=arr[i]%10000007;
        }
    }

    return arr[n];
}

int main()
{
    ll n, caseno = 0, t;
    scanf("%lld", &t);

    while( t-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        ll z=fn(n)%10000007;
        printf("Case %lld: %lld\n", ++caseno, z);
    }
    return 0;
}
