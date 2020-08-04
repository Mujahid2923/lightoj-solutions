#include<bits/stdc++.h>
using namespace std ;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          output                 freopen("output.txt","wt", stdout)
#define          pf                     printf
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

///--------------------**********----------------------------------

vector < int > v( 100005 ), v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec1, vec2 ;
vector < pll > vec, Vec ;
vector < ll > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;
vector < string > vs ;


///---------------------**********--------------------------------

int n, q, ck, T ;
ll ans = 0 ;

void Reset()
{
    v.clear() ;
    ans = 0 ;
}

void Input()
{
    scanf( "%d", &n ) ;
    scanf( "%d", &q ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scanf( "%d", &v[ i ] ) ;
    }

    ll val = 0 ;
    for( int i = n - 2 ; i >= 0 ; i -- )
    {
        ll x = v[ i ] - v[ i + 1 ] ;
        ll y = ( n - i - 1 ) ;
        ll z = x * y ;
        val += z ;
        ans += val ;
    }
}

void Calculation()
{
    printf( "Case %d:\n", T ) ;
    while( q-- )
    {
        scanf( "%d", &ck ) ;
        if( ck )
        {
             printf( "%lld\n", ans ) ;
        }
        else
        {
            int x, y ;
            scanf( "%d", &x ) ;
            scanf( "%d", &y ) ;

            ll cng = y - v[ x ] ;
            ll left = x ;
            ll right = n - x - 1 ;
            ll val = ( -left * cng ) + ( right * cng ) ;
            ans += val ;
            v[ x ] = y ;
        }
    }
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    scanf( "%d", &t ) ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }
    return 0 ;
}




