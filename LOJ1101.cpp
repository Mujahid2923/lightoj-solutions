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

///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < ll > adj[ 50005 ],cost[ 50005 ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

ll n, m, x, y, z, L, ans = 0, q, T ;
ll parent[ 50005 ] ;
ll level[ 50005 ] ;
ll arr[ 50005 ][ 20 ] ;
ll mEdge[ 50005 ][ 20 ] ;

void Reset()
{
    vec.clear() ;
    zero( parent ) ;
    zero( level ) ;
    zero( arr ) ;
    zero( mEdge ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        adj[ i ].clear() ;
        cost[ i ].clear() ;
    }
}

void Input()
{
    cin >> n >> m ;
    L = ceil( log2( n ) ) ;
    for( int i = 0 ; i < m ; i ++ )
    {
        scanf( "%lld %lld %lld", &x, &y, &z ) ;
        vec.pb( { z,{ x, y } } ) ;
    }
    sort( all( vec ) ) ;
}

ll Find( ll r )
{
    if( r == parent[ r ] ) return r ;
    else return parent[ r ] = Find( parent[ r ] ) ;
}

void kruskal()
{
    for( int i = 1 ; i <= n ; i ++ ) parent[ i ] = i ;
    ll cnt = 0 ;
    for( auto x : vec )
    {
        ll a = x.ss.ff, b = x.ss.ss, c = x.ff ;
        ll u1 = Find( a ),u2 = Find( b ) ;
        if( u1 != u2 )
        {
            parent[ u1 ] = u2 ;
            adj[ a ].pb( b ) ;
            adj[ b ].pb( a ) ;
            cost[ a ].pb( c ) ;
            cost[ b ].pb( c ) ;
            cnt ++ ;
            if( cnt == n - 1 ) return ;
        }
    }
}

void dfs( int u, int p )
{
    arr[ u ][ 0 ] = p ;
    level[ u ] = level[ p ] + 1 ;
    for( int i = 1 ; i <= L ; i ++ )
    {
        arr[ u ][ i ] = arr[ arr[ u ][ i - 1 ] ][ i - 1 ] ;
        mEdge[ u ][ i ] = max( mEdge[ u ][ i - 1 ], mEdge[ arr[ u ][ i - 1 ] ][ i - 1 ] ) ;
    }
    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        if( v != p )
        {
            mEdge[ v ][ 0 ] = cost[ u ][ i ] ;
            dfs( v, u ) ;
        }
    }
}

int up( int x, int step )
{
    for( int i = 0 ; i <= L ; i ++ )
    {
        if( step & ( 1 << i ) )
        {
            ans = max( ans , mEdge[ x ][ i ] ) ;
            x = arr[ x ][ i ] ;
        }
    }
    return x ;
}

void lca( int p, int q )
{
    if( level[ p ] < level[ q ] ) swap( p, q ) ;
    p = up( p, level[ p ] - level[ q ] ) ;

    if( p == q ) return ;

    for( int i = L ; i >= 0 ; i -- )
    {
        if( arr[ p ][ i ] != arr[ q ][ i ] )
        {
            ans = max( { ans , mEdge[ p ][ i ], mEdge[ q ][ i ] } ) ;
            p = arr[ p ][ i ], q = arr[ q ][ i ] ;

        }
    }

    ans = max( { ans , mEdge[ p ][ 0 ], mEdge[ q ][ 0 ] } ) ;
    return ;
}


void Calculation()
{
    printf( "Case %lld:\n", T ) ;
    kruskal() ;
    dfs( 1, 0 ) ;
    cin >> q ;
    while( q-- )
    {
        ans = 0 ;
        scanf( "%lld %lld", &x, &y ) ;
        lca( x, y ) ;
        printf( "%lld\n", ans ) ;
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
    //t = 1 ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }
    return 0 ;
}
