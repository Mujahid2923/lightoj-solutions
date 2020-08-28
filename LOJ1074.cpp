#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          output                 freopen("output.txt","wt", stdout)
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
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
#define          siz                    205
///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < pll, ll > > vec ;
vector < ll > adj[ siz ], cost[ siz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

ll n, m, q, x, y, test ;
ll dist[ siz ], val[ siz ], visited[ siz ] ;
void Reset()
{
    zero( visited ) ;
    for( int i = 1 ; i <= n ; i ++ ) adj[ i ].clear(), cost[ i ].clear() ;
}

void Input()
{
    scanf( "%lld", &n ) ;
    for( int i = 1 ; i <= n ; i ++ ) scanf( "%lld", &val[ i ] ) ;

    scanf( "%lld", &m ) ;
    for( int i = 0 ; i < m ; i ++ )
    {
        scanf( "%lld %lld", &x, &y ) ;
        adj[ x ].pb( y ) ;
        ll z = val[ y ] - val[ x ] ;
        cost[ x ].pb( z * z * z ) ;
    }
}

void Bellmanford( int s )
{
    for( int i = 1 ; i <= n ; i ++ ) dist[ i ] = INT_MAX ;
    dist[ s ] = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++  )
        {
            ll u = j ;
            for( int k = 0 ; k < adj[ u ].size() ; k ++ )
            {
                ll v = adj[ u ][ k ] ;
                ll w = cost[ u ][ k ] ;
                if( dist[ u ] + w < dist[ v ] ) dist[ v ] = dist[ u ] + w ;
            }
        }
    }
}

void dfs( int u )
{
    visited[ u ] = 1 ;
    for( auto v : adj[ u ] ) if( !visited[ v ] ) dfs( v ) ;
}

void Calculation()
{
    pf( "Case %lld:\n", ++ test ) ;
    dfs( 1 ) ;
    Bellmanford( 1 ) ;
    scanf( "%lld", &q ) ;
    while( q-- )
    {
        scanf( "%lld", &x ) ;
        if( dist[ x ] < 3 || dist[ x ] == INT_MAX || !visited[ x ] ) pf( "?\n" ) ;
        else pf( "%lld\n", dist[ x ] ) ;
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
    cin >> t ;
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}
