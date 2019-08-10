///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          db                     double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Upper(c,x)           (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

vector< ll > v ;
const int MAXN = 6e4 ;
bitset< MAXN > status ;

void findPrime()
{
    int rt = sqrt( MAXN ) + 1 ;

    for( int i = 3 ; i < rt ; i += 2 )
    {
        if( !status[ i ] )
        {
            for( int j = i * i ; j < MAXN ; j += ( i << 1 ) )
            {
                status[j] = true;
            }
        }
    }

    v.push_back( 2 ) ;

    for( int i = 3; i < MAXN; i += 2 )
    {
        if( !status[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

set < ll > st ;
map < ll, ll > Mp ;

ll primeFactorization( ll n, ll m )
{
    for( int i = 0 ; v[ i ] * v[ i ] <= n ; i ++ )
    {
        ll cnt = 0 ;
        while( n % v[ i ] == 0 )
        {
            cnt ++ ;
            n = n / v[ i ] ;
        }
        if( cnt > 0 )
        {
            st.insert( v[ i ] ) ;
            Mp[ v[ i ] ] = cnt * m ;
        }
    }

    if( n > 1 )
    {
        st.insert( n ) ;
        Mp[ n ] = 1 * m ;
    }
}


ll power(ll x,ll y,ll m)
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x, y/2, m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x, y-1, m ) % m ) ) % m ;
}



int main()
{
    CIN ;
    findPrime();
    ll t, n, m ;
    cin >> t ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n >> m ;
        primeFactorization( n , m ) ;
        ll ans = 1 ;
        for( auto x : st )
        {
            ll p =  power( x , Mp[ x ] + 1 , MOD ) - 1 ;
            ll q =  power( x - 1 , MOD - 2 , MOD ) ;
            ans = ( ( ans % MOD ) * ( ( ( p % MOD ) * ( q % MOD ) ) % MOD ) ) % MOD ;
        }
        if( ans < 0 )
        {
            ans += MOD ;
        }
        pf("Case %d: %lld\n" , k , ans % MOD ) ;
        st.clear() ;
        Mp.clear() ;
    }

    return 0;
}



-------------------------*****************---------------------------------------------


#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

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

vector<ll>v;
const int MAXN = 60000;

bitset<MAXN> status;


void sieve()
{
    int n = 6*1e4;
    int sq=sqrt(n);

    for(int i = 3; i <= sq; i+=2)
    {
        if(!status[i])
        {
            for(int j = i*i; j <= n; j+=(i<<1))
            {
                status[j] = true;
            }
        }
    }

    v.push_back(2);

    for(int i = 3; i <= n; i+=2)
    {
        if(!status[i])
        {
            v.push_back(i);
        }
    }
}


ll power(ll N, ll P)
{
    if(P==0)
        return 1;
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
    //output;
    sieve();
    ll i,t,a,b;
    ll ans;
    scln(t);
    RUN_CASE(i,t)
    {
        scln2(a,b);
        if(a%MOD==0)
        {
            ans=1;
        }
        else
        {
            ans=Find(a,b);
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}

///same solution:
///https://paste.ubuntu.com/p/dgFwJkGrV8/
