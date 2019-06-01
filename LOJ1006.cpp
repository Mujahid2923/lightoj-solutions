///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)


///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

#define        mod          10000007

ll arr[10002];
ll a, b, c, d, e, f;

ll fn( ll n )
{
    if( n == 0 )
        return a ;
    if( n == 1 )
        return b ;
    if( n == 2 )
        return c ;
    if( n == 3 )
        return d ;
    if( n == 4 )
        return e ;
    if( n == 5 )
        return f ;

    if( arr[ n ] != - 1 )
        return arr[ n ] % mod ;
    else
        return arr[ n ] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % mod ;
}

int main()
{
    ll n, caseno = 0, t;
    cin >> t ;

    for( int i = 1 ; i <= t ; i ++ )
    {
        memset( arr , -1 , sizeof arr ) ;
        cin >> a >> b >> c >> d >> e >> f >> n ;
        ll z = fn(n) % mod;
        printf("Case %d: %lld\n", i, z ) ;
    }
    return 0;
}

------------------------------------Iterative-------------------------------------------

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
